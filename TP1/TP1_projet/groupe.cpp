#include "groupe.h"

Groupe::Groupe(): nom_("Aucun"), totalDepenses_(0.0), nombreDepenses_(0), nombreUtilisateurs_(0), tailleTabUtilisateurs_(5), tailleTabDepenses_(10), comptes_(nullptr), listeTransferts_(nullptr), nombreTrensferts_(0)
{
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
}

Groupe::Groupe(string & nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) : nom_(nom), totalDepenses_(0.0), nombreDepenses_(0), nombreUtilisateurs_(0), tailleTabUtilisateurs_(tailleTabUtilisateurs), tailleTabDepenses_(tailleTabDepenses), comptes_(nullptr), listeTransferts_(nullptr), nombreTrensferts_(0)
{
	listeDepenses_ = new Depense*[tailleTabDepenses];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs];
}

Groupe::~Groupe()
{
	delete[] listeUtilisateurs_;
	delete[] listeDepenses_;

	for (unsigned i = 0; i < nombreTrensferts_; i++)
		delete listeTransferts_[i];
	delete[] listeTransferts_;
}

string Groupe::getNom() const
{
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const
{
	return nombreDepenses_;
}

double Groupe::getTotal() const
{
	return totalDepenses_;
}

void Groupe::setNom(string & nom)
{
	nom_ = nom;
}

void Groupe::ajouterDepense(Depense * uneDepense, Utilisateur * payePar)
{
	if (nombreDepenses_ == 0)
		listeDepenses_ = new Depense*[++tailleTabDepenses_];
	else if (nombreDepenses_ >= tailleTabDepenses_)
	{
		Depense ** listeDepensesTemporaire = listeDepenses_;
		listeDepenses_ = new Depense*[tailleTabDepenses_ * 2];
		for (unsigned i = 0; i < tailleTabDepenses_; i++)
		{
			listeDepenses_[i] = listeDepensesTemporaire[i];
		}
		delete[] listeDepensesTemporaire;
		tailleTabDepenses_ *= 2;
	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
	payePar->ajouterDepense(uneDepense);
}

void Groupe::ajouterUtilisateur(Utilisateur * unUtilisateur)
{
	
	if (tailleTabUtilisateurs_ == 0)
	{
		listeUtilisateurs_ = new Utilisateur*[++tailleTabUtilisateurs_];
		comptes_ = new double[tailleTabUtilisateurs_];
	}
	else if (nombreUtilisateurs_ >= tailleTabUtilisateurs_)
	{
		Utilisateur** listeUtilisateursTemporaire = listeUtilisateurs_;
		listeUtilisateurs_ = new Utilisateur* [tailleTabUtilisateurs_ * 2];

		double* comptesTemporaire = comptes_;
		comptes_ = new double[tailleTabUtilisateurs_ * 2];
		for (unsigned i = 0; i < tailleTabUtilisateurs_; i++)
		{
			listeUtilisateurs_[i] = listeUtilisateursTemporaire[i];
			comptes_[i] = comptesTemporaire[i];
		}
		delete[] listeUtilisateursTemporaire;
		delete[] comptesTemporaire;
		tailleTabUtilisateurs_ *= 2;
	}
	listeUtilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}

void Groupe::calculerTotalDepenses()
{
	totalDepenses_ = 0;
	for (unsigned i = 0; i < nombreDepenses_; i++)
		totalDepenses_ += listeDepenses_[i]->getMontant();

	double moyenne = totalDepenses_ / double(nombreUtilisateurs_);
	for (unsigned i = 0; i < nombreUtilisateurs_; i++)
	{
		listeUtilisateurs_[i]->calculerTotal();
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - moyenne;
	}

}

void Groupe::equilibrerComptes()
{
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	
	bool equilibrageEnCours = true;
	while (equilibrageEnCours == true)
	{
		equilibrageEnCours = false;

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			if (comptes_[i] != 0.0)
			{
				for (unsigned int j = 0; j < nombreUtilisateurs_; j++)
				{
					if (i != j)
					{
						if ((comptes_[i] != 0.0) && (comptes_[j] != 0.0))
						{
							if ((comptes_[i] + comptes_[j]) == 0.0)
							{
								equilibrageEnCours = true;
								if (comptes_[i] > 0.0)
									listeTransferts_[nombreTrensferts_++] = new Transfert(comptes_[i], listeUtilisateurs_[j], listeUtilisateurs_[i]);
								else
									listeTransferts_[nombreTrensferts_++] = new Transfert(comptes_[j], listeUtilisateurs_[i], listeUtilisateurs_[j]);
								comptes_[i] = 0.0;
								comptes_[j] = 0.0;

							}
						}
					}
				}
			}
		}

		if (equilibrageEnCours == false)
		{
			for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
			{
				if ((comptes_[i] != 0.0) && (equilibrageEnCours == false))
				{
					for (unsigned int j = 0; j < nombreUtilisateurs_; j++)
					{
						if ((i != j) && (equilibrageEnCours == false))
						{
							if ((comptes_[i] > 0.0) && (comptes_[j] < 0))
							{
								equilibrageEnCours = true;
								if (abs(comptes_[i]) < abs(comptes_[j]))
								{
									listeTransferts_[nombreTrensferts_++] = new Transfert(comptes_[i], listeUtilisateurs_[j], listeUtilisateurs_[i]);
									comptes_[j] += comptes_[i];
									comptes_[i] = 0.0;
								}
								else if (abs(comptes_[i]) > abs(comptes_[j]))
								{
									listeTransferts_[nombreTrensferts_++] = new Transfert(abs(comptes_[j]), listeUtilisateurs_[j], listeUtilisateurs_[i]);
									comptes_[i] += comptes_[j];
									comptes_[j] = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Groupe::afficherGroupe() const
{
	cout << "\n\n *****************************************\n\nL'evenement: " << nom_ << '\n'
		<< "A coute un total de: " << totalDepenses_ << " $\n"
		<< "\nVoici les depenses:\n";

	for (unsigned i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();

	bool afficherComptes = false;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		if (comptes_[i] != 0.0)
			afficherComptes = true;
	}
	
	if (afficherComptes == true)
	{
		cout << "Voici les comptes:";
		for (unsigned i = 0; i < nombreUtilisateurs_; i++)
		{
			cout << "\n" << listeUtilisateurs_[i]->getNom();
			cout << ": " << comptes_[i] << " $";
		}
	}
	else
	{
		cout << "Pour equilibrer:";
		for (unsigned i = 0; i < nombreTrensferts_; i++)
		{
			cout << "\n" << "Transfert fait par : ";
			listeTransferts_[i]->afficherTransfert();
		}
	}
}

