/******************************************************************************
utilisateurPremium.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 16 octobre 2018
Date de modification: 16 octobre 2018
Description fichier:
Fichier source de la classe UtilisateurPremium

******************************************************************************/
#include "utilisateurPremium.h"

// Constructeurs 
UtilisateurPremium::UtilisateurPremium(const string& nom) :
	Utilisateur(nom, Premium), taux_(TAUX_REGULIER), joursRestants_(30)
{
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur), 
	taux_(static_cast<UtilisateurPremium>(utilisateur).taux_), 
	joursRestants_(static_cast<UtilisateurPremium>(utilisateur).joursRestants_)
{
}

// Methodes d'acces
unsigned int UtilisateurPremium::getJoursRestants() const
{
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const
{
	return taux_;
}

// Methodes de modification
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

UtilisateurPremium& UtilisateurPremium::operator=(Utilisateur* utilisateur)
{
	if (this != utilisateur)
	{
		*static_cast<Utilisateur*>(this) = utilisateur;
		taux_ = static_cast<UtilisateurPremium*>(utilisateur)->taux_;
		
		joursRestants_ = 
			static_cast<UtilisateurPremium*>(utilisateur)->joursRestants_;
	}
	return *this;
}

// Methodes de calcul
void UtilisateurPremium::calculerTaux()
{
	if (getNombreDepenses() < 10)
		taux_ = TAUX_REGULIER - (0.01 * (getNombreDepenses() / 2));
	else
		taux_ = 0.0;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const UtilisateurPremium& utilisateur)
{
	return os << "\n\n\t\tUtilisateur : " << utilisateur.getNom() 
			  << " (Prenium)" << static_cast<Utilisateur>(utilisateur)
			  << "\n\n\t Le taux final est de : " << utilisateur.taux_
			  << "\n\t Il reste " << utilisateur.joursRestants_ 
			  << " jours a son abonnement.\n";
}
