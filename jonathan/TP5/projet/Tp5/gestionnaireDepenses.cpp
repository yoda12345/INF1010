#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	for (vector<Depense*>::iterator it = getConteneur().begin(); 
		 it != getConteneur().end(); it++) 
	{
		totalDepenses += (*it)->getMontant();
	}
	return totalDepenses;
};

