/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	TransfertPaypal(double montant,
					Utilisateur* expediteur,
					Utilisateur* receveur);

	string getId() const;
	void setId(string id);

	virtual double getFraisTransfert() const;

private:
	string id_;
};