/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"

// Constructeurs
UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), joursRestants_(joursRestants)
{}

// Methode d'acces
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

// Methode de modifications
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

// Affichage

void UtilisateurPremium::print(ostream & os) const
{
	os << "- Utilisateur (Premium) " << nom_ << " :\n"
	   << "\tTotal a payer: " << Utilisateur::getTotalATransferer()
	   << "$ (" << Utilisateur::getBalance() << "$ economises)\n";
	Utilisateur::print(os);
}