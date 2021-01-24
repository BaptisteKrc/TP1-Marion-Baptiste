#ifndef EASYSHOP_CLIENT_H
#define EASYSHOP_CLIENT_H


#include <iostream>
#include <string>
#include <vector>
#include "Produit.h"

using namespace  std;

class Client 
{
	public :
		Client ();
		Client(int id,string nom, string prenom,vector<Produit*> panier);

		vector<Produit*> getPanier();
		int getId();
		string getNom();
		string getPrenom();

		void ajouterProduit(Produit* p);
		void viderPanier();
		void augmenterQuantite(Produit* p, int quantite);
        void supprimerProduit(Produit* p);
		friend ostream& operator <<(ostream &output, Client client);



	private :
        int m_id;
		string m_nom;
		string m_prenom ;
		vector<Produit*> m_panier;
};


#endif