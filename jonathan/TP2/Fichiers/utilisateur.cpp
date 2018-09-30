/******************************************************************************
utilisateur.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier source de la classe Utilisateur

******************************************************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() 
	: nom_("")
{
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom)
{
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur)
	: nom_(utilisateur.nom_), 
	  depenses_(utilisateur.depenses_)
{
}

// Methodes d'acces
string Utilisateur::getNom() const 
{
	return nom_;
}

size_t Utilisateur::getNombreDepense() const 
{
	return  depenses_.size();
}

double Utilisateur::getTotalDepenses() const 
{
	double total = 0.0;
	for (int i = 0; i <  depenses_.size(); i++) 
	{
		total += depenses_[i]->getMontant();
	}
	return total;
}

Depense Utilisateur::getDepense(const unsigned& noDepense) const
{
	if (noDepense < depenses_.size())
		return *depenses_[noDepense];
	
	return Depense();
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) 
{
	nom_ = nom;
}

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur)
{
	nom_ = utilisateur.nom_;
	depenses_ = utilisateur.depenses_;
	return *this;
}

 //Méthode d'ajout
Utilisateur& Utilisateur::operator+=(Depense* depense)
{
	this->depenses_.push_back(depense);
	return *this;
}



// Methode d'affichage
ostream& operator<<(ostream& sortie, const Utilisateur& utilisateur)
{
	sortie << "Utilisateur : " << utilisateur.nom_ 
		   << " a depense pour un total de : " 
		   << utilisateur.getTotalDepenses() << endl
		   << "\t Liste de depenses : " << endl;

	for (int i = 0; i < utilisateur.depenses_.size(); i++) 
	{
		sortie << "\t\t" << *(utilisateur.depenses_[i]);
	}
	return sortie;
}
