#include "Produit.h"

Produit::Produit() {}

Produit::Produit(string titre, string desc, int quantite, double prix) {
    this->m_titre = titre;
    this->m_description = desc;
    this->m_quantite = quantite;
    this->m_prix_unitaire = prix;
}

string Produit::getTitre()  {
    return m_titre;
}

string Produit::getDescription()  {
    return m_description;
}

int Produit::getQuantite()  {
    return m_quantite;
}

double Produit::getPrixUnitaire()  {
    return m_prix_unitaire;
}

void Produit::modifierQuantite(int quantite){
    this->m_quantite = quantite;
}


string Produit::toString() {
    return  m_titre + "\t\t" + m_description + "\t\t(" + to_string(m_quantite) +")\t\t" + to_string(m_prix_unitaire) + " €";
}

ostream&operator<< (ostream&output, Produit produit){
    output << produit.toString() << endl;
}