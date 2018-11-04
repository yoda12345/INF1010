/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
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
	   << "\t\tTotal a payer: " << Utilisateur::getTotalATransferer()
	   << "$ (" << abs(Utilisateur::getBalance()) << "$ economises)\n"
	   << "\t\tJours restants: " << joursRestants_ << endl;
	Utilisateur::print(os);
}