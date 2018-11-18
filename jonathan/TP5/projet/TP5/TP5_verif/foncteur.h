/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/
#ifndef FONCTEUR_H
#define FONCTEUR_H

#include <map>
#include <vector>

// AjouerDepense
// Description: Foncteur permettant d'ajouter une depense 
//				a un vecteur de depenses
// Attributs: 
//		depenses_ : 
//			Reference au conteneur de depenses pass� 
//			par reference dans le constructeur
// Methodes:
//		AjouterDepenses(vector<Depense*>& conteneurDepenses) :
//			Constructeur par parametre qui initialise depenses_ par reference
//
//		operator() : 
//			Surcharge de l'operateur qui permet d'ajouter une depenses 
//			au conteneur r�f�renc� par l'attribut depenses_,
//			il est possible de l'appeler en cascade
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


// AjouerUtilisateur
// Description: Foncteur permettant d'ajouter un utilisateur a 
//				un map d'utilisateurs associ�s avec leur compte
// Attributs: 
//		utilisateurs_ : 
//			Reference au conteneur d'utilisateur pass� 
//			par reference dans le constructeur
// Methodes:
//		AjouterDepenses(map<Utilisateur*, double>& conteneurUtilisateur)  :
//			Constructeur par parametre qui initialise 
//			utilisateurs_ par reference
//
//		operator() : 
//			Surcharge de l'operateur qui permet d'ajouter un utilisateur 
//			au conteneur r�f�renc� par l'attribut utilisateurs_, 
//			il est possible de l'appeler en cascade
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


// FoncteurIntervalle
// Description: Foncteur permettant de verifier 
//				si une valeur se trouve dans un intervalle
// Attributs: 
//		borneInf_ : 
//			Repr�sente la borne inf�rieur de l'intervalle
//		borneSup_ : 
//			Repr�sente la borne sup�rieur de l'intervalle
// Methodes:
//		FoncteurIntervalle(double borneInf, double borneSup)  :
//			Constructeur par parametre qui initialise borneInf_ et borneSup_
//
//		operator() : 
//			Surcharge de l'operateur qui permet de v�rifier 
//			si une valeur double se situe dans l'intervalle
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

#endif