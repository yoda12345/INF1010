/*
utilisateur.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier source de la classe Utilisateur

*/
#include "utilisateur.h"

// Constructeurs

Utilisateur::Utilisateur(): nom_("Inconnu"), tailleTabDepense_(5),
							nombreDepenses_(0), totalDepense_(0.0)
{
	listeDepenses_ = new Depense*[tailleTabDepense_];
}


Utilisateur::Utilisateur(const string& nom): nom_(nom), tailleTabDepense_(5),
									   nombreDepenses_(0), totalDepense_(0.0)
{
	listeDepenses_ = new Depense*[tailleTabDepense_];
}

//Destructeur

Utilisateur::~Utilisateur()
{
	delete[] listeDepenses_;
	nombreDepenses_ = 0;
	listeDepenses_ = nullptr;
}


// Méthodes d'accès

string Utilisateur::getNom() const
{
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const
{
	return nombreDepenses_;
}

double Utilisateur::getTotal() const
{
	return totalDepense_;
}

//Methode de modfication

void Utilisateur::setNom(const string & nom)
{
	nom_ = nom;
}

//Methode d'ajout

void Utilisateur::ajouterDepense(Depense * uneDepense)
{
	if (tailleTabDepense_ == 0)
		listeDepenses_ = new Depense*[++tailleTabDepense_];
	else if (nombreDepenses_ >= tailleTabDepense_)
	{
		Depense** listeDepensesTemporaire = listeDepenses_;
		listeDepenses_ = new Depense*[tailleTabDepense_ * 2];

		for (unsigned i = 0; i < tailleTabDepense_; i++)
		{
			listeDepenses_[i] = listeDepensesTemporaire[i];
			delete listeDepensesTemporaire[i];
		}

		delete[] listeDepensesTemporaire;
		tailleTabDepense_ *= 2;
	}

	listeDepenses_[nombreDepenses_++] = uneDepense;

}

//Methode de calcul du total

void Utilisateur::calculerTotal()
{
	totalDepense_ = 0.0;
	for (unsigned i = 0; i < nombreDepenses_; i++)
		totalDepense_ = totalDepense_ + listeDepenses_[i]->getMontant();
}

//Methode d'affichage

void Utilisateur::afficherUtilisateur() const
{
	cout << "\tUtilisateur: " << nom_ << "\n"
		<< "\tTotal des depenses: " << totalDepense_ << " $\n"
		<< "\tListe des depenses:\n";

	for (unsigned i = 0; i < nombreDepenses_; i++)
	{
		listeDepenses_[i]->afficherDepense();
		cout << "\n\n";
	}
}
