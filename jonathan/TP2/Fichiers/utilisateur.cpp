/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("")
{
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom)
{
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur)
	: nom_(utilisateur.nom_), depenses_(utilisateur.depenses_)
{
}

//Destructeur
Utilisateur::~Utilisateur() 
{
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return  depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i <  depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

Depense Utilisateur::getDepense(unsigned noDepense) const
{
	if (noDepense < depenses_.size())
		return *depenses_[noDepense];
	
	return Depense();
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

//void Utilisateur::ajouterDepense(Depense* depense) {
Utilisateur& Utilisateur::operator+=(Depense* depense)
{
	this->depenses_.push_back(depense);
	return *this;
}

Utilisateur& Utilisateur::operator=(Utilisateur& utilisateur)
{
	// TODO: insérer une instruction return ici
	nom_ = utilisateur.nom_;
	depenses_ = utilisateur.depenses_;
	return *this;
}

// Methode d'affichage
//void Utilisateur::afficherUtilisateur() const {
//
//	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
//	cout << "\t Liste de depenses : " << endl;
//	for (int i = 0; i < nombreDepenses_; i++) {
//		cout << "\t\t";
//		depenses_[i]->afficherDepense();
//	}
//
//}

ostream & operator<<(ostream & sortie, const Utilisateur& utilisateur)
{
	sortie << "Utilisateur : " << utilisateur.nom_ << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl;
	sortie << "\t Liste de depenses : " << endl;
	for (int i = 0; i < utilisateur.depenses_.size(); i++) {
		sortie << "\t\t";
		sortie << *(utilisateur.depenses_[i]);
	}
	return sortie;
}
