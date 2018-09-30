/******************************************************************************
tranfert.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier d'entête de la classe Tranfert

******************************************************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
public:

	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Méthodes d'accès
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;

	//Méthodes de modification
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// Méthodes d'affichage
	friend ostream& operator<<(ostream& sortie, const Transfert& transfert);
private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;


};

#endif