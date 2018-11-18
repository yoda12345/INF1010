/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#ifndef GESTIONNAIRE_DEPENSES_H
#define GESTIONNAIRE_DEPENSES_H

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <algorithm>
#include <vector>


// GestionnaireDepenses
// Description: class permettant de gérer un vecteur de depenses
class GestionnaireDepenses:  
	public  GestionnaireGenerique< Depense*, 
								   vector<Depense*>, 
								   Depense*, 
								   AjouterDepense >
{
public:
	// Methode de calcul
	double getTotalDepenses() const;

	// Methode d'acces
	vector<Depense*> getDepenses() const;

	// Methode d'ajout
	virtual void ajouter(Depense* depense);
};

#endif