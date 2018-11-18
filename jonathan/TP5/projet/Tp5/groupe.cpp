/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs
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
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getConteneur();
}

// TODO : À modifier :
map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getUtilisateurs();
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : À modifier :
vector<double> Groupe::getComptes() const 
{
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
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

// Methodes de modifications
void Groupe::setNom(const string& nom) 
{
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{
	// Trouver l'index de l'auteur de la depense
	// Si payePar n<est pas dans le groupe on arrete immediatement
	if (gestionnaireUtilisateurs_->estExistant(payePar) == false) {
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	// depenses_.push_back(depense);
	gestionnaireDepenses_->ajouter(new Depense(nom, montant, lieu));

	*payePar += depense;

	// Mise a jour des comptes
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajouté :
	gestionnaireUtilisateurs_->ajouter(utilisateur);

	comptes_.push_back(0);
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		// On cherche le compte le plus eleve et le moins eleve
		pair<Utilisateur*, double>& max = gestionnaireUtilisateurs_->getMax();
		pair<Utilisateur*, double>& min = gestionnaireUtilisateurs_->getMin();

		// On cherche lequel des deux a la dette la plus grande
		if (-(min.second) <= max.second && min.second != 0 && max.second != 0) {
			if (min.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-(min.second), min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-(min.second), min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			max.second += min.second;
			min.second = 0;
		}
		else if (-(min.second) > max.second  && min.second != 0 && max.second != 0) {
			if (min.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			max.second = 0;
			min.second += max.second;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-(min.second) == max.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreUtilisateurs() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		os << "\t- " << *groupe.gestionnaireUtilisateurs_->getUtilisateurParIndex(i);
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (int i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getUtilisateurParIndex(i)->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
