/******************************************************************************
groupe.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier d'entête de la classe Groupe

******************************************************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	size_t getNombreDepenses() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	Groupe& operator+=(Utilisateur* unUtilisateur);

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// Méthode d'affichage
	friend ostream& operator<<(ostream& sortie, const Groupe& groupe);

private:
	string nom_;
	vector< Utilisateur* > utilisateurs_;
	vector< Depense* > depenses_;
	vector< Transfert* > transferts_;
	vector< double > comptes_;

};

#endif
