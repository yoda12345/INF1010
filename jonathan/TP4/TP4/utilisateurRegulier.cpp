/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

// Constructeur
UtilisateurRegulier::UtilisateurRegulier(const string& nom, 
										 MethodePaiement methodePaiement,
										 const string& courriel,
										 const string& idPaypal):
	Utilisateur(nom, methodePaiement, courriel, idPaypal),
	possedeGroupe_(false)
{}



// Methode d'acces 
bool UtilisateurRegulier::getPossedeGroupe() const 
{
	return possedeGroupe_;
}

// Methodes de modifications
void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) 
{
	possedeGroupe_ = possedeGroupe;
}

//Affichage
void UtilisateurRegulier::print(ostream & os) const
{
	os << "- Utilisateur (Regulier) " << nom_ << " :\n"
		<< "\tTotal a payer: " << Utilisateur::getTotalATransferer()
		<< "$ (" << Utilisateur::getBalance() << "$ de frais)\n";
	Utilisateur::print(os);
}
