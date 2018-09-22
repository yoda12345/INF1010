/*
groupe.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier source de la classe Groupe

*/
#include "groupe.h"

//Constructeurs

Groupe::Groupe(): nom_("Inconnu"), totalDepenses_(0.0), nombreDepenses_(0),
				  nombreUtilisateurs_(0), tailleTabUtilisateurs_(5),
				  tailleTabDepenses_(10), comptes_(nullptr), 
				  listeTransferts_(nullptr), nombreTrensferts_(0)
{
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	comptes_ = new double[tailleTabUtilisateurs_];
}

Groupe::Groupe(const string& nom, unsigned int tailleTabDepenses, 
			   unsigned int tailleTabUtilisateurs): nom_(nom),
			   totalDepenses_(0.0), nombreDepenses_(0), nombreUtilisateurs_(0),
			   tailleTabUtilisateurs_(tailleTabUtilisateurs), 
			   tailleTabDepenses_(tailleTabDepenses), comptes_(nullptr),
			   listeTransferts_(nullptr), nombreTrensferts_(0)
{
	listeDepenses_ = new Depense*[tailleTabDepenses];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs];
	comptes_ = new double[tailleTabUtilisateurs];
}

//Destructeurs

Groupe::~Groupe()
{
	delete[] listeUtilisateurs_;
	delete[] listeDepenses_;

	for (unsigned i = 0; i < nombreTrensferts_; i++)
		delete listeTransferts_[i];
	delete[] listeTransferts_;

	listeUtilisateurs_ = nullptr;
	listeDepenses_ = nullptr;
	listeTransferts_ = nullptr;

	nombreDepenses_ = 0;
	nombreTrensferts_ = 0;
	nombreUtilisateurs_ = 0;
}

//Methodes d'acces

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

//Methode de modification

void Groupe::setNom(const string& nom)
{
	nom_ = nom;
}

//Methode d'ajout de Depense

void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)
{
	if (nombreDepenses_ == 0)
		listeDepenses_ = new Depense*[++tailleTabDepenses_];
	else if (nombreDepenses_ >= tailleTabDepenses_)
	{
		Depense** listeDepensesTemporaire = listeDepenses_;
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

//Methode d'ajout d'utilisateur

void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur)
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

//Methode calcul du total des depenses

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

//Methode permettant d'equillibrer les comptes
//Description de l'algorithme:
//La methode cherche a minimiser le nombre de transfert.
//Elle cherche donc les comptes ayant des valeurs complementaire
//afin d'eliminer deux utilisateur par transfert.
//Si aucun compte ne se complementent, la methode cherche le compte 
//avec la plus grande valeur positive et celui avec la plus grande valeur
//negative afin de creer un transfert avec le plus grand montant possible.
void Groupe::equilibrerComptes()
{
	//Avant de refaire la liste de transfert, on detruit l'ancienne
	if (listeTransferts_ != nullptr)
	{
		for (int i = 0; i < nombreTrensferts_; i++)
			delete listeTransferts_[i];
		delete[] listeTransferts_;
		nombreTrensferts_ = 0;
		listeTransferts_ = nullptr;
	}

	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	unsigned int plusGrandCompte = 0;
	unsigned int plusPetitCompte = 0;


	bool equilibrageEnCours = true;
	while (equilibrageEnCours == true)
	{
		equilibrageEnCours = false;

		//Cherche deux comptes complementaires
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
							if (abs(comptes_[i] + comptes_[j]) < 0.01)
							{
								equilibrageEnCours = true;
								if (comptes_[i] > 0.0)
								{
									listeTransferts_[nombreTrensferts_++] =
										new Transfert(comptes_[i],
											listeUtilisateurs_[j],
											listeUtilisateurs_[i]);
								}
								else
								{
									listeTransferts_[nombreTrensferts_++] =
										new Transfert(comptes_[j],
											listeUtilisateurs_[i],
											listeUtilisateurs_[j]);
								}

								comptes_[i] = 0.0;
								comptes_[j] = 0.0;

							}
						}
					}
				}
			}
		}

		//Si aucun comptes ne se complemente,
		//faire un transfert d'un montant maximale
		if (equilibrageEnCours == false)
		{
			for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
			{
				if (comptes_[i] != 0.0)
				{
					if (comptes_[plusGrandCompte] < comptes_[i])
						plusGrandCompte = i;
					else if (comptes_[plusPetitCompte] > comptes_[i])
						plusPetitCompte = i;
				}
			}

			if ((comptes_[plusGrandCompte] != 0.0) && 
				(comptes_[plusPetitCompte] != 0.0))
			{
				equilibrageEnCours = true;
				if (abs(comptes_[plusGrandCompte]) <= 
					abs(comptes_[plusPetitCompte]))
				{
					listeTransferts_[nombreTrensferts_++] = 
					new Transfert(abs(comptes_[plusGrandCompte]), 
								  listeUtilisateurs_[plusPetitCompte], 
								  listeUtilisateurs_[plusGrandCompte]);

					comptes_[plusPetitCompte] += comptes_[plusGrandCompte];
					comptes_[plusGrandCompte] = 0.0;
				}
				else if (abs(comptes_[plusGrandCompte]) >= abs(comptes_[plusPetitCompte]))
				{
					listeTransferts_[nombreTrensferts_++] = 
					new Transfert(abs(comptes_[plusPetitCompte]),
								  listeUtilisateurs_[plusPetitCompte], 
								  listeUtilisateurs_[plusGrandCompte]);

					comptes_[plusGrandCompte] += comptes_[plusPetitCompte];
					comptes_[plusPetitCompte] = 0.0;
				}
			}
							
		}
	}
}

//Methode d'affichage

void Groupe::afficherGroupe() const
{
	cout << "\n\n *****************************************\n\nL'evenement: "
		 << nom_ << '\n'
		 << "A coute un total de: " << totalDepenses_ << " $\n"
		 << "\nVoici les depenses:\n";

	for (unsigned i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();

	bool afficherComptes = false;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		if (abs(comptes_[i]) > 0.01)
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

