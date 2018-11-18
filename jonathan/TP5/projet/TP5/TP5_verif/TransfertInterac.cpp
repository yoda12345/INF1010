/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#include "transfertInterac.h"

TransfertInterac::TransfertInterac(double montant, 
								   Utilisateur* expediteur,
								   Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur), 
	  courriel_(receveur->getCourriel())
{
}

string TransfertInterac::getCourriel() const
{
	return courriel_;
}

void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}

double TransfertInterac::getFraisTransfert() const
{
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) == nullptr) {
		return FRAIS_TRANSFERT;
	}
	else {
		return 0;
	}
}

