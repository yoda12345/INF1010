/******************************************************************************
transfert.h
Cr�� par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de cr�ation: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-t�te de la classe Transfert

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

	// Methodes d'acc�s
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;


	// Methodes de modification
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// Methodes d'affichage
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;


};

#endif