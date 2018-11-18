/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

/*
	class GestionnaireGenerique
	
	Méthodes :
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

	Attributs :
	C conteneur_;
*/

template<typename T, typename C, typename D, typename Foncteur>
class GestionnaireGenerique {
public:
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
	C conteneur_;
};

template<typename T, typename C, typename D, typename Foncteur>
inline C GestionnaireGenerique<T, C, D, Foncteur>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C, typename D, typename Foncteur>
inline void GestionnaireGenerique<T, C, D, Foncteur>::ajouter(T t)
{
	Foncteur foncteurAjouter(conteneur_);
	foncteurAjouter(t);
}

template<typename T, typename C, typename D, typename Foncteur>
inline int GestionnaireGenerique<T, C, D, Foncteur>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename T, typename C, typename D, typename Foncteur>
inline D GestionnaireGenerique<T, C, D, Foncteur>::getElementParIndex(int i) const
{
	auto begIt = conteneur_.begin();
	
	for (int j = 0; j < i; j++)
	{
		begIt++;
	}
	
	auto endIt = conteneur_.end();
	
	if (begIt >= endIt) //If out of range
	{
		return NULL;
	}
	else
	{
		return begIt;
	}
}
