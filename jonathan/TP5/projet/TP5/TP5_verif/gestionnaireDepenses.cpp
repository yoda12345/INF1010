/********************************************
* Titre: Travail pratique #5 - gestionnaireDepenses.cpp
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#include "gestionnaireDepenses.h"

// *************************** Methode de calcul ***************************

double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	for (auto it = conteneur_.begin(); 
		 it != conteneur_.end(); it++) 
	{
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
};

// *************************** Methode d'acces ***************************

vector<Depense*> GestionnaireDepenses::getDepenses() const
{
	return getConteneur();
}

// *************************** Methode d'ajout ***************************

void GestionnaireDepenses::ajouter(Depense* depense)
{
	GestionnaireGenerique::ajouter(depense);
}
