#ifndef _MAGASIN_H
#define _MAGASIN_H
#include "Produit.h"
#include <vector>

class Magasin{

public:

	Magasin();

void ajoutProduit(Produit* produit)

void display()

void modificationQ(int n, Produit* produit)

private:
	std::vector<Produit*> m_produit;
	std::vector<Client*> m_client;
	std::vector<Commande*> m_commande;

};
#endif

