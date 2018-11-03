/******************************************************************************
depense.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe Depense

******************************************************************************/

#include "depense.h"

// Constucteurs
Depense::Depense(const string& nom, double montant, const string& lieu) :
	nom_(nom), montant_(montant), lieu_( new string(lieu)), type_(individuelle)
{
}

Depense::Depense(const Depense& depense) : 
	nom_(depense.nom_), montant_(depense.montant_), 
	lieu_(new string(*(depense.lieu_))), type_(depense.type_)
{
}


// Destructeur
Depense::~Depense()
{	
	if (lieu_ != nullptr)
		delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const 
{
	return nom_;
}

double Depense::getMontant() const 
{
	return montant_;
}

string* Depense::getLieu() const
{
	return lieu_;
}

TypeDepense Depense::getType() const
{
	return type_;
}



// Methodes de modifications
void Depense::setNom(const string& nom) 
{
	nom_ = nom;
}

void Depense::setMontant(double montant) 
{
	montant_ = montant;
}

void Depense::setLieu(const string& nom)
{
	delete lieu_;
	lieu_ = new string(nom);
}


void Depense::setType(TypeDepense type) 
{
	type_ = type; 
}

Depense& Depense::operator=(const Depense& depense)
{
	if (this != &depense)
	{
		nom_ = depense.nom_;
		montant_ = depense.montant_;
		delete lieu_;
		lieu_ = new string(*(depense.lieu_));
		type_ = depense.type_;
	}

	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Depense& depense)
{
	return os << "Achat : " << depense.nom_ << " Lieu : " << (*depense.lieu_)
			  << " Prix : "<< depense.montant_;
}
