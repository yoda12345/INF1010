/******************************************************************************
transfert.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier source de la classe Transfert

******************************************************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() 
	: montant_(0.0), 
	  expediteur_(nullptr), 
	  receveur_(nullptr) 
{
}

Transfert::Transfert(double montant, 
					 Utilisateur* expediteur, Utilisateur* receveur) 
	: montant_(montant), 
	  expediteur_(expediteur), 
	  receveur_(receveur) 
{
}

// Methodes d'acces
double Transfert::getMontant() const 
{
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const 
{
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const 
{
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) 
{
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) 
{
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) 
{
	receveur_ = receveur;
}

//Methode affichage
ostream& operator<<(ostream& sortie, const Transfert& transfert)
{
	return sortie << "Transfert fait par " << transfert.expediteur_->getNom()
				  << " vers " << transfert.receveur_->getNom()
				  << " d'un montant de " << transfert.montant_ << endl;
}
