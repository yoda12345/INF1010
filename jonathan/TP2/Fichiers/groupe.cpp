/******************************************************************************
groupe.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier source de la classe Groupe

******************************************************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() 
	: nom_("")
{
}

Groupe::Groupe(const string& nom) 
	: nom_(nom)
{
}


Groupe::~Groupe() 
{
	for (int i = 0; i < transferts_.size(); i++) 
	{
		delete transferts_[i];
		transferts_[i] = nullptr;
	}
}


// Methodes d'acces
string Groupe::getNom() const 
{
	return nom_;
}

size_t Groupe::getNombreDepenses() const 
{
	return depenses_.size();
}

double Groupe::getTotalDepenses() const 
{
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) 
	{
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) 
{
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) 
{

	depenses_.push_back(depense);
	(*utilisateur) += depense;
	return *this;

}

Groupe& Groupe::operator+=(Utilisateur* unUtilisateur)
{
	utilisateurs_.push_back(unUtilisateur);
	return *this;
}


//Méthodes de calcul
void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back(((utilisateurs_[i]->getTotalDepenses()) - moyenne));
	}
}

void Groupe::equilibrerComptes() 
{
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0.0;
		double min = 0.0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) 
		{
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_.push_back(new Transfert(-min, 
												utilisateurs_[indexMin], 
												utilisateurs_[indexMax]));

			comptes_[indexMax] += min;
			comptes_[indexMin] = 0.0;
		}
		else {
			transferts_.push_back(new Transfert(max,
												utilisateurs_[indexMin],
												utilisateurs_[indexMax]));
			comptes_[indexMax] = 0.0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) 
		{
			count++;
		}
		if (count >= utilisateurs_.size() - 1) 
		{
			calcul = false;
		}
	}
}


// Methode d'affichage
ostream& operator<<(ostream& sortie, const Groupe& groupe)
{
	sortie << "L'evenement " << groupe.nom_ << " a coute un total de " 
		   << groupe.getTotalDepenses() << " :  \n\n";

	for (int i = 0; i < groupe.utilisateurs_.size(); i++) 
	{
		sortie << *(groupe.utilisateurs_[i]);
	}
	sortie << endl;

	if (groupe.transferts_.size() != 0) 
	{
		sortie << "Les transferts suivants ont"
			   << " ete realiser pour equilibrer  : " << endl;

		for (int i = 0; i < groupe.transferts_.size(); i++) 
		{
			sortie << "\t" << *(groupe.transferts_[i]);
		}
	}
	else {
		sortie << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	sortie << endl;
	return sortie;
}
