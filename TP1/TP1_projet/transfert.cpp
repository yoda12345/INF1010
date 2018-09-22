/*
transfert.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier source de la classe Transfert

*/
#include "transfert.h"

//Constructeurs

Transfert::Transfert(): montant_(0.0), donneur_(nullptr), receveur_(nullptr)
{
}

Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour):
		   montant_(montant), donneur_(de), receveur_(pour)
{
}

//Methodes d'acces

Utilisateur* Transfert::getDonneur() const
{
	return donneur_;
}

Utilisateur* Transfert::getReceveur() const
{
	return receveur_;
}

double Transfert::getMontant() const
{
	return montant_;
}

//Methodes de modifications

void Transfert::setDonneur(Utilisateur* donneur)
{
	donneur_ = donneur;
}

void Transfert::setMontant(double montant)
{
	montant_ = montant;
}

void Transfert::setReceveur(Utilisateur* receveur)
{
	receveur_ = receveur;
}

//Methode de d'affichage

void Transfert::afficherTransfert() const
{
	cout << donneur_->getNom() << " pour : " << receveur_->getNom()
		 << " d'un montant de : "<< montant_ << " $";
}

