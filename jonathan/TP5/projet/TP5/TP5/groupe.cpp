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
	vector<Depense*> depenses = gestionnaireDepenses_->getDepenses();
	for (size_t i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (size_t i = 0; i < transferts_.size(); i++) {
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
	return gestionnaireDepenses_->getDepenses();
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
vector<double> Groupe::getComptes() const {
	return comptes_;
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
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{
	// Trouver l'index de l'auteur de la depense
	//int indexPayePar = gestionnaireUtilisateurs_->getIndexDe(payePar);

	if (gestionnaireUtilisateurs_->estExistant(payePar) == false) {
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	// depenses_.push_back(depense);
	gestionnaireDepenses_->ajouter(depense);


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
		pair<Utilisateur*, double> utilisateurMax = gestionnaireUtilisateurs_->getMax();
		pair<Utilisateur*, double> utilisateurMin = gestionnaireUtilisateurs_->getMin();
		//int indexMax = 0;
		//int indexMin = 0;

		//// On cherche le compte le plus eleve et le moins eleve
		//for (int i = 0; i < gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		//	if (comptes_[i] > max) {
		//		max = comptes_[i];
		//		indexMax = i;
		//	}
		//	if (comptes_[i] < min) {
		//		min = comptes_[i];
		//		indexMin = i;
		//	}
		//}

		// On cherche lequel des deux a la dette la plus grande
		if (-(utilisateurMin.second) <= utilisateurMax.second && utilisateurMin.second != 0 && utilisateurMax.second != 0) {
			if (utilisateurMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-utilisateurMin.second, utilisateurMin.first, utilisateurMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-utilisateurMin.second, utilisateurMin.first, utilisateurMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			utilisateurMax.second += utilisateurMin.second;
			gestionnaireUtilisateurs_->setCompte(utilisateurMax);
			utilisateurMin.second = 0;
			gestionnaireUtilisateurs_->setCompte(utilisateurMin);
		}
		else if (-(utilisateurMin.second) > utilisateurMax.second && (utilisateurMin.second) != 0 && utilisateurMax.second != 0) {
			if (utilisateurMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(utilisateurMax.second, utilisateurMin.first, utilisateurMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(utilisateurMax.second, utilisateurMin.first, utilisateurMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}

			utilisateurMin.second += utilisateurMax.second;
			gestionnaireUtilisateurs_->setCompte(utilisateurMin);
			utilisateurMax.second = 0;
			gestionnaireUtilisateurs_->setCompte(utilisateurMax);
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-utilisateurMin.second == utilisateurMax.second) {
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
		os << "\t- " << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (size_t i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (size_t i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first << endl;
		}
	}

	os << endl;
	return os;
}
