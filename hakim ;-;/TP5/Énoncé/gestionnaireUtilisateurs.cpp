/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

vector<double> GestionnaireUtilisateurs::getComptes() const
{
	vector<double> comptes;

	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		comptes.push_back(it->second);
	}

	return comptes;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur * utilisateur) const
{
	auto it = conteneur_.begin();

	for (int i = 0; i < getNombreElements(); i++)
	{
		if ((*it).first == utilisateur)
		{
			return true;
		}
		else
		{
			it++;
		}
	}

	return false;
}

void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur * payePar, double montant)
{
	// ;-;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const
{
	auto itMax = conteneur_.begin();

	for (auto it1 = conteneur_.begin(); it1 != conteneur_.end(); it1++)
	{
		auto it2 = it1;
		it2++; //places it2 right after it1
		for (it2; it2 != conteneur_.end(); it2++)
		{
			if ((*it1).second > (*it2).second)
			{
				itMax = it1;
			}
			else
			{
				itMax = it2;
			}
		}
	}

	return *itMax; //why ;-;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const
{
	auto itMin = conteneur_.begin();

	for (auto it1 = conteneur_.begin(); it1 != conteneur_.end(); it1++)
	{
		auto it2 = it1;
		it2++; //places it2 right after it1
		for (it2; it2 != conteneur_.end(); it2++)
		{
			if ((*it1).second < (*it2).second)
			{
				itMin = it1;
			}
			else
			{
				itMin = it2;
			}
		}
	}

	return *itMin; //why ;-;
}
