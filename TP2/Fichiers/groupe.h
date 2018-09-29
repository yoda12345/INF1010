/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	// TODO: Modifier pour utiliser la surcharge d'operateur
	void ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	void ajouterUtilisateur(Utilisateur* utilisateur);

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// TODO: Remplacer par une surcharge de l'operateur <<
	void afficherGroupe() const;

private:
	string nom_;
	// Remplacer les doubles pointeurs par des vecteurs
	Utilisateur** utilisateurs_;
	unsigned int nombreUtilisateurs_;
	unsigned int tailleTabUtilisateurs_;
	Depense** depenses_;
	unsigned int nombreDepenses_;
	unsigned int tailleTabDepenses_;
	Transfert** transferts_;
	unsigned int nombreTransferts_;
	double* comptes_;

};

#endif
