/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	// Constructeur
	TransfertPaypal(double montant, 
					Utilisateur* expediteur,
					Utilisateur* receveur);

	// Methode d'acces
	string getId() const;
	virtual double getFraisTransfert() const;

	// Methode de modification
	void setId(string id);
private:
	string id_;
};