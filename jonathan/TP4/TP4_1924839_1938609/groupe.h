/********************************************
* Titre: Travail pratique #4 - groupe.h
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>

#include "depense.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfertInterac.h"
#include "transfertPaypal.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);
	Groupe(const Groupe & groupe);

	//Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	vector<Depense*> getDepenses() const;
	vector<Utilisateur*> getUtilisateurs() const;
	vector<Transfert*> getTransferts() const;
	vector<double> getComptes() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);
	Groupe & operator=(const Groupe & groupe);

	// Methodes d'ajout
	Groupe& ajouterDepense(double montant,
						   Utilisateur* payePar,
						   const string& nom = "",
						   const string& lieu = "Montreal");

	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void equilibrerComptes();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<Depense*> depenses_;
	vector<Transfert*> transferts_;
	vector<double> comptes_; 
};

#endif
