
#ifndef G_DEPENSES_H
#define G_DEPENSES_H

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <algorithm>
#include <vector>

#include <functional>

class GestionnaireDepenses:  
	public  GestionnaireGenerique< Depense*, 
								   vector<Depense*>, 
								   Depense*, 
								   AjouterDepense >
{
public:
	double getTotalDepenses() const;
	vector<Depense*> getDepenses() const;
};

#endif