#include "Produit.h"
#include <iostream>
#include <string>

//Constructeur de Produit
Produit::Produit(std::string titre, std::string description,int quantite, float prix) 
				: m_titre(titre), 
				m_description(description), 
				m_quantite(quantite),
				m_prixU(prix) {
}

//getters classique
std::string Produit::getTitre() const{
	return m_titre;
}

std::string Produit::getDescription() const{
	return m_description;
}

int Produit::getQuantite() const{
	return m_quantite;
}

float Produit::getPrixU() const{
	return m_prixU;
}

//setters
void Produit::setQuantite(int quantite){
	m_quantite = quantite;
}

//Surcharge de l'opérateur << afin d'afficher un produit
std::ostream& operator << (std::ostream& output, Produit& obj){
	output << obj.getTitre() << "	" << obj.getDescription() << "    (" << obj.getQuantite() << ")	 " 
		   << obj.getPrixU() << " €" << std::endl;

	return output;
}
