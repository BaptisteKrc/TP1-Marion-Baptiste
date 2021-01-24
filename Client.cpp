#include "Client.h"
#include "Produit.h"
#include "ConsoleTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace  std;

Client::Client(int id, string nom, string prenom, vector<Produit*> panier){
	this->m_id = id;
    this->m_nom = nom;
    this->m_prenom = prenom;
    this->m_panier = panier;
}

vector<Produit*> Client::getPanier(){
	return m_panier;
}
int Client::getId(){
    return m_id;
}
string Client::getNom(){
	return m_nom;
}
string Client::getPrenom(){
	return m_prenom;
}

void Client::ajouterProduit(Produit *p) {
    m_panier.push_back(p);
}

void Client::viderPanier() {
    m_panier.clear();
}

void Client::augmenterQuantite(Produit *p, int quantite) {
    p->modifierQuantite(quantite);
}

void Client::supprimerProduit(Produit* p) {
    for (int i = 0; i < m_panier.size(); ++i) {
        if (p == m_panier.at(i)){
            m_panier.erase(m_panier.begin() + i);
        }
    }
}

ostream&operator<< (ostream&output, Client client){
    ConsoleTable table{"Nom","Description", "Quantite", "Prix Unitaire"};
    table.addTopLine("Client #"+ to_string(client.getId()) + " : "+ client.getPrenom() + " " + client.getNom());
    table.addTopLine("Panier :");
    table.setStyle(1);
    for (int i = 0; i < client.getPanier().size(); ++i) {
        string nom = client.getPanier().at(i)->getTitre() ;
        string description = client.getPanier().at(i)->getDescription();
        string quantite = to_string(client.getPanier().at(i)->getQuantite());

        stringstream stream;
        stream << fixed << setprecision(2) << "$ " << client.getPanier().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    table.sort(true);
    output << table;
}