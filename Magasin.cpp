#include <iostream>
#include <iomanip>
#include "Magasin.h"
#include "ConsoleTable.h"

Magasin::Magasin() {}

Magasin::Magasin(vector<Produit*> produits, vector<Client*> clients, vector<Commande*> commandes, int idC, int idO){
   this->m_clients = clients;
   this->m_produits = produits;
   this->m_commandes = commandes;
   this->m_startIDClient = idC;
   this->m_startIDOrder = idO;
}

Magasin::~Magasin() {
    for (Produit* p : m_produits){
        delete p;
    }
    for (Client* c : m_clients){
        delete c;
    }
    for (Commande* c : m_commandes){
        delete c;
    }
}

vector<Produit*> Magasin::getProduits(){
    return m_produits;
}
vector<Client* >Magasin::getClients(){
    return m_clients;
}
vector<Commande*> Magasin::getCommandes(){
    return m_commandes;
}

Produit *Magasin::getProduit(string nom) {
    Produit* res = nullptr;
    for (Produit* p : m_produits) {
        if (p->getTitre() == nom) {
            res = p;
        }
    }
    return res;
}

Client* Magasin::getClient(int id) {
    Client* res = nullptr;
    for (Client* c : m_clients) {
        if (c->getId() == id) {
            res = c;
        }
    }
    return res;
}
Client* Magasin::getClient(string prenom, string nom){
    Client* res = nullptr;
    for (Client* c : m_clients) {
        if (c->getPrenom() == prenom && c->getNom() == nom) {
            res = c;
        }
    }
    return res;
}

Commande* Magasin::getCommande(int id){
    Commande* res = nullptr;
    for (Commande* c : m_commandes) {
        if (c->getNumero() == id) {
            res = c;
        }
    }
    return res;
}

void Magasin::addProduit(Produit *p) {
    m_produits.push_back(p);
}

void Magasin::addClient(Client* c) {
    m_clients.push_back(c);
}

void Magasin::addCommande(Commande* c) {
    m_commandes.push_back(c);
}

void Magasin::displayProducts() {
    ConsoleTable table{"Nom","Description", "Quantite", "Prix Unitaire"};
    table.addTopLine("Liste des produits du magasin");
    table.setStyle(1);
    for (int i = 0; i < getProduits().size(); ++i) {
        string nom = getProduits().at(i)->getTitre() ;
        string description = getProduits().at(i)->getDescription();
        string quantite = to_string(getProduits().at(i)->getQuantite());

        stringstream stream;
        stream << fixed << setprecision(2) << "EU " << getProduits().at(i)->getPrixUnitaire();
        string prix = stream.str();

        table += {nom, description, quantite, prix};
    }
    table.sort(true);
    cout << table;
}

void Magasin::updateProductQuantity(Produit *p, int quantity) {
    for (int i = 0; i < m_produits.size(); ++i) {
        if (p == m_produits.at(i)){
            p->modifierQuantite(quantity);
        }
    }
}

void Magasin::displayProduct(string name) {
    for (int i = 0; i < m_produits.size(); ++i) {
        if (m_produits.at(i)->getTitre() == name){

            ConsoleTable table{"Nom","Description", "Quantite", "Prix Unitaire"};
            table.addTopLine("Description du produit");
            table.setStyle(1);

            string nom = m_produits.at(i)->getTitre();
            string description = m_produits.at(i)->getDescription();
            string quantite = to_string(m_produits.at(i)->getQuantite());

            stringstream stream;
            stream << fixed << setprecision(2) << "EU " << m_produits.at(i)->getPrixUnitaire();
            string prix = stream.str();

            table += {nom, description, quantite, prix};
            cout << table;
        }
    }
}

void Magasin::displayClients() {
    ConsoleTable table{"ID", "Prenom", "Nom"};
    table.addTopLine("Liste des clients");
    table.setStyle(1);

    for (int i = 0; i < m_clients.size(); ++i) {
        string id = to_string(m_clients.at(i)->getId());
        string prenom = m_clients.at(i)->getPrenom();
        string nom = m_clients.at(i)->getNom();
        table += {id, prenom, nom};
    }
    cout << table;
}

void Magasin::displayClient(int id) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getId() == id){

            ConsoleTable table{"ID", "Prenom", "Nom"};
            table.addTopLine("Liste des clients");
            table.setStyle(1);
            string id = to_string(m_clients.at(i)->getId());
            string prenom = m_clients.at(i)->getPrenom();
            string nom = m_clients.at(i)->getNom();
            table += {id, prenom, nom};
            cout << table;
        }
    }
}

void Magasin::displayClient(string name, string surname) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getPrenom() == name && m_clients.at(i)->getNom() == surname){

            ConsoleTable table{"ID", "Prenom", "Nom"};
            table.addTopLine("Liste des clients");
            table.setStyle(1);
            string id = to_string(m_clients.at(i)->getId());
            string prenom = m_clients.at(i)->getPrenom();
            string nom = m_clients.at(i)->getNom();
            table += {id, prenom, nom};
            cout << table;
        }
    }
}

void Magasin::addProductToBasket(Client *c, Produit *p) {
    c->ajouterProduit(p);
}

void Magasin::removeProductFromBasket(Client *c, Produit *p) {
    c->supprimerProduit(p);
}

void Magasin::validerCommande(Commande* c) {
    setCommandeStatut(c, "Validee");
}

void Magasin::setCommandeStatut(Commande* c, string statut) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (c->getNumero() == m_commandes.at(i)->getNumero()){
            m_commandes.at(i)->setStatut(statut);
        }
    }
}

void Magasin::displayCommande(int id) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getNumero() == id) {
            cout << *m_commandes.at(i) << endl;
        }
    }
}

void Magasin::displayCommandes() {
    for (int i = 0; i < m_commandes.size(); ++i) {
        cout << *m_commandes.at(i) << endl;
    }
}

void Magasin::displayCommandesValidees() {
    cout << "LISTE DES COMMANDES VALIDEES" << endl;
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getStatut() == "Validee"){
            cout << *m_commandes.at(i) << endl;
        }
    }
}

void Magasin::displayCommandesClient(Client* client) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getClient() == client) {
            cout << *m_commandes.at(i) << endl;
        }
    }
}

void Magasin::displayCommandesClient(int id) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getId() == id) {
            displayCommandesClient(m_clients.at(i));
            break;
        }
    }
}

void Magasin::displayCommandesClient(string prenom, string nom) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getNom() == nom && m_clients.at(i)->getPrenom() == prenom) {
            displayCommandesClient(m_clients.at(i));
            break;
        }
    }
}

int Magasin::generateClientID() {
    m_startIDClient += 1;
    return m_startIDClient;
}

int Magasin::generateOrderID() {
    m_startIDOrder += 1;
    return m_startIDOrder;
}




