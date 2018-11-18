/********************************************
* Titre: Travail pratique #4 - depense.cpp
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#include "depense.h"

// Constucteurs

Depense::Depense(const string& nom, 
				 double montant, 
				 const string& lieu) : 
	nom_(nom), 
	montant_(montant), 
	lieu_(new string(lieu)) {
}

Depense::Depense(const Depense& depense) : 
	nom_(depense.nom_),
	montant_(depense.montant_),
	lieu_(new string(*(depense.lieu_))) {
}

Depense::~Depense()
{
	if (lieu_ != nullptr)
		delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const
{
	return lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom)
{
	*lieu_ = nom;
}

Depense& Depense::operator=(const Depense & depense)
{
	if (this != &depense) {
		nom_ = depense.nom_;
		montant_ = depense.montant_;
		*lieu_ = *depense.lieu_;
	}
	return *this;
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Depense& depense)
{
	return os << "- Depense (a " << *depense.lieu_ << ") : "  
			  << depense.nom_ << ". Prix : " << depense.montant_ 
			  << "$" << endl;
}
