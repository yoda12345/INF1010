#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom) :
	Utilisateur(nom, Regulier), estGroupe_(false)
{
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur.getNom(), utilisateur.getType())
{
	if (utilisateur.getType() == Regulier)
	{
		estGroupe_ = static_cast<UtilisateurRegulier>(utilisateur).estGroupe();
	}
	
	ajouterInteret(utilisateur.getInteret());

	for (size_t i = 0; i < utilisateur.getNombreDepenses(); i++)
	{
		copierDepense(utilisateur.getDepenses()[i]);
	}
	calculerTotalDepenses();
}

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}



