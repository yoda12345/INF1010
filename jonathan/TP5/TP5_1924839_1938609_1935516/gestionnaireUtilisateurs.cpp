/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

vector<double> GestionnaireUtilisateurs ::getComptes() const
{
	vector<double> comptes;

	transform(conteneur_.begin(), 
			  conteneur_.end(), 
			  back_inserter(comptes),
			  [](auto &utilisateur) {return utilisateur.second; });

	return comptes;
}

int GestionnaireUtilisateurs::getNombreUtilisateurs() const
{
	return getNombreElements();
}

void GestionnaireUtilisateurs::ajouter(Utilisateur* utilisateur)
{

	bool doitRenouveler = false;
	bool estAjouter = true;

	// Si le type est Regulier, il faut verifier s'il est dans un groupe
	// Si le type est Premium, il faut verifier l'etat de son abonnement
	if (typeid(*utilisateur) == typeid(UtilisateurRegulier))
	{
		bool estGroupe =
			dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe();

		if (estGroupe == true)
			estAjouter = false;
		else
		{
			dynamic_cast<UtilisateurRegulier*>(utilisateur)
				->setPossedeGroupe(true);
		}
	}
	else
	{
		unsigned int joursRestants =
			dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants();

		if (joursRestants == 0)
		{
			estAjouter = false;
			doitRenouveler = true;
		}
	}

	// Ajout de l'utilisateur ou bien affichage d'un message d'erreur
	if (estAjouter == true)
	{
		GestionnaireGenerique::ajouter(utilisateur);
	}
	else if (doitRenouveler == true)
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " doit renouveler son abonnement Premium";
	}
	else
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " n'est pas souscrit a un abonnement premium,"
			<< " et est deja groupe";
	}

}

map<Utilisateur*, double> GestionnaireUtilisateurs::getUtilisateurs() const
{
	return getConteneur();
}
//
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const
{
	auto it = conteneur_.find(utilisateur);
	if (it != conteneur_.end())
		return true;
	else
		return false;
}
//
//
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant)
{
	double montantReparti = montant / getNombreElements();
	conteneur_[payePar] += (montant - montantReparti);

	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) 
	{
		if (it != conteneur_.find(payePar)) 
		{
			it->second -= montantReparti;
		}
	}
}
//
pair<Utilisateur*, double> GestionnaireUtilisateurs::getElementParIndex(int i) const
{
	auto it = conteneur_.begin();

	for (int j = 0; j < i; j++)
	{
		it++;
	}

	return make_pair(it->first, it->second);
}
//
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const
{
	double max = 0;
	pair<Utilisateur*, double> maxPair;
	for (int i = 0; i < getNombreElements(); i++)
	{
		if (getElementParIndex(i).second > max)
		{
			maxPair = getElementParIndex(i);
			max = maxPair.second;
		}
	}
	return maxPair;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const
{
	double min = 0;
	pair<Utilisateur*, double> minPair;
	for (int i = 0; i < getNombreElements(); i++)
	{
		if (getElementParIndex(i).second < min)
		{
			minPair = getElementParIndex(i);
			min = minPair.second;
		}
	}
	return minPair;
}

// A SURVEILLER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const
{
	auto utilisateurPresent =
		find_if(
			conteneur_.begin(),
			conteneur_.end(),
			bind(equal_to<pair<Utilisateur*, double>>(), 
				_1, 
				pair<Utilisateur*, double>(utilisateur, montant))
			);	pair<Utilisateur*, double> pair = *(++utilisateurPresent);
	return pair.first;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const
{
	vector<pair<Utilisateur*, double>> utilisateursEntre;
	FoncteurIntervalle dansIntervalle(borneInf, borneSup);
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(utilisateursEntre), dansIntervalle);
	return utilisateursEntre;
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> paire)
{
	if (estExistant(paire.first) == true)
		conteneur_[paire.first] = paire.second;

	return *this;
}