/*
utilisateur.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier d'entête de la classe Utilisateur
*/
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
    public :
    // constructeurs
    Utilisateur();
    Utilisateur(const string& nom);
    
    //Destructeur
    ~Utilisateur(); 
    
    //Methodes d'accès
    string getNom() const;
    unsigned int getNombreDepense() const;
    double getTotal() const;
  
    //Methode de modification
    void setNom(const string& nom);
    
    // Methode ajout de dépense
    void ajouterDepense(Depense* uneDepense);
    
    //Methode de calcul total
    void calculerTotal();
    
    //Mathode d'affichage
    void afficherUtilisateur() const;
    
    private :
        string nom_ = "Inconnu";
        unsigned int tailleTabDepense_;
        unsigned int nombreDepenses_;
        double totalDepense_;
        Depense** listeDepenses_;
    
    
};
#endif /* utilisateur_hpp */
