/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""), tailleTabDepense_(5), nombreDepenses_(0), depenses_(new Depense*[tailleTabDepense_]) {
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom), tailleTabDepense_(5), nombreDepenses_(0), depenses_(new Depense*[tailleTabDepense_]) {
}

//Destructeur
Utilisateur::~Utilisateur() {
	delete[] depenses_;
	depenses_ = nullptr;
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < nombreDepenses_; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense* depense) {
	if (nombreDepenses_ == tailleTabDepense_) {
		tailleTabDepense_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}
	depenses_[nombreDepenses_++] = depense;
}

// Methode d'affichage
void Utilisateur::afficherUtilisateur() const {

	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		cout << "\t\t";
		depenses_[i]->afficherDepense();
	}

}
