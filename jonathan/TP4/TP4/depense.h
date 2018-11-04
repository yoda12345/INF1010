/********************************************
* Titre: Travail pratique #4 - depense.h
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	Depense(const string& nom = "",
			double montant = 0 ,
			const string& lieu = "Montreal");

	Depense(const Depense& depense);

	// Destructeur
	~Depense();


	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);
	Depense & operator=(const Depense& depense);

	// Affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);
private:
	string nom_;
	double montant_;
	string* lieu_;

};
#endif