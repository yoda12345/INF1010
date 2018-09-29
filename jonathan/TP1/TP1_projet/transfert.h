/*
transfert.h
Créé par: Jonathan Laroche (1924839) et Hakim Payman (1938609)
Date de création: 14 septembre 2018
Date de modification: 21 septembre 2018
Description fichier:
Fichier d'entête de la classe Transfert

*/
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>

#include <stdio.h>

class Transfert {
    public :
    
    // Constructeurs
    Transfert();
    Transfert(double montant, Utilisateur* de, Utilisateur* pour);
    
    // Méthodes d'accès
    
    Utilisateur* getDonneur() const;
    Utilisateur* getReceveur() const;
    double getMontant() const;
    
	//Methodes de modifications
    void setDonneur(Utilisateur* donneur);
    void setMontant(double montant);
    void setReceveur(Utilisateur* receveur);

	//Méthode d'affichage
    void afficherTransfert() const;
    
    private :
        double montant_;
        Utilisateur* donneur_;
        Utilisateur* receveur_;
    

};
#endif
