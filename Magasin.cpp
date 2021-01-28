#include <iostream>
#include <iomanip>
#include "Magasin.h"
#include "ConsoleTable.h"

Magasin::Magasin() {}
//Constructeur (Caractérisé par des clients, des commandes, ID, etc..)
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
//Retourne les Produits
vector<Produit*> Magasin::getProduits(){
    return m_produits;
}
//Retourne les clients 
vector<Client* >Magasin::getClients(){
    return m_clients;
}
//Retourne les commandes
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
//Ajout de produit
void Magasin::addProduit(Produit *p) {
    m_produits.push_back(p);
}
//Ajout de client
void Magasin::addClient(Client* c) {
    m_clients.push_back(c);
}
//Ajout de commande
void Magasin::addCommande(Commande* c) {
    m_commandes.push_back(c);
}
//Permet d'associer a chaque produit une description quantité, ect.
//Dans l'affichage de tous les produits
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
//Mise a jour des quantités
void Magasin::updateProductQuantity(Produit *p, int quantity) {
    for (int i = 0; i < m_produits.size(); ++i) {
        if (p == m_produits.at(i)){
            p->modifierQuantite(quantity);
        }
    }
}
//Permet d'associer a chaque produit une description quantité, ect.
//Dans l'affichage d'un produit demander
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
//Permet d'associer a chaque client un nom, prenom, ect.
//Dans l'affichage de tous les clients
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

//Permet d'associer a chaque client un nom, prenom, ect.
//Dans l'affichage d'un client demander (Affichage d'un client grace a son id)
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

//Permet d'associer a chaque client un nom, prenom, ect.
//Dans l'affichage d'un client en fonction de son nom et prenom
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
//Ajoute un produit au panier
void Magasin::addProductToBasket(int idClient, string titre) {
    for (std::vector<Client*>::iterator pit = m_clients.begin(); pit != m_clients.end(); ++pit) {
        if ((*pit)->getId() == idClient) {
            for (std::vector<Produit*>::iterator it = m_produits.begin(); it != m_produits.end(); ++it) {
                if (titre == (*it)->getTitre()) {
                    (*pit)->ajouterProduit(*it);
                }
            }      
        }
    }
}
//Supprime un produit (par son nom) du panier
void Magasin::removeProductFromBasket(int idClient, string titre) {
 for (std::vector<Client*>::iterator pit = m_clients.begin(); pit != m_clients.end(); ++pit) {
        if ((*pit)->getId() == idClient) {
            for (std::vector<Produit*>::iterator it = m_produits.begin(); it != m_produits.end(); ++it) {
                if (titre == (*it)->getTitre()) {
                    (*pit)->supprimerProduit(*it);
                }
            }      
        }
    }
}
//Affiche le contenu du panier (ne fonctionne pas)
void Magasin::displayBasket(int idClient) {
    for (std::vector<Client*>::iterator pit = m_clients.begin(); pit != m_clients.end(); ++pit) {
        if ((*pit)->getId() == idClient) {
            for (std::vector<Produit*>::iterator it = (*pit)->getPanier().begin(); it != (*pit)->getPanier().end(); ++it) {
                cout << (*it)->getTitre() << endl;   
            }
        }
    }
}
//Valider une commande
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
//Afficher une commande en fonction de l'id de la commande
void Magasin::displayCommande(int id) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getNumero() == id) {
            cout << *m_commandes.at(i) << endl;
        }
    }
}
//Affichage de toute les commandes
void Magasin::displayCommandes() {
    for (int i = 0; i < m_commandes.size(); ++i) {
        cout << *m_commandes.at(i) << endl;
    }
}
//Affichage des toutes les commandes validees
void Magasin::displayCommandesValidees() {
    cout << "LISTE DES COMMANDES VALIDEES" << endl;
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getStatut() == "Validee"){
            cout << *m_commandes.at(i) << endl;
        }
    }
}
//Affichage de commande en fonction du client
void Magasin::displayCommandesClient(Client* client) {
    for (int i = 0; i < m_commandes.size(); ++i) {
        if (m_commandes.at(i)->getClient() == client) {
            cout << *m_commandes.at(i) << endl;
        }
    }
}
//Affichage de commande en fonction de l'id du client
void Magasin::displayCommandesClient(int id) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getId() == id) {
            displayCommandesClient(m_clients.at(i));
            break;
        }
    }
}
//Affichage de commande en fonction du nom et prenom du client
void Magasin::displayCommandesClient(string prenom, string nom) {
    for (int i = 0; i < m_clients.size(); ++i) {
        if (m_clients.at(i)->getNom() == nom && m_clients.at(i)->getPrenom() == prenom) {
            displayCommandesClient(m_clients.at(i));
            break;
        }
    }
}
//Donne un id a un client
int Magasin::generateClientID() {
    m_startIDClient += 1;
    return m_startIDClient;
}
//Donne un id a une commande
int Magasin::generateOrderID() {
    m_startIDOrder += 1;
    return m_startIDOrder;
}




