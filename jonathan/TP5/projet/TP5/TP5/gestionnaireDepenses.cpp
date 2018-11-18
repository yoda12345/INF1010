#include "gestionnaireDepenses.h"

double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	for (auto it = getConteneur().begin(); 
		 it != getConteneur().end(); it++) 
	{
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
};

vector<Depense*> GestionnaireDepenses::getDepenses() const
{
	return getConteneur();
}