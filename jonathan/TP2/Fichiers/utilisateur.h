/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	// TODO: Ajouter un constructeur par copie

	// Destructeur
	~Utilisateur();

	// Methodes d'acc�s
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// TODO: Ajouter un operateur += et =
	void ajouterDepense(Depense* uneDepense);
	
	// TODO: Remplacer par une surcharge de l'operateur <<
	void afficherUtilisateur() const;

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	unsigned int tailleTabDepense_;
	unsigned int nombreDepenses_;
	Depense ** depenses_;

};
#endif