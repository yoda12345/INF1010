/******************************************************************************
utilisateurPremium.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe utilisateurPremium

******************************************************************************/

#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"


class UtilisateurPremium : public Utilisateur {
public :

	// Constructeurs 
	UtilisateurPremium(const string& nom= "");
	UtilisateurPremium(const Utilisateur& utilisateur); 


	// Methodes d'acces
	unsigned int getJoursRestants() const; 
	double getTaux() const; 

	// Methodes de modification
	void setJoursRestants(unsigned int joursRestants); 
	UtilisateurPremium& operator= (Utilisateur* utilisateur);

	// Methodes de calcul 
	void calculerTaux(); 

	// Methode d'affichage
	friend ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur); 

private : 
	unsigned int joursRestants_; 
	double taux_; 
};

#endif 
