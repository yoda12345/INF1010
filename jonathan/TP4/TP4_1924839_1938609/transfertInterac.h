/********************************************
* Titre: Travail pratique #4 - tranfertInterac.h
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/
#pragma once

#include "transfert.h"
#include "utilisateurPremium.h"

const double FRAIS_TRANSFERT = 1.0;

class TransfertInterac : public Transfert {
public:
	// Constructeur
	TransfertInterac(double montant,
					 Utilisateur* expediteur,
					 Utilisateur* receveur);

	// Methodes d'acces
	string getCourriel() const;
	virtual double getFraisTransfert() const;

	// Methodes de modifications
	void setcourriel(string courriel);
	
private:
	string courriel_;
};