/******************************************************************************
depense.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier d'entête de la classe Depense

******************************************************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);
	Depense(const Depense& depense);

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);
	Depense& operator=(const Depense& depense);

	//Méthode d'affichage
	friend ostream& operator<<(ostream& sortie, const Depense& depense);

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif