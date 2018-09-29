/*
groupe.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier d'entête de la classe Groupe

*/
#ifndef GROUPE_H
#define GROUPE_H


#include "transfert.h"
#include <string>
using namespace std;

class Groupe{
    public :
    //Constructeurs
    Groupe();
    Groupe(const string& nom, unsigned int tailleTabDepenses = 10, 
			unsigned int tailleTabUtilisateurs = 5);
    
    //Destructeur
    ~Groupe();
    
    //methode d'acces
    string getNom() const;
    unsigned int getNombreDepenses() const;
    double getTotal() const;
    
    //Methodes de modification
    void setNom(const string& nom);
    
    //Methodes d'ajout
    void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
    void ajouterUtilisateur(Utilisateur* unUtilisateur);
    
    //Méthode de calcul
    void calculerTotalDepenses();
    void equilibrerComptes();
    
    //methode d'affichage
    void afficherGroupe() const;
    
    private :
        string nom_ = "Inconnu";
        double totalDepenses_;
        Utilisateur** listeUtilisateurs_;
        unsigned int nombreDepenses_;
        unsigned int nombreUtilisateurs_;
        unsigned int tailleTabUtilisateurs_;
        unsigned int tailleTabDepenses_;
        Depense** listeDepenses_;
        double* comptes_;
        Transfert** listeTransferts_;
        unsigned int nombreTrensferts_; 
    
};

#endif 
