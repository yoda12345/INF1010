/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}


double Transfert::getFraisTransfert() const
{
	return getFraisTransfert();
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

void Transfert::effectuerTransfert()
{
	expediteur_->modifierBalanceTranferts( montant_ );
	receveur_->modifierBalanceTranferts( -montant_ );
	if (typeid(*expediteur_) == typeid(UtilisateurPremium))
	{
		expediteur_->modifierBalanceFrais( -TAUX_EPARGNE * montant_ );
	}
	else
	{
		expediteur_->modifierBalanceFrais(getFraisTransfert());
	}
}



//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) 
{
	
	return os << "- " << transfert.getExpediteur()->getNom()
			  << "\t -> " << transfert.getReceveur()->getNom()
			  << "\t : " << transfert.getMontant() << "$\n";
}
