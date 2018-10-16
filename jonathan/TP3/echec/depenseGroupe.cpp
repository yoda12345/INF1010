#include "depenseGroupe.h"

//constructeur
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) :
	Depense(nom, montant, lieu), nombreParticipants_(0)
{
	Depense::setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) :
	Depense(depense), nombreParticipants_(depense.nombreParticipants_)
{
}

//getters 
unsigned int DepenseGroupe:: getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ == 0)
		return 0;
	else
		return ( getMontant() / nombreParticipants_);
}

//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}

//surcharge 
ostream & operator<<(ostream & os, const DepenseGroupe& depense)
{
	return os << "Depense de groupe :\t" << static_cast<Depense>(depense)
			  << "fait par : " << depense.nombreParticipants_ << " soit : "
			  << depense.getMontant() << " par personne.";
}
