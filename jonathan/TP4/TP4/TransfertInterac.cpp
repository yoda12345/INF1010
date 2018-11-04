/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#include "transfertInterac.h"

// Constructeur
TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur), courriel_(receveur->getCourriel())
{
}

// Methode d'acces
string TransfertInterac::getCourriel() const
{
	return courriel_;
}

double TransfertInterac::getFraisTransfert() const
{
	if (typeid(*getExpediteur()) == typeid(UtilisateurPremium))
		return 0.0;
	else
		return FRAIS_TRANSFERT;

}

// Methode de modification
void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}


