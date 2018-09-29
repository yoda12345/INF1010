/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0) {
}

Depense::Depense(const string& nom, double montant) : nom_(nom), montant_(montant) {
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

// Methode d'affichage
void Depense::afficherDepense() const {
	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
}
