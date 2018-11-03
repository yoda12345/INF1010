/******************************************************************************
depense.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe Depense

******************************************************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>



using namespace std;

enum TypeDepense {groupe, individuelle};

class Depense {
public:
	// Constructeurs
	Depense(const string& nom = "", double montant = 0 , const string& lieu = "Montreal");
	Depense(const Depense& depense);

	// Destructeur 
	~Depense();

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;
	TypeDepense getType() const; 

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);
	void setType(TypeDepense type); 
	
	// Operateurs
	Depense& operator=(const Depense& depense);

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);
private:
	string nom_;
	double montant_;
	string* lieu_;
	TypeDepense type_; 

};
#endif