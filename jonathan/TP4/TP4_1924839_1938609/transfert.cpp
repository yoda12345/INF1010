/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) 
{
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) 
{
}

// Methodes d'acces
double Transfert::getMontant() const 
{
	return montant_;
}


//double Transfert::getFraisTransfert() const
//{
	// Si la version de Transfert de getFraisTransfert est appele
	// (Normalement ce n'est pas le cas vu qu'elle est virtuel)
	// ,le resultat de la fonction virtuel approprie sera retourne
	//return getFraisTransfert();
//}

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
	os << "- " << transfert.getExpediteur()->getNom() << "\t";

	if (transfert.getExpediteur()->getNom().size() <= 5)
		os << "\t";

	os << "-> " << transfert.getReceveur()->getNom() << "\t";

	if (transfert.getReceveur()->getNom().size() <= 5)
		os << "\t";
	
	os << ": " << transfert.getMontant() << "$\n";
	return os;
}