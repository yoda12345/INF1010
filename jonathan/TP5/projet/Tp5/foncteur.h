/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#ifndef FONCTEUR_H
#define FONCTEUR_H

#include <map>
#include <vector>

class AjouterDepense
{
	public:
		AjouterDepense(vector<Depense*>& conteneurDepenses);
		vector<Depense*>& operator()(Depense* depense);
	
	private:
		vector<Depense*>& conteneur_;
};

AjouterDepense::AjouterDepense(vector<Depense*>& conteneurDepenses) :
	conteneur_(conteneurDepenses)
{
};

vector<Depense*>& AjouterDepense::operator()(Depense* depense)
{
	conteneur_.push_back(depense);
	return conteneur_;
};


class AjouterUtilisateur
{
	public :
		AjouterUtilisateur(map<Utilisateur*, double>& conteneurUtilisateur);
		map<Utilisateur*, double>& operator()(Utilisateur* utilisateur);

	private :
		map<Utilisateur*, double>& conteneur_;
};

AjouterUtilisateur::AjouterUtilisateur(map<Utilisateur*, double>& conteneurUtilisateur) :
	conteneur_(conteneurUtilisateur)
{
}

map<Utilisateur*, double>& AjouterUtilisateur::operator()(Utilisateur* utilisateur)
{
	conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0));
	return conteneur_;
};


class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup);
	bool operator()(pair<Utilisateur*, double> pair);

private:
	double borneInf_, borneSup_;
};

FoncteurIntervalle::FoncteurIntervalle(double borneInf, double borneSup) :
	borneInf_(borneInf), borneSup_(borneSup)
{
};

bool FoncteurIntervalle::operator()(pair<Utilisateur*, double> pair)
{
	if ((pair.second > borneInf_) && (pair.second < borneSup_))
		return true;
	else
		return false;
};

#endif