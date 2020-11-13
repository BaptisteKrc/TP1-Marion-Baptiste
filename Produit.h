#ifndef _PRODUIT_H
#define _PRODUIT_H

#include <iostream>
#include <string>
#include <vector>

//Création de la classe Produit 
class Produit{

public:

	//Constructeur
	Produit(std::string titre = "PS4", 
			std::string description = "Console de jeu Sony",
			int quantite=1, float prix=0.0);

	//Getters
	std::string getTitre() const;
	std::string getDescription() const;
	int getQuantite() const;
	float getPrixU() const;

	//setters
	void setQuantite(int quantite);


private:

	//attributs de Produit
	std::string m_titre;
	std::string m_description;
	int m_quantite;
	float m_prixU;



};

//surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& output, Produit& obj);



#endif