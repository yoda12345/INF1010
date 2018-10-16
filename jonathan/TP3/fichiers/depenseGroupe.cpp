/******************************************************************************
depenseGroupe.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre septembre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe DepenseGroupe

******************************************************************************/

#include "depenseGroupe.h"

// Constructeurs
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) :
	Depense(nom, montant, lieu), nombreParticipants_( 0 )
{
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) :
	Depense(static_cast<Depense>(depense)), 
	nombreParticipants_(depense.getNombreParticipants())
{
}

// Methodes d'acces
unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ > 0)
		return (getMontant() / nombreParticipants_);
	else
		return 0.0;
}

//Methodes de modifications
void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}

DepenseGroupe& DepenseGroupe::operator=(const DepenseGroupe& depense)
{
	// On utilise l'operateur= de la classe Depense
	static_cast<Depense>(*this) = static_cast<Depense>(depense);

	nombreParticipants_ = depense.nombreParticipants_;
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const DepenseGroupe& depense)
{
	// L'operateur<< de la classe Depense est utilise
	return os << "Depense de groupe : \t" << static_cast<Depense>(depense) 
			  << " fait par : " << depense.getNombreParticipants() << " soit : " 
			  << depense.getMontantPersonnel() << " par personne.";
}
