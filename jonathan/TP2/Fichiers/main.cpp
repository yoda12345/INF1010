/******************************************************************************
main.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 29 septembre 2018
Date de modification: 30 septembre 2018
Description fichier:
Fichier source d'un programme permetettant d'équilibrer les dépenses au sein d'un groupe
Les réponses aux questions sont dans le fichier texte

******************************************************************************/

#include <iostream>
#include "depense.h"
#include "utilisateur.h"
#include "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	cout << "\t \tBienvenue sur PolyCount " << endl 
		 << " *****************************************************" << endl;

	// Initialisation des depenses
	Depense* d1 = new Depense("d1", 12, "IGA");
	Depense* d2 = new Depense("d2", 11, "Provigo");
	Depense* d3 = new Depense("d3", 5, "Jean-drapeau");
	Depense* d4 = new Depense("d4", 23, "Vieux port");
	Depense* d5 = new Depense("d5", 17, "Metro");
	Depense* d6 = new Depense("d6", 29, "Desjardins");
	Depense* d7 = new Depense(*d5);
	d7->setNom("d7");
	d7->setLieu("Maisonnee");

	Depense* d8 = new Depense();
	*d8 = *d1;
	d8->setNom("d8");
	d8->setLieu("Banque scotia");

	// Initialisation des utilisateurs
	Utilisateur* u1 = new Utilisateur("Martin");
	Utilisateur* u2 = new Utilisateur("Franklin");
	Utilisateur* u3 = new Utilisateur("Geraldine");
	Utilisateur* u4 = new Utilisateur("Bernard");
	Utilisateur* u5 = new Utilisateur();
	*u5 = *u1;
	u5->setNom("Christian");

	// Initialisation du groupe
	Groupe* groupe = new Groupe("vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((*groupe += u1) += u2) += u3) += u4) += u5;

	groupe->ajouterDepense(d1, u1).ajouterDepense(d2, u1)
		   .ajouterDepense(d3, u2).ajouterDepense(d4, u3)
		   .ajouterDepense(d5, u4).ajouterDepense(d6, u5)
		   .ajouterDepense(d7, u3).ajouterDepense(d8, u4);

	cout << *groupe;

	// Equilibrage des comptes
	groupe->equilibrerComptes();
	cout << *groupe;

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;
	delete d8;
	
	delete u1;
	delete u2;
	delete u3;
	delete u4;
	delete u5;

	delete groupe;

	return 0;
}
