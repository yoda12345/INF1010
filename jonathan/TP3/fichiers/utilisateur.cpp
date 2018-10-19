/******************************************************************************
utilisateur.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe Utilisateur

******************************************************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type) :
	nom_(nom), type_(type), interet_(0.0), totalDepense_(0.0)
{
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur) :
	interet_(utilisateur.interet_), nom_(utilisateur.nom_), 
	type_(utilisateur.type_), totalDepense_(utilisateur.totalDepense_),
	depenses_(utilisateur.depenses_)
{
}

// Methodes d'acces
string Utilisateur::getNom() const 
{
	return nom_;
}

double Utilisateur::getTotalDepenses() const 
{
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const 
{
	return type_; 
}

double Utilisateur::getInteret() const 
{
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const 
{
	
	return unsigned int(depenses_.size());
}

vector <Depense*> Utilisateur::getDepenses() const 
{
	return depenses_; 
}

// Methodes de modification
void Utilisateur::setNom(const string& nom) 
{
	nom_ = nom;
}

Utilisateur& Utilisateur::operator=(Utilisateur* utilisateur)
{
	if (this != utilisateur)
	{
		nom_ = utilisateur->nom_;
		depenses_ = utilisateur->depenses_;
		interet_ = utilisateur->interet_;
		type_ = utilisateur->type_;
		totalDepense_ = utilisateur->totalDepense_;
	}

	return *this;
}

// Methodes d'ajout
void Utilisateur::ajouterInteret(double montant)
{
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense)
{
	depenses_.push_back(depense);
	return *this;
}

// Methodes de calcul
void Utilisateur::calculerTotalDepenses() 
{
	totalDepense_ = 0.0;
	for (size_t i = 0; i < depenses_.size(); i++)
	{
		if( depenses_[i]->getType() == groupe )
			totalDepense_ +=  static_cast< DepenseGroupe* >(depenses_[i])->getMontantPersonnel();
		else
			totalDepense_ += depenses_[i]->getMontant();
	}
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os  << " a depense pour un total de : " << utilisateur.getTotalDepenses() 
		<< ", Polycount prend en interet : " << utilisateur.interet_ << endl
		<< "\t\t\tListe des depenses : ";

	for (int i = 0; i < utilisateur.depenses_.size(); i++)
	{
		os << "\n\t\t\t\t";

		if(utilisateur.depenses_[i]->getType() == groupe)
			os << *static_cast<DepenseGroupe*>(utilisateur.depenses_[i]);
		else
			os << *utilisateur.depenses_[i];
	}
	return os;
}

