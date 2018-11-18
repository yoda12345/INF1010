/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/


template<typename T, typename C, typename D, typename FoncteurAjouter> 
class GestionnaireGenerique
{
public:
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i);

protected:
	C conteneur_;
};

template<typename T, typename C, typename D, typename FoncteurAjouter>
C GestionnaireGenerique< T, C, D, FoncteurAjouter>::getConteneur() const
{
	return conteneur_;
};

template<typename T, typename C, typename D, typename FoncteurAjouter>
void GestionnaireGenerique< T, C, D, FoncteurAjouter>::ajouter(T t)
{
	FonteurAjouter foncteurAjouter(conteneur_);
	foncteur(t);
};

template<typename T, typename C, typename D, typename FoncteurAjouter>
int GestionnaireGenerique< T, C, D, FoncteurAjouter>::getNombreElements() const
{
	return conteneur_.size();
};

//template<typename T, typename C, typename D, typename FoncteurAjouter>
//D GestionnaireGenerique< T, C, D, FoncteurAjouter>::getElementParIndex(int i)
//{
//	auto it = conteneur_.begin();
//
//	for (int j = 0; j < i; j++)
//	{
//		it++;
//	}
//
//	return it;
//
//};