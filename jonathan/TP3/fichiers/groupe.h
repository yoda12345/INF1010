/******************************************************************************
groupe.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe Groupe

******************************************************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "depenseGroupe.h"
#include"utilisateurPremium.h"
#include "utilisateurRegulier.h"
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
	vector<DepenseGroupe*> getDepenses() const;
	vector<Utilisateur*> getUtilisateurs() const;
	vector<Transfert*> getTransferts() const; 
	double getTotalDepenses() const;
	vector<double> getComptes() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour);
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();
	void calculerTotalDepense(); 

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<DepenseGroupe*> depenses_;
	vector<Transfert*> transferts_;
	double totalDepenses_; 
	vector<double> comptes_; 
};

#endif
