/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#include "transfertPaypal.h"

// Constructeur
TransfertPaypal::TransfertPaypal(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur), id_(expediteur->getIdPaypal())
{
}

// Methode d'acces
string TransfertPaypal::getId() const
{
	return id_;
}

double TransfertPaypal::getFraisTransfert() const
{
	if (typeid(*getExpediteur()) == typeid(UtilisateurPremium))
		return 0.0;
	else
		return (COMMISSION * getMontant() + FRAIS);

}

// Methode de modification
void TransfertPaypal::setId(string id)
{
	id_ = id;
}



