/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
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
// GestionnaireUtilisateurs
// Description: class permettant de gérer un map d'utilisateurs
class GestionnaireUtilisateurs :
	public  GestionnaireGenerique <Utilisateur*,
								   map<Utilisateur*, double>,
								   pair<Utilisateur*, double>,
								   AjouterUtilisateur>
{
public:
	// Methode d'acces
	vector<double> getComptes() const;
	int getNombreUtilisateurs() const;
	map<Utilisateur*, double> getUtilisateurs() const;
	pair<Utilisateur*, double>& getMax() const;
	pair<Utilisateur*, double>& getMin() const;
	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, 
									   double montant) const;

	vector<pair<Utilisateur*, double>> 
		getUtilisateursEntre(double borneInf, double borneSup) const;

	// Methode d'ajout
	virtual void ajouter(Utilisateur* utilisateur);

	// Methodes de modification
	void mettreAJourComptes(Utilisateur* payePar, double montant);
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> paire);
	
	// Methode de test
	bool estExistant(Utilisateur* utilisateur) const;
};