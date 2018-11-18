/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#ifndef G_H
#define G_H

template<typename T, typename C, typename D, typename FoncteurAjouter>
class GestionnaireGenerique
{
public:
	C getConteneur() const;
	virtual void ajouter(T t) = 0;
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
	C conteneur_;
};

template<typename T, typename C, typename D, typename FoncteurAjouter>
C  GestionnaireGenerique< T, C, D, FoncteurAjouter>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
void GestionnaireGenerique< T, C, D, FoncteurAjouter>::ajouter(T t)
{
	FoncteurAjouter foncteur(conteneur_);
	foncteur(t);
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
int  GestionnaireGenerique< T, C, D, FoncteurAjouter>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
D GestionnaireGenerique< T, C, D, FoncteurAjouter>::getElementParIndex(int i) const
{
	auto it = conteneur_.begin();

	for (int j = 0; j < i; j++)
	{
		it++;
	}

	return it;

};

#endif