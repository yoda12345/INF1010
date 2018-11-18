/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/


template<class T, class C, class D, class FoncteurAjouter>
class GestionnaireGenerique
{
public:
	template<class T, class C, class D, class FoncteurAjouter>
	C getConteneur() const;

	template<class T, class C, class D, class FoncteurAjouter>
	void ajouter(T t);

	template<class T, class C, class D, class FoncteurAjouter>
	int getNombreElements() const;

	D getElementParIndex(int i);

protected:
	C conteneur_;
};

template<class T, class C, class D, class FoncteurAjouter>
C GestionnaireGenerique< T, C, D, FoncteurAjouter>::getConteneur() const
{
	return conteneur_;
};

template<class T, class C, class D, class FoncteurAjouter>
void GestionnaireGenerique< T, C, D, FoncteurAjouter>::ajouter(T t)
{
	FoncteurAjouter foncteur(conteneur_);
	foncteur(t);
};

template<class T, class C, class D, class FoncteurAjouter>
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