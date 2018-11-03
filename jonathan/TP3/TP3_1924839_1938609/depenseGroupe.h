/******************************************************************************
depenseGroupe.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre septembre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe DepenseGroupe

******************************************************************************/

#ifndef DEPENSE_GROUPE_H
#define DEPENSE_GROUPE_H

#include "depense.h"

#include <vector>

using namespace std; 

class DepenseGroupe : public Depense {
public:
	//constructeur
	DepenseGroupe( const string& nom = "", double montant = 0, const string& lieu = "Montreal" );
	DepenseGroupe(const DepenseGroupe& depense); 

	// Methodes d'acces 
	unsigned int getNombreParticipants() const; 
	double getMontantPersonnel() const;

	// Methodes de modification
	void setNombreParticipants(unsigned int nombre); 
	DepenseGroupe& operator=(const DepenseGroupe& depense);

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const DepenseGroupe& depense); 
private : 
	//Les utilisateurs qui partageront la depense
	unsigned int  nombreParticipants_; 
};

#endif // !DEPENSE_GROUPEE_H
