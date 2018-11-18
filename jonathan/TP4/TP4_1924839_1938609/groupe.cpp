/********************************************
* Titre: Travail pratique #4 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Jonathan Laroche (1924839) & Hakim Payman (1938609)
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() 
{
	nom_ = "";
}

Groupe::Groupe(const string& nom) : nom_(nom) 
{
}

Groupe::Groupe(const Groupe& groupe) : 
	nom_(groupe.nom_),
	utilisateurs_(groupe.utilisateurs_),
	comptes_(groupe.comptes_)
{
	// Les depenses et les transferts sont composites
	// Il faut donc eviter de faire un shallow copy
	for (size_t i = 0; i < groupe.depenses_.size(); i++)
		depenses_.push_back(new Depense(*groupe.depenses_[i]));

	for (size_t i = 0; i < groupe.transferts_.size(); i++)
	{
		if (typeid(*groupe.depenses_[i]) == typeid(TransfertInterac))
		{
			transferts_.push_back(new TransfertInterac(
				*(dynamic_cast<TransfertInterac*>(groupe.transferts_[i]))));
		}
		else
		{
			transferts_.push_back(new TransfertPaypal(
				*(dynamic_cast<TransfertPaypal*>(groupe.transferts_[i]))));
		}
	}
}
//Destructeur
Groupe::~Groupe()
{
	for (size_t i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
	}

	for (size_t i = 0; i < transferts_.size(); i++)
	{
		delete transferts_[i];
	}
}

// Methodes d'acces
string Groupe::getNom() const 
{
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

vector<double> Groupe::getComptes() const
{
	return comptes_;
}

double Groupe::getTotalDepenses() const 
{
	double totalDepenses = 0;
	for (size_t i = 0; i < depenses_.size(); i++) {
		totalDepenses += depenses_[i]->getMontant();
	}
	return totalDepenses;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) 
{
	nom_ = nom;
}

Groupe& Groupe::operator=(const Groupe& groupe)
{
	if (this != &groupe)
	{
		nom_ = groupe.nom_;
		utilisateurs_ = groupe.utilisateurs_;
		comptes_ = groupe.comptes_;

		// Destruction des anciennes depenses
		for (size_t i = 0; i < depenses_.size(); i++)
		{
			delete depenses_.back();
			depenses_.pop_back();
		}

		// Ajout des depenses copies
		for (size_t i = 0; i < groupe.depenses_.size(); i++)
			depenses_.push_back(new Depense(*groupe.depenses_[i]));

		// Destruction des anciens transferts
		for (size_t i = 0; i < transferts_.size(); i++)
		{
			delete transferts_.back();
			transferts_.pop_back();
		}

		// Ajout des transferts copies
		for (size_t i = 0; i < groupe.transferts_.size(); i++)
		{
			if (typeid(*groupe.depenses_[i]) == typeid(TransfertInterac))
			{
				transferts_.push_back(new TransfertInterac(
					*(dynamic_cast<TransfertInterac*>(groupe.transferts_[i]))));
			}
			else
			{
				transferts_.push_back(new TransfertPaypal(
					*(dynamic_cast<TransfertPaypal*>(groupe.transferts_[i]))));
			}
		}
	}

	return *this;
}

// Methode d'ajout
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string & lieu)
{
	// Verification de la presence de l'utilisateur payePar dans le groupe
	bool estPresent = false;
	size_t i = 0;
	while ((estPresent == false) && (i < utilisateurs_.size()))
	{
		if (utilisateurs_[i]->getNom() == payePar->getNom())
			estPresent = true;

		i++;
	}

	// Ajout de la depense si present, sinon un message d'erreur
	if (estPresent == true)
	{
		depenses_.push_back(new Depense(nom, montant, lieu));
		*payePar += depenses_.back();
		double montantIndividuel = montant / utilisateurs_.size();

		for (size_t j = 0; j < utilisateurs_.size(); j++)
		{
			if (payePar != utilisateurs_[j])
				comptes_[j] -= montantIndividuel;
			else
				comptes_[j] += (montant - montantIndividuel);
		}
	}
	else
	{
		cout << "\nErreur	:	La personne payant la depense" 
			 << " n'est pas dans le groupe";
	}

	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	bool doitRenouveler = false;
	bool estAjouter = true;

	// Si le type est Regulier, il faut verifier s'il est dans un groupe
	// Si le type est Premium, il faut verifier l'etat de son abonnement
	if (typeid(*utilisateur) == typeid(UtilisateurRegulier))
	{
		bool estGroupe = 
		   dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe();
		
		if (estGroupe == true)
			estAjouter = false;
		else
		{
			dynamic_cast<UtilisateurRegulier*>(utilisateur)
				->setPossedeGroupe(true);
		}
	}
	else
	{
		unsigned int joursRestants =
			dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants();

		if (joursRestants == 0)
		{
			estAjouter = false;
			doitRenouveler = true;
		}
	}

	// Ajout de l'utilisateur ou bien affichage d'un message d'erreur
	if (estAjouter == true)
	{
		utilisateurs_.push_back(utilisateur);
		comptes_.push_back(0.0);
	}
	else if (doitRenouveler == true)
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " doit renouveler son abonnement Premium";
	}
	else
	{
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " n'est pas souscrit a un abonnement premium,"
			<< " et est deja groupe";
	}

	return *this;
}

// Methode de calculs
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (size_t i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}


		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			// Faire le transfert  du bon type
			MethodePaiement typeDeTransfert = 
				utilisateurs_[indexMin]->getMethodePaiement();

			if (typeDeTransfert == Paypal)
			{
				transferts_.push_back(new TransfertPaypal(-min, 
											utilisateurs_[indexMin], 
											utilisateurs_[indexMax]));
			}
			else
			{
				transferts_.push_back(new TransfertInterac(-min,
											utilisateurs_[indexMin],
											utilisateurs_[indexMax]));
			}
			// Le transfert est effectue
			transferts_[transferts_.size() - 1]->effectuerTransfert();
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			// Faire le transfert du bon type
			MethodePaiement typeDeTransfert =
				utilisateurs_[indexMin]->getMethodePaiement();

			if (typeDeTransfert == Paypal)
			{
				transferts_.push_back(new TransfertPaypal(max,
											utilisateurs_[indexMin],
											utilisateurs_[indexMax]));
			}
			else
			{
				transferts_.push_back(new TransfertInterac(max,
											utilisateurs_[indexMin],
											utilisateurs_[indexMax]));
			}
			// Le transfert est effectue
			transferts_[transferts_.size() - 1]->effectuerTransfert();
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
ostream& operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (size_t i = 0; i < groupe.utilisateurs_.size(); i++) {
		os <<"\n\t " << *groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (size_t i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (size_t i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.utilisateurs_[i]->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
