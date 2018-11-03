/******************************************************************************
groupe.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe Groupe

******************************************************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() : nom_(""), totalDepenses_(0.0)
{
}

Groupe::Groupe(const string& nom) : nom_(nom), totalDepenses_(0.0)
{
}

Groupe::~Groupe() 
{
	for (int i = 0; i < transferts_.size(); i++) 
	{
		delete transferts_[i];
	}
}


// Methodes d'acces
string Groupe::getNom() const 
{
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const 
{
	return totalDepenses_;
}

vector<double> Groupe::getComptes() const
{
	return comptes_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) 
{
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, 
							   Utilisateur* payePar,
							   vector<Utilisateur*> payePour)
{
	
	// Verification de la presence de l'utilisateur payePar dans le groupe
	bool estPresent = false;
	size_t i = 0;
	while ((estPresent == false) && (i < utilisateurs_.size()))
	{
		if (utilisateurs_[i]->getNom() == payePar->getNom())
			estPresent = true;

		i++;
	}

	bool sontPresents = true;
	if (estPresent == false)
		sontPresents = false;

	// Verification de la presence des utilisateurs payePour dans le groupe
	size_t j = 0;
	while ((sontPresents == true) && (j < payePour.size()))
	{
		i = 0;
		estPresent = false;
		while ((estPresent == false) && (i < utilisateurs_.size()))
		{
			if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				estPresent = true;

			i++;
		}
		j++;
		if ((estPresent == false) && (i < utilisateurs_.size()))
			sontPresents = false;
	}

	// Ajout de la depense aux utilisateur s'il sont tous present 
	// et que la depense est de groupe
	if ((depense->getType() == groupe) && (sontPresents == true))
	{
		// Modification du nombre de participant de la depense
		static_cast<DepenseGroupe*>(depense)
			->setNombreParticipants(unsigned int(payePour.size() + 1));

		// Ajout de la depense a la liste de depense du groupe
		depenses_.push_back(static_cast< DepenseGroupe* >(depense));
		
		// Ajout de la depense a l'utilisateur payePar
		(*payePar) += depense;

		// Recherche de l'index de l'utilisateur payePar 
		// dans la liste d'utilisateurs
		size_t i = 0;
		while (payePar->getNom() != utilisateurs_[i]->getNom())
		{
			i++;
		}

		// Ajustement du comptes de l'utilisateur payePar 
		// (Il doit se faire rembourse la partie des autres)
		comptes_[i] += depense->getMontant()
					- static_cast<DepenseGroupe*>(depense)
					  ->getMontantPersonnel();

		// On repete l'operation fait sur l'utilisateur payePar 
		// mais pour les utilisateurs payePour
		for (size_t i = 0; i < payePour.size(); i++)
		{

			*payePour[i] += depense;
			j = 0;
			while (payePour[i]->getNom() != utilisateurs_[j]->getNom())
			{
				j++;
			}
			// Les utilisateurs payePour 
			// doivent rembourser leur montant personnel
			comptes_[j] -= static_cast<DepenseGroupe*>(depense)
						   ->getMontantPersonnel();
		}
	}
	else
	{
		cout << "\nErreur	:	Vous tentez d'ajouter une depense "
			 << "individuelle au groupe ou alors les personnes impliquees "
			 << "dans la depense groupe ne sont pas dans le groupe";
	}
	
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Verification de l'abonnement de l'utilisateur
	bool doitRenouveler = false;
	bool estAjouter = true;
	if (utilisateur->getType() == Regulier)
	{
		if (static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe() == true)
			estAjouter = false;
		else
			static_cast<UtilisateurRegulier*>
			(utilisateur)->setEtatGroupe(true);
	}
	else if (static_cast<UtilisateurPremium*>(utilisateur)
			 ->getJoursRestants() <= 0)
	{
		doitRenouveler = true;
		estAjouter = false;
	}

	if (estAjouter == true)
	{
		utilisateurs_.push_back(utilisateur);
		comptes_.push_back(0.0);
	}
	else if (doitRenouveler == true)
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " doit renouveler son abonnement Premium";
	}
	else
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			 << " n'est pas souscrit a un abonnement premium,"
			 << " et est deja groupe";
	}
	return *this;
}


// Methodes de calcul
void Groupe::equilibrerComptes() 
{
	// On met a jours les taux des utilisateur Premium
	for (int i = 0; i < utilisateurs_.size(); i++)
	{
		if (utilisateurs_[i]->getType() == Premium)
			static_cast<UtilisateurPremium*>(utilisateurs_[i])->calculerTaux();
	}

	bool calcul = true;
	int count = 0;
	while (calcul) 
	{
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, 
												 utilisateurs_[indexMin],
												 utilisateurs_[indexMax]));

			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
			if (utilisateurs_[indexMin]->getType() == Regulier)
			{
				utilisateurs_[indexMin]->ajouterInteret(TAUX_REGULIER * -min);
			}
			else
			{
				double taux = 
					static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])
					->getTaux();

				utilisateurs_[indexMin]->ajouterInteret(taux * -min);	
			}

		}
		else if (-min > max  && min != 0 && max != 0) 
		{
			transferts_.push_back(new Transfert(max, 
											    utilisateurs_[indexMin], 
											    utilisateurs_[indexMax]));

			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;

			if (utilisateurs_[indexMin]->getType() == Regulier)
			{
				utilisateurs_[indexMin]->ajouterInteret(TAUX_REGULIER * max);
			}
			else
			{
				double taux = 
					static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])
					->getTaux();

				utilisateurs_[indexMin]->ajouterInteret(taux * max);
			}

		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) 
		{
			count++;
		}
		if (count >= utilisateurs_.size() - 1) 
		{
			calcul = false;
		}
	}
	
}

void Groupe::calculerTotalDepense() 
{
	for (int i = 0; i < utilisateurs_.size(); i++)
	{
		utilisateurs_[i]->calculerTotalDepenses();
	}

	totalDepenses_ = 0.0;
	for (int i = 0; i < depenses_.size(); i++)
	{
		totalDepenses_ += depenses_[i]->getMontant();
	}

}

// Methode d'affichage
ostream& operator<<(ostream& os, const Groupe& groupe)
{
	os << "\n\nL'evenement " << groupe.nom_ 
	   << " a coute un total (en terme de depenses groupees) de : "
	   << groupe.getTotalDepenses() 
	   << "\n Voici les utilisateurs et toute leur depenses :";

	for (int i = 0; i < groupe.utilisateurs_.size(); i++)
	{
		if(groupe.utilisateurs_[i]->getType() == Regulier)
			os << *static_cast<UtilisateurRegulier*>(groupe.utilisateurs_[i]);
		else
			os << *static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i]);
	}
	os << endl;

	if (groupe.transferts_.size() != 0)
	{
		os << "Les transferts suivants ont"
		   << " ete realiser pour equilibrer  : " << endl;

		for (int i = 0; i < groupe.transferts_.size(); i++)
		{
			os << "\t" << *(groupe.transferts_[i]);
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	return os;
}
