#include <iostream>
#include <iomanip>
#include "Commande.h"
#include "ConsoleTable.h"

using namespace std;

Commande::Commande() : m_client(), m_produits(), m_statut("Non renseigne"), m_numero(0) {}


Commande::Commande(Client* client, vector<Produit*> produits, string statut, int numero) {
    this->m_client = client;
    this->m_produits = produits;
    this->m_statut = statut;
    this->m_numero = numero;
}


void Commande::setClient(Client* client){
	this->m_client = client;
}


void Commande::setProduits(vector<Produit*> produits){
	this->m_produits = produits;
}

void Commande::setStatut(string statut){
	this->m_statut = statut;
}

void Commande::setNumero(int numero){
	this->m_numero = numero;
}

Client* Commande::getClient(){
	return this->m_client;
}

vector<Produit*> Commande::getProduits(){
	return this->m_produits;
}

string Commande::getStatut(){
	return this->m_statut;
}

int Commande::getNumero(){
	return this->m_numero;
}

double Commande::getPrixTotal() {
    double prixTotal = m_produits.at(0)->getPrixUnitaire() * m_produits.at(0)->getQuantite();
    for (int i = 1; i < m_produits.size(); ++i) {
        prixTotal = m_produits.at(i)->getPrixUnitaire() * m_produits.at(i)->getQuantite();
    }
    return prixTotal;
}

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
        stream << fixed << setprecision(2) << "$ " << commande.getProduits().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    double prixTotal = commande.getPrixTotal();
    stringstream stream;
    stream << fixed << setprecision(2) << prixTotal;
    string prix = stream.str();

    table.sort(true);
    table.addBottomLine("Statut de la commande : "+ commande.getStatut());
    table.addBottomLine("TOTAL : $"+ prix);

    output << table;
	return output;
}


