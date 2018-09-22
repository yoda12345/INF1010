/*
depense.cpp
Cr�� par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de cr�ation: 14 septembre 2018
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

// M�thodes d'acc�s

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

//M�thode d'affichage

void Depense::afficherDepense() const
{
	cout << "Achat : " << titre_ << " Prix: " << montant_ << " $";
}




