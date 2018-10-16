/******************************************************************************
utilisateurRegulier.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe UtilisateurRegulier

******************************************************************************/
#include "utilisateurRegulier.h"

// Constructeurs 
UtilisateurRegulier::UtilisateurRegulier(const string & nom) :
	Utilisateur(nom), estGroupe_(false)
{
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur), 
	estGroupe_(static_cast< UtilisateurRegulier >(utilisateur).estGroupe_)
{
}

// Methodes d'acces
bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

// Methodes de modifications
void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur)
{
	*static_cast< Utilisateur* >(this) = utilisateur;
	estGroupe_ = static_cast< UtilisateurRegulier* >(utilisateur)->estGroupe_;
	return *this;
}

// Methodes d'affichage
ostream & operator<<(ostream & os, const UtilisateurRegulier& utilisateur)
{
	os << "\n\n\t\tUtilisateur : " << utilisateur.getNom() << " (Regulier)";

	if (utilisateur.estGroupe_ == true)
		os << " est dans le groupe et ";
	else
		os << " n'est pas dans un groupe et ";

	return os << static_cast<Utilisateur>(utilisateur);
}
