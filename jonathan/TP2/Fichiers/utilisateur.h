/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

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
	// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& utilisateur);

	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;
	Depense getDepense(unsigned noDepense) const;

	// Methodes de modification
	void setNom(const string& nom);

	// TODO: Ajouter un operateur += et =
	//void ajouterDepense(Depense* uneDepense);
	Utilisateur& operator+=(Depense* depense);
	Utilisateur& operator=(Utilisateur& utilisateur);

	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherUtilisateur() const;
	friend ostream& operator<<(ostream& sortie, const Utilisateur& utilisateur);

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	//unsigned int tailleTabDepense_;
	//unsigned int nombreDepenses_;
	//Depense ** depenses_;
	vector< Depense* > depenses_;

};
#endif