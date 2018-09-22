/*
depense.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier d'entête de la classe Depense
*/
#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>


using namespace std;
class Depense {
    public :
    
    // constructeurs par défaut et parametres
    Depense();
    Depense(const string& titre, double montant );
    
    // methodes d'accès
    string getTitre() const;
    double getMontant() const;
    
    //methodes de modifications
    void setTitre(const string& titre);
    void setMontant(double montant);

    //methode d'affichage
    void afficherDepense() const;
    
    private :
        string titre_ = "Inconnu";
        double montant_;

};

#endif
