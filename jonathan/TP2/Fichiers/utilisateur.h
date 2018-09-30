/******************************************************************************
utilisateur.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier d'entête de la classe Utilisateur

******************************************************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	Utilisateur(const Utilisateur& utilisateur);

	// Methodes d'accès
	string getNom() const;
	size_t getNombreDepense() const;
	double getTotalDepenses() const;
	Depense getDepense(const unsigned& noDepense) const;

	// Methodes de modification
	void setNom(const string& nom);
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// Methodes d'ajout
	Utilisateur& operator+=(Depense* depense);

	//Méthode d'affichage
	friend ostream& operator<<(ostream& sortie, 
							   const Utilisateur& utilisateur);

private:
	string nom_;
	vector< Depense* > depenses_;

};
#endif