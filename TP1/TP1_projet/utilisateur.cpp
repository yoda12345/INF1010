#include "utilisateur.h"

Utilisateur::Utilisateur(): nom_("Aucun"), tailleTabDepense_(5), nombreDepenses_(0), totalDepense_(0.0)
{
	listeDepenses_ = new Depense*[tailleTabDepense_];
}
//Il n'y avait pas moyen de reutiliser le constructeur plus haut?????????????????????????????????
Utilisateur::Utilisateur(string & nom): nom_(nom), tailleTabDepense_(5), nombreDepenses_(0), totalDepense_(0.0)
{
	listeDepenses_ = new Depense*[tailleTabDepense_];
}

Utilisateur::~Utilisateur()
{
	delete[] listeDepenses_;
}

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

void Utilisateur::setNom(string & nom)
{
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense * uneDepense)
{
	if (tailleTabDepense_ == 0)
		listeDepenses_ = new Depense*[++tailleTabDepense_];
	else if (nombreDepenses_ >= tailleTabDepense_)
	{
		Depense ** listeDepensesTemporaire = listeDepenses_;
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

void Utilisateur::calculerTotal()
{
	totalDepense_ = 0;
	for (unsigned i = 0; i < nombreDepenses_; i++)
		totalDepense_ = totalDepense_ + listeDepenses_[i]->getMontant();
}

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
