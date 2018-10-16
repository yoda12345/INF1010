/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type) :
	nom_(nom), type_(type), interet_(0), totalDepense_(0)
{
}

//destructeur 

// Methodes d'acces



string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() 
{
	totalDepense_ = 0;
	for (size_t i = 0; i < depenses_.size(); i++)
	{
		if (depenses_[i]->getType == groupe)
			totalDepense_ += static_cast< DepenseGroupe* >(depenses_[i])->getMontantPersonnel();
		else
			totalDepense_ += depenses_[i]->getMontant();
	}
}

Utilisateur& Utilisateur::operator=(Utilisateur* utilisateur)
{
	nom_ = utilisateur->nom_;
	depenses_ = utilisateur->depenses_;

	if (depense->getType() == groupe)
		*this += new DepenseGroupe(*depense);
	else
		*this += new Depense(*depense);
	return *this;
}


void Utilisateur::ajouterInteret(double montant) 
{
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) 
{
	this->depenses_.push_back(depense);
	return *this;
}

void Utilisateur::setType(const TypeUtilisateur& type)
{
	type_ = type;
}

void Utilisateur::copierDepense(Depense* depense)
{
	if (depense->getType() == groupe)
		*this += new DepenseGroupe(*depense);
	else
		*this += new Depense(*depense);
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur : " << utilisateur.nom_
	   << " a depense pour un total de : "
	   << utilisateur.getTotalDepenses() << ", Polycount prend en interet : " 
	   << utilisateur.getInteret() << endl << "\t Liste de depenses : " << endl;

	for (int i = 0; i < utilisateur.depenses_.size(); i++)
	{
		os << "\t\t" << *(utilisateur.depenses_[i]);       // FORTE CHANCE DE DEVOIR CHANCER LA SURCHANGE EN VIRTUALLLLL!!!!!!!!
	}
	return os;
}
