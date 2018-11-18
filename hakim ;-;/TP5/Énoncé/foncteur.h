/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include <vector>
#include <map>

/*
	Foncteur AjouterDepense

	Méthode :
	Constructeur
	vector<Depense*>& operator()();

	Attribut :
	vector<Depense*> conteneur_;
*/

class AjouterDepense {
public:
	AjouterDepense(const vector<Depense*>& conteneur);
	vector<Depense*>& operator()(Depense* uneDepense);
private:
	vector<Depense*> conteneur_;
};

AjouterDepense::AjouterDepense(const vector<Depense*>& conteneur): conteneur_(conteneur)
{
}

vector<Depense*>& AjouterDepense::operator()(Depense* uneDepense) {
	conteneur_.push_back(uneDepense);
	return conteneur_;
}

/*
Foncteur AjouterUtilisateur

Méthode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/

class AjouterUtilisateur {
public:
	AjouterUtilisateur(const map<Utilisateur*, double>& conteneur);
	map<Utilisateur*, double>& operator()(Utilisateur* unUtilisateur);

private:
	map<Utilisateur*, double> conteneur_;
};

AjouterUtilisateur::AjouterUtilisateur(const map<Utilisateur*, double>& conteneur) : conteneur_(conteneur)
{
}

map<Utilisateur*, double>& AjouterUtilisateur::operator()(Utilisateur* unUtilisateur) {
	conteneur_.insert(pair<Utilisateur*, double>(unUtilisateur, 0.0));
	return conteneur_;
}

/*
Foncteur FoncteurIntervalle

Méthode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/

class FoncteurIntervalle {
public:
	FoncteurIntervalle(const double& borneInf, const double& borneSup);
	bool operator()(const pair<Utilisateur*, double>& unePaire);

private:
	double borneInf_, borneSup_;
};

FoncteurIntervalle::FoncteurIntervalle(const double& borneInf, const double& borneSup): borneInf_(borneInf), borneSup_(borneSup)
{
}

inline bool FoncteurIntervalle::operator()(const pair<Utilisateur*, double>& unePaire)
{
	if (unePaire.second >= borneInf_ && unePaire.second <= borneSup_)
	{
		return true;
	}
	else
	{
		return false;
	}
}
