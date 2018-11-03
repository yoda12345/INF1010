/******************************************************************************
utilisateurRegulier.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier d'en-tête de la classe utilisateurRegulier

******************************************************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	// Constructeurs 
	UtilisateurRegulier(const string& nom = ""); 
	UtilisateurRegulier(const Utilisateur& utilisateur); 


	// Methodes d'acces
	bool estGroupe() const; 
	 
	// Methodes de modifications
	void setEtatGroupe(bool etat); 
	UtilisateurRegulier& operator=(Utilisateur* utilisateur);

	// Methode d'affichage
	friend ostream& operator<< (ostream& os, 
								const UtilisateurRegulier& utilisateur);

private :
	bool estGroupe_; 
	
};

#endif // !UTILISATEUR_REGULIER_H
