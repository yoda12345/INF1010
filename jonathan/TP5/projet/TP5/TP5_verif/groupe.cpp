/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#include "groupe.h"

// *************************** Constructeurs ***************************
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getDepenses();
	for (size_t i = 0; i < depenses.size(); i++) 
	{
		delete depenses[i];
	}
	for (size_t i = 0; i < transferts_.size(); i++) 
	{
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// *************************** Methodes d'acces ***************************
string Groupe::getNom() const {
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getDepenses();
}

map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getUtilisateurs();
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

vector<double> Groupe::getComptes() const 
{
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const 
{
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// ************************ Methodes de modifications *************************
void Groupe::setNom(const string& nom) 
{
	nom_ = nom;
}

//*************************** Methodes d'ajout ***************************

Groupe& Groupe::ajouterDepense(double montant, 
							   Utilisateur* payePar,
							   const string& nom,
							   const string& lieu)
{
	// Verification de la presence dans le groupe
	if (gestionnaireUtilisateurs_->estExistant(payePar) == false) {
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);

	gestionnaireDepenses_->ajouter(depense);


	*payePar += depense;

	// Mise a jour des comptes
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	gestionnaireUtilisateurs_->ajouter(utilisateur);
	return *this;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		pair<Utilisateur*, double> utilisateurMax = 
			gestionnaireUtilisateurs_->getMax();

		pair<Utilisateur*, double> utilisateurMin = 
			gestionnaireUtilisateurs_->getMin();

		// On cherche lequel des deux a la dette la plus grande
		if (-(utilisateurMin.second) <= utilisateurMax.second &&
			  utilisateurMin.second != 0 && utilisateurMax.second != 0) 
		{
			if (utilisateurMin.first->getMethodePaiement() == Interac) 
			{
				TransfertInterac* transfert = 
					new TransfertInterac(-utilisateurMin.second, 
										  utilisateurMin.first, 
										  utilisateurMax.first);

				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else 
			{
				TransfertPaypal* transfert = 
					new TransfertPaypal(-utilisateurMin.second, 
										 utilisateurMin.first, 
										 utilisateurMax.first);

				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}

			// Mise a jours des comptes
			utilisateurMax.second += utilisateurMin.second;
			gestionnaireUtilisateurs_->setCompte(utilisateurMax);
			utilisateurMin.second = 0;
			gestionnaireUtilisateurs_->setCompte(utilisateurMin);

		}
		else if (-(utilisateurMin.second) > utilisateurMax.second &&
				  (utilisateurMin.second) != 0 && utilisateurMax.second != 0)
		{
			if (utilisateurMin.first->getMethodePaiement() == Interac) 
			{
				TransfertInterac* transfert = 
					new TransfertInterac(utilisateurMax.second, 
										 utilisateurMin.first, 
										 utilisateurMax.first);

				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = 
					new TransfertPaypal(utilisateurMax.second, 
										utilisateurMin.first, 
										utilisateurMax.first);

				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}

			//Mise a jours des comptes
			utilisateurMin.second += utilisateurMax.second;
			gestionnaireUtilisateurs_->setCompte(utilisateurMin);
			utilisateurMax.second = 0;
			gestionnaireUtilisateurs_->setCompte(utilisateurMax);
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-utilisateurMin.second == utilisateurMax.second) 
		{
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreUtilisateurs() - 1) 
		{
			calcul = false;
		}
	}

}

//*************************** Methode d'affichage ***************************
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " 
	   << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; 
		 i < groupe.gestionnaireUtilisateurs_->getNombreUtilisateurs(); 
		 i++) 
	{
		os << "\t- " 
		   << *groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) 
	{
		os << "Transferts :" << endl;
		for (size_t i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (size_t i = 0; i < groupe.getComptes().size(); i++) 
		{
			os << groupe.gestionnaireUtilisateurs_
							->getElementParIndex(i).first->getNom()
			   << " : " 
			   << groupe.gestionnaireUtilisateurs_
							->getElementParIndex(i).second 
			   << endl;
		}
	}

	os << endl;
	return os;
}
