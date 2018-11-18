/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, 
								 Utilisateur * expediteur, 
								 Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur), id_(expediteur->getIdPaypal())
{
}

string TransfertPaypal::getId() const
{
	return id_;
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

double TransfertPaypal::getFraisTransfert() const
{
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) == nullptr) {
		return montant_ * (COMMISSION) + FRAIS;
	}
	else {
		return 0;
	}
}
