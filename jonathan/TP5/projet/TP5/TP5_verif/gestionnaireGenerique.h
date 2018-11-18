/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 18 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609) & (1935516)
*******************************************/

#ifndef Gestionnaire_Generique_H
#define Gestionnaire_Generique_H


// GestionnaireGenerique
// Description: class générique abstraite permettant de gérer un conteneur
template<typename T, typename C, typename D, typename FoncteurAjouter>
class GestionnaireGenerique
{
public:
	// Methode d'accès
	C getConteneur() const;
	int getNombreElements() const;
	D getElementParIndex(int i) const;

	// Methode d'ajout
	virtual void ajouter(T t) = 0;

protected:
	C conteneur_;
};

//*************************** Methode d'accès ***************************
template<typename T, typename C, typename D, typename FoncteurAjouter>
C  GestionnaireGenerique< T, C, D, FoncteurAjouter>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
int GestionnaireGenerique< T, C, D, FoncteurAjouter>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
D GestionnaireGenerique< T, C, D, FoncteurAjouter>::
	getElementParIndex(int i) const
{
	auto it = conteneur_.begin();

	for (int j = 0; j < i; j++)
	{
		it++;
	}

	D output = *it;

	return output;

}

// *************************** Methode d'ajout ***************************
template<typename T, typename C, typename D, typename FoncteurAjouter>
void GestionnaireGenerique< T, C, D, FoncteurAjouter>::ajouter(T t)
{
	FoncteurAjouter foncteur(conteneur_);
	foncteur(t);
}

#endif