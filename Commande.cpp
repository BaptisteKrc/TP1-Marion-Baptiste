#include <iostream>
#include <iomanip>
#include "Commande.h"
#include "ConsoleTable.h"

using namespace std;

Commande::Commande() : m_client(), m_produits(), m_statut("Non renseigne"), m_numero(0) {}

//Constructeur 
Commande::Commande(Client* client, vector<Produit*> produits, string statut, int numero) {
    this->m_client = client;
    this->m_produits = produits;
    this->m_statut = statut;
    this->m_numero = numero;
}

//Setter Client
void Commande::setClient(Client* client){
	this->m_client = client;
}

//Setter Produit
void Commande::setProduits(vector<Produit*> produits){
	this->m_produits = produits;
}

//Setter statue (de la commande)
void Commande::setStatut(string statut){
	this->m_statut = statut;
}
//Setter numéro (de la commande)
void Commande::setNumero(int numero){
	this->m_numero = numero;
}
//Getter Client
Client* Commande::getClient(){
	return this->m_client;
}
//Getter Produit
vector<Produit*> Commande::getProduits(){
	return this->m_produits;
}
//Getter statut (de la commande)
string Commande::getStatut(){
	return this->m_statut;
}
//Getter numéro (de la commande)
int Commande::getNumero(){
	return this->m_numero;
}
//Permet de calculer le prix total de la commande
double Commande::getPrixTotal() {
    double prixTotal = m_produits.at(0)->getPrixUnitaire() * m_produits.at(0)->getQuantite();
    double prixInt=0;
    for (int i = 1; i < m_produits.size(); ++i) {
        prixInt = m_produits.at(i)->getPrixUnitaire() * m_produits.at(i)->getQuantite();
		prixTotal = prixTotal+prixInt;
    }
    return prixTotal;
}
//Surcharge de l'opérateur "<<" pour la commande
ostream&operator<< (ostream&output,Commande commande){

    ConsoleTable table{"Nom","Description", "Quantite", "Prix"};
    table.addTopLine("Details de la commande #"+ to_string(commande.getNumero()));
    table.addTopLine("Client #"+ to_string(commande.getClient()->getId()) +": " + commande.getClient()->getPrenom() + " " + commande.getClient()->getNom());
    table.setStyle(1);
    for (int i = 0; i < commande.getProduits().size(); ++i) {
        string nom = commande.getProduits().at(i)->getTitre();
        string description = commande.getProduits().at(i)->getDescription();
        string quantite = to_string(commande.getProduits().at(i)->getQuantite());

        stringstream stream;
        stream << fixed << setprecision(2) << "EU " << commande.getProduits().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    double prixTotal = commande.getPrixTotal();
    stringstream stream;
    stream << fixed << setprecision(2) << prixTotal;
    string prix = stream.str();

    table.sort(true);
    table.addBottomLine("Statut de la commande : "+ commande.getStatut());
    table.addBottomLine("TOTAL : EU "+ prix);

    output << table;
	return output;
}
