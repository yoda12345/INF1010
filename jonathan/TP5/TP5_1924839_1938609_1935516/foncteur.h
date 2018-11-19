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
		AjouterDepense(vector<Depense*>& conteneurDepenses) :
			depenses_(conteneurDepenses)
		{
		};

		vector<Depense*>& operator()(Depense* depense)
		{
			depenses_.push_back(depense);
			return depenses_;
		};
	
	private:
		vector<Depense*>& depenses_;
};

//AjouterDepense::AjouterDepense(vector<Depense*>& conteneurDepenses) :
//	depenses_(conteneurDepenses)
//{
//};

//vector<Depense*>& AjouterDepense::operator()(Depense* depense)
//{
//	depenses_.push_back(depense);
//	return depenses_;
//};


class AjouterUtilisateur
{
	public :
		AjouterUtilisateur(map<Utilisateur*, double>& conteneurUtilisateur) :
			utilisateurs_(conteneurUtilisateur)
		{
		};

		map<Utilisateur*, double>& operator()(Utilisateur* utilisateur)
		{
			utilisateurs_.insert(pair<Utilisateur*, double>(utilisateur, 0));
			return utilisateurs_;
		};

	private :
		map<Utilisateur*, double>& utilisateurs_;
};

//AjouterUtilisateur::AjouterUtilisateur(map<Utilisateur*, double>& conteneurUtilisateur) :
//	utilisateurs_(conteneurUtilisateur)
//{
//}
//
//map<Utilisateur*, double>& AjouterUtilisateur::operator()(Utilisateur* utilisateur)
//{
//	utilisateurs_.insert(pair<Utilisateur*, double>(utilisateur, 0));
//	return utilisateurs_;
//};


class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup):
		borneInf_(borneInf), borneSup_(borneSup)
	{
	};


	bool operator()(pair<Utilisateur*, double> paire)
	{
		if ((paire.second >= borneInf_) && (paire.second <= borneSup_))
			return true;
		else
			return false;
	};

private:
	double borneInf_, borneSup_;
};
//
//FoncteurIntervalle::FoncteurIntervalle(double borneInf, double borneSup) :
//	borneInf_(borneInf), borneSup_(borneSup)
//{
//};
//
//bool FoncteurIntervalle::operator()(pair<Utilisateur*, double> paire)
//{
//	if ((paire.second > borneInf_) && (paire.second < borneSup_))
//		return true;
//	else
//		return false;
//};

#endif