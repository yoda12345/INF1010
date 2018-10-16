/******************************************************************************
utilisateur.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe Utilisateur

******************************************************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include"depenseGroupe.h"
#include"depense.h"

const double TAUX_REGULIER = 0.05;

enum TypeUtilisateur{Regulier, Premium};

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur(const string& nom = "", TypeUtilisateur type = Regulier);
	Utilisateur(const Utilisateur& utilisateur);

	// Methodes d'accès
	string getNom() const;
	double getInteret() const; 
	double getTotalDepenses() const;
	TypeUtilisateur getType() const; 
	vector<Depense*> getDepenses() const; 
	unsigned int getNombreDepenses() const; 

	// Methodes de modification
	void setNom(const string& nom);
	Utilisateur& operator=(Utilisateur* utilisateur);

	// Methodes d'ajout
	void ajouterInteret(double montant);
	Utilisateur& operator+=(Depense* depense);

	// Methode de calculs
	void calculerTotalDepenses();
	
	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Utilisateur& user);


private:
	double interet_;
	string nom_;
	TypeUtilisateur type_; 
	vector <Depense*> depenses_;
	double totalDepense_; 
};
#endif