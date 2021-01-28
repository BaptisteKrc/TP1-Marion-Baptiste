#include "Produit.h"

Produit::Produit() {}
//definition d'un produit : il lui faut un titre, une description etc..
Produit::Produit(string titre, string desc, int quantite, double prix) {
    this->m_titre = titre;
    this->m_description = desc;
    this->m_quantite = quantite;
    this->m_prix_unitaire = prix;
}
//getter
string Produit::getTitre()  {
    return m_titre;
}
//getter
string Produit::getDescription()  {
    return m_description;
}
//getter
int Produit::getQuantite()  {
    return m_quantite;
}
//getter
double Produit::getPrixUnitaire()  {
    return m_prix_unitaire;
}
//fonction pour modifier la quantité 
void Produit::modifierQuantite(int quantite){
    this->m_quantite = quantite;
}
//convertit en string tous les paramètres de Produit pour pouvoir lafficher 
string Produit::toString() {
    return  m_titre + "\t\t" + m_description + "\t\t(" + to_string(m_quantite) +")\t\t" + to_string(m_prix_unitaire) + " â‚¬";
}
//surcharge de l'opérateur << pour afficher un produit 
ostream&operator<< (ostream&output, Produit produit){
    output << produit.toString() << endl;
}
