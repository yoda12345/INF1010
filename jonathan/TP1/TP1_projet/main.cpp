/*
main.cpp
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier source d'un programme permetettant d'équilibrer les dépenses au sein d'un groupe
Les réponses aux questions sont dans le fichier texte
*/
#include <iostream>
#include "groupe.h"

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl 
		 << " *****************************************";
    // Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nomGroupe = "Ete2018";
	Groupe groupe(nomGroupe, 6, 4);
    
    // Creer 5 utlisateurs.
	string nomUtilisateur1 = "Utilisateur1";
	string nomUtilisateur2 = "Utilisateur2";
	string nomUtilisateur3 = "Utilisateur3";
	string nomUtilisateur4 = "Utilisateur4";
	string nomUtilisateur5 = "Utilisateur5";


	Utilisateur* utilisateur1 = new Utilisateur(nomUtilisateur1);
	Utilisateur* utilisateur2 = new Utilisateur(nomUtilisateur2);
	Utilisateur* utilisateur3 = new Utilisateur(nomUtilisateur3);
	Utilisateur* utilisateur4 = new Utilisateur(nomUtilisateur4);
	Utilisateur* utilisateur5 = new Utilisateur(nomUtilisateur5);

    //Creer 7 dépenses.
	string nomDepense1 = "Depense1";
	string nomDepense2 = "Depense2";
	string nomDepense3 = "Depense3";
	string nomDepense4 = "Depense4";
	string nomDepense5 = "Depense5";
	string nomDepense6 = "Depense6";
	string nomDepense7 = "Depense7";

	Depense* depense1 = new Depense(nomDepense1, 8.8);
	Depense* depense2 = new Depense(nomDepense2, 2.2);
	Depense* depense3 = new Depense(nomDepense3, 3.3);
	Depense* depense4 = new Depense(nomDepense4, 4.4);
	Depense* depense5 = new Depense(nomDepense5, 5.5);
	Depense* depense6 = new Depense(nomDepense6, 6.6);
	Depense* depense7 = new Depense(nomDepense7, 7.7);

    //ajouter les utilisateurs au groupe
	groupe.ajouterUtilisateur(utilisateur1);
	groupe.ajouterUtilisateur(utilisateur2);
	groupe.ajouterUtilisateur(utilisateur3);
	groupe.ajouterUtilisateur(utilisateur4);
	groupe.ajouterUtilisateur(utilisateur5);

    //ajouter les depenses au groupe
	groupe.ajouterDepense(depense1, utilisateur1);
	groupe.ajouterDepense(depense2, utilisateur2);
	groupe.ajouterDepense(depense3, utilisateur3);
	groupe.ajouterDepense(depense4, utilisateur4);
	groupe.ajouterDepense(depense5, utilisateur1);
	groupe.ajouterDepense(depense6, utilisateur2);
	groupe.ajouterDepense(depense7, utilisateur3);
    
    //calculer le total du grouoe et de chaque utilisateur
	groupe.calculerTotalDepenses();

    //Afficher  le groupe
	groupe.afficherGroupe();
    
    //Equilibrer les comptes
	groupe.equilibrerComptes();

    //Afficher le groupe
	groupe.afficherGroupe();
   
    //terminer le programme correctement
	delete utilisateur1;
	delete utilisateur2;
	delete utilisateur3;
	delete utilisateur4;
	delete utilisateur5;

	delete depense1;
	delete depense2;
	delete depense3;
	delete depense4;
	delete depense5;
	delete depense6;
	delete depense7;


}
