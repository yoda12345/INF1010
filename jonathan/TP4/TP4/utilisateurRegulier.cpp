/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
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
	os << "\n\t - Utilisateur (Regulier) " << nom_ << " :\n"
		<< "\t\tTotal a payer: " << Utilisateur::getTotalATransferer()
		<< "$ (" << Utilisateur::getBalance() << "$ de frais)\n";
	Utilisateur::print(os);
}
