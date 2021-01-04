//Magasin.cpp

#include <iostream>
#include <vector>

#include "Magasin.h"
#include "Produit.h"

Magasin::Magasin(){}


 void Magasin::ajoutProduit(Produit* produit){
	m_produit.push_back(produit);
 }

 void Magasin::display(){
 	for ( int i=0; i<produit.size();i++){
 		std::cout << "NAME 		DESCRIPTION 		QUANTITY		PRICE"<< std::endl;
 		std::cout << m_produit.at(i) << std::endl;
 	}
 }

 void Magasin::modificationQ(int n, Produit* produit){
 	produit.setQuantite(n);
 }
