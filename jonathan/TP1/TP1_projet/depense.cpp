/*
depense.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier source de la classe Depense

*/
#include "depense.h"

// Constructeurs

Depense::Depense(): titre_("Inconnu"), montant_(0.0)
{
}

Depense::Depense(const string & titre, double montant): 
		 titre_(titre), montant_(montant)
{
}

// Méthodes d'accès

string Depense::getTitre() const
{
	return titre_;
}


double Depense::getMontant() const
{
	return montant_;
}

//Methodes de modifications

void Depense::setTitre(const string & titre)
{
	titre_ = titre;
}


void Depense::setMontant(double montant)
{
	montant_ = montant;
}

//Méthode d'affichage

void Depense::afficherDepense() const
{
	cout << "Achat : " << titre_ << " Prix: " << montant_ << " $";
}




