/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"

const double TAUX_EPARGNE = 0.03;

class UtilisateurPremium : public Utilisateur {
public :

	// Constructeurs 
	UtilisateurPremium(const string& nom = "",
					   MethodePaiement methodePaiement = Interac,
					   unsigned int joursRestants = 0,
					   const string& courriel = "",
					   const string& idPaypal = "");

	// Methodes d'acces
	unsigned int getJoursRestants() const; 

	// Methodes de modifications
	void setJoursRestants(unsigned int joursRestants); 

	// Methode d'affichage
	virtual void print(ostream& os) const;

private : 
	unsigned int joursRestants_;
};

#endif 
