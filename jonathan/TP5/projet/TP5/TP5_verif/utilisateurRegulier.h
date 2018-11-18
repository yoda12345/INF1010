/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	// Constructeurs 
	UtilisateurRegulier(const string& nom = "",
						MethodePaiement methodePaiement = Interac,
						const string& courriel = "", 
		const string& idPaypal = "");

	// Methode d'acces 
	bool getPossedeGroupe() const; 
	 
	// Methodes de modifications
	void setPossedeGroupe(bool etat); 
		
	//Affichage
	virtual void print(ostream& os) const;

private :
	bool possedeGroupe_; 
};

#endif
