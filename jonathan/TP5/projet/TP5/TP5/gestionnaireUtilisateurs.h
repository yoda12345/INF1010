/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"
#include <vector>
#include "foncteur.h"
#include "gestionnaireGenerique.h"
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
#include <iterator>
using namespace std;
using namespace std::placeholders;
class GestionnaireUtilisateurs :
	public  GestionnaireGenerique< Utilisateur*,
								   map<Utilisateur*, double>,
								   pair<Utilisateur*, double>,
								   AjouterUtilisateur >
{
public:

	vector<double> getComptes() const;

	int getNombreUtilisateurs() const;

	map<Utilisateur*, double> getUtilisateurs() const;

	bool estExistant(Utilisateur * utilisateur) const;

	void mettreAJourComptes(Utilisateur * payePar, double montant);

	pair<Utilisateur*, double> getElementParIndex(int i) const;

	pair<Utilisateur*, double>& getMax() const;

	pair<Utilisateur*, double>& getMin() const;

	pair<Utilisateur*, double>& getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;

	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;

	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> paire);

};