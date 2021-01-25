#define ANSI_GREEN "\033[0;92m"
#define ANSI_RED   "\033[0;91m"
#define ANSI_RESET "\033[0;0m"
#define ANSI_CYAN "\033[0;36m"

#define SLEEP_DELAY 2

#include <iostream>
#include <limits>
#include <sys/ioctl.h>
#include <unistd.h>

#include "Magasin.h"

using namespace std;


void move(int x, int y){
    // Déplace le curseur en x,y
    string escape_ANSI = "\033["+to_string(y)+";"+to_string(x)+"H";
    cout << escape_ANSI.c_str();
}

void Box(){

    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    
    // Détermine le point de départ du tracé
    int x = size.ws_col - 15;
    int y = size.ws_row - 3;

    string top = "╔══════════╗";
    string mid = "║          ║";
    string bot = "╚══════════╝";

    // Tracé de la case en bas a droite
    move(x,y);
    cout << ANSI_RED << top.c_str();
    move(x,y+1);
    cout << ANSI_RED << mid.c_str();
    move(x,y+2);
    cout << ANSI_RED << bot.c_str();

    move(x+5, y+1);
}

//Affichage de l'accueil
void displayAccueil() {
    system("clear");
    move(5, 2);
    cout << ANSI_RED << "╔══════╗ ╔══════╗ ╔══════╗ ╔═╗   ╔═╗ ╔══════╗ ╔═══════╗ ╔══════╗ ╔══════╗ ╔══════╗" << ANSI_RESET;
    move(5, 3);
    cout << ANSI_RED << "║ ╔════╝ ║ ╔══╗ ║ ║ ╔════╝ ╚╗╚╗ ╔╝╔╝ ║ ╔════╝ ╚══╗ ╔══╝ ║ ╔══╗ ║ ║ ╔══╗ ║ ║ ╔════╝" << ANSI_RESET;
    move(5, 4);
    cout << ANSI_RED << "║ ╚══╗   ║ ╚══╝ ║ ║ ╚════╗  ╚╗╚═╝╔╝  ║ ╚════╗    ║ ║    ║ ║  ║ ║ ║ ╚══╝ ║ ║ ╚══╗" << ANSI_RESET;
    move(5, 5);
    cout << ANSI_RED << "║ ╔══╝   ║ ╔══╗ ║ ╚════╗ ║   ╚╗ ╔╝   ╚════╗ ║    ║ ║    ║ ║  ║ ║ ║ ╔═╗ ╔╝ ║ ╔══╝ " << ANSI_RESET;
    move(5, 6);
    cout << ANSI_RED << "║ ╚════╗ ║ ║  ║ ║ ╔════╝ ║    ║ ║    ╔════╝ ║    ║ ║    ║ ╚══╝ ║ ║ ║ ╚╗╚╗ ║ ╚════╗" << ANSI_RESET;
    move(5, 7);
    cout << ANSI_RED << "╚══════╝ ╚═╝  ╚═╝ ╚══════╝    ╚═╝    ╚══════╝    ╚═╝    ╚══════╝ ╚═╝  ╚═╝ ╚══════╝"  << ANSI_RESET << endl;
    cout << " "<< endl << endl;
    cout << ANSI_CYAN << "Bienvenue dans le EASYSTORE de Marion et Babou"<< ANSI_RESET << endl << endl;
    cout << " "<< endl << endl;
    cout << ANSI_CYAN << "Que voulez vous faire ?"<< ANSI_RESET << endl << endl;
    cout << ANSI_CYAN << "1 - Entrer dans le EASYSTORE" << ANSI_RESET << endl;
    cout << ANSI_CYAN << "2 - Quitter" << ANSI_RESET << endl;
    Box();
}

//Affichage du menu principal
void displayMenu(){
    system("clear");
    cout << "1 - Gestion des stocks" << endl;
    cout << "2 - Gestion des clients" << endl;
    cout << "3 - Gestion des commandes" << endl;
    cout << "4 - Sauvegarder le magasin" << endl;
    cout << "5 - Charger un magasin" << endl;
    cout << "6 - Retour à l'accueil" << endl;
    Box();
}

//Affichage menu client
void displayMenuClient() {
    system("clear");
    cout << "1 - Ajouter un client" << endl;
    cout << "2 - Afficher la liste des clients" << endl;
    cout << "3 - Afficher un client grâce à son ID" << endl;
    cout << "4 - Afficher un client grâce à son nom et son prénom" << endl;
    cout << "5 - Retour au menu principal" << endl;
    Box();
}

//Affichage menu commande
void displayMenuCommande() {
    system("clear");
    cout << "1 - Afficher la liste des commandes" << endl;
    cout << "2 - Valider une commande grâce à son ID" << endl;
    cout << "3 - Afficher la liste des commandes validées" << endl;
    cout << "4 - Afficher une commande grâce à son ID" << endl;
    cout << "5 - Afficher toutes les commandes d'un client grâce à son ID" << endl;
    cout << "6 - Afficher toutes les commandes d'un client grâce à son nom et son prénom" << endl;
    cout << "7 - Retour au menu principal" << endl;
    Box();
}

//Affichage menu magasin/stock
void displayMenuMagasin() {
    system("clear");
    cout << "1 - Ajouter un produit" << endl;
    cout << "2 - Modifier la quantité d'un produit" << endl;
    cout << "3 - Afficher tous les produits du magasin" << endl;
    cout << "4 - Afficher les détails d'un produit grâce à son nom" << endl;
    cout << "5 - Retour au menu principal" << endl;
    Box();
}

int getInput(){
    int choix;
    cin >> choix;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }
    return choix;
}

void press_to_continue() {
    cout << ANSI_GREEN << "Appuyer sur ENTREE pour continuer ..." << ANSI_RESET << endl;
    system("read var");
}

void to_be_implemented_next() {
    system("clear");
    cout << ANSI_RED << "Cette option n'est malheureusement pas encore disponible" << endl;
    cout << "Appuyer sur ENTREE pour revenir à l'accueil ..." << ANSI_RESET << endl;
    system("read var");
}

void initialisation_store(Magasin* shop){
    Produit* p3 = new Produit("Xbox One", "Console de jeu Microsoft", 20, 179.99);
    Produit* p = new Produit("PS4 ", "Console de jeu Sony", 20, 249.99);
    Produit* p4 = new Produit("PS5", "Console de jeu Sony", 20, 599.99);
    Produit* p2 = new Produit("Switch", "Console de jeu Nintendo", 20, 299.99);
    Produit* p5 = new Produit("3DS", "Console de jeu Nintendo", 20, 299.99);

    shop->addProduit(p);
    shop->addProduit(p2);
    shop->addProduit(p3);
    shop->addProduit(p4);
    shop->addProduit(p5);

    Client* client = new Client(shop->generateClientID(), "Ginhac", "Dominique", shop->getProduits());
    Client* client2 = new Client(shop->generateClientID(), "Krecina", "Baptiste", shop->getProduits());
    Client* client3 = new Client(shop->generateClientID(), "Paris", "Marion", shop->getProduits());

    shop->addClient(client);
    shop->addClient(client2);
    shop->addClient(client3);

    Commande* co = new Commande(client, client->getPanier(), "En cours de traitement", shop->generateOrderID());
    Commande* co2 = new Commande(client2, client->getPanier(), "En cours de traitement", shop->generateOrderID());

    shop->addCommande(co);
    shop->addCommande(co2);
}


int main(){
    
    int choix = 0, choix2 = 0, choix3 = 0;
    bool quit = false, quit2 = false, quit3 = false;

    vector<Produit*> produits;
    vector<Client*> clients;
    vector<Commande*> commandes;

    int startIDClient = 0; int startIDOrder = 0;

    Magasin easystore(produits, clients, commandes, startIDClient, startIDOrder);

    initialisation_store(&easystore);

    
    while(!quit) {
        displayAccueil();
        choix = getInput();
        switch(choix){
            case 1: // Affichage du menu principal
                displayMenu();
                quit2 = false;
                while(!quit2) {
                    choix2 = getInput();
                    switch(choix2) {
                        case 1 : // Gestion des stocks
                            displayMenuMagasin();
                            quit3 = false;
                            while(!quit3){
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Ajouter un produit
                                    {
                                        string nom, desc;
                                        int quantite;
                                        double prixU;
                                        cin.ignore();
                                        cout << "Nom du produit : ";
                                        getline(cin, nom);
                                        cout << "Description du produit : ";
                                        getline(cin, desc);
                                        cout << "Quantitée disponible : ";
                                        quantite = getInput();
                                        cout << "Prix unitaire du produit : ";
                                        cin >> prixU;
                                        Produit* p = new Produit(nom, desc, quantite, prixU);
                                        easystore.addProduit(p);
                                        cout << ANSI_GREEN << "Le produit a été ajouté" << ANSI_RESET << endl;
                                        sleep(SLEEP_DELAY);
                                        displayMenuMagasin();
                                        break;
                                    }
                                    case 2: // Modifier la quantité d'un produit
                                    {
                                        string nom;
                                        cout << "Nom du produit : ";
                                        cin.ignore();
                                        getline(cin, nom);
                                        cout << "Nouvelle quantité : ";
                                        int quantite = getInput();
                                        easystore.updateProductQuantity(easystore.getProduit(nom), quantite);
                                        cout << ANSI_GREEN << "Le produit a été modifié" << ANSI_RESET << endl;
                                        displayMenuMagasin();
                                        break;
                                    }
                                    case 3: // Afficher tous les produits du magasin
                                        system("clear");
                                        easystore.displayProducts();
                                        press_to_continue();
                                        displayMenuMagasin();
                                        break;
                                    case 4: // Afficher les détails d'un produit
                                    {
                                        string nom;
                                        cout << "Nom du produit : ";
                                        cin.ignore();
                                        getline(cin, nom);
                                        system("clear");
                                        easystore.displayProduct(nom);
                                        press_to_continue();
                                        displayMenuMagasin();
                                        break;
                                    }
                                    case 5:  // Retour au menu principal
                                        displayMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayMenuMagasin();
                                        break;
                                }
                            }
                            break;
                        case 2 : // Gestion des clients 
                            displayMenuClient();
                            quit3 = false;
                            while(!quit3){
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Ajouter un client
                                    {
                                        int id;
                                        string nom, prenom;
                                        vector<Produit*> panier;
                                        id = easystore.generateClientID();
                                        cout << "Prenom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        Client* c = new Client(id,nom, prenom, panier);
                                        easystore.addClient(c);
                                        cout << ANSI_GREEN << "Le client a été ajouté" << ANSI_RESET << endl;
                                        sleep(SLEEP_DELAY);
                                        displayMenuClient();
                                        break;
                                    }
                                    case 2: // Afficher tous les clients
                                        system("clear");
                                        easystore.displayClients();
                                        press_to_continue();
                                        displayMenuClient();
                                        break;
                                    case 3: // Aficher un client grâce à son ID
                                    {
                                        cout << "ID Du client : ";
                                        int id = getInput();
                                        system("clear");
                                        easystore.displayClient(id);
                                        press_to_continue();
                                        displayMenuClient();
                                        break;
                                    }
                                    case 4: // Afficher un client grâce à son nom
                                    {
                                        string prenom, nom;
                                        cout << "Prenom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        system("clear");
                                        easystore.displayClient(prenom, nom);
                                        press_to_continue();
                                        displayMenuClient();
                                        break;
                                    }
                                    case 5: // Retour au menu principal
                                        displayMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayMenuClient();
                                        break;
                                }
                            }
                            break;
                        case 3 : // Gestion des commandes 
                            displayMenuCommande();
                            quit3 = false;
                            while(!quit3) {
                                choix3 = getInput();
                                switch(choix3) {
                                    case 1: // Afficher toutes les commandes
                                        system("clear");
                                        easystore.displayCommandes();
                                        press_to_continue();
                                        displayMenuCommande();
                                        break;
                                    case 2 : // Valider une commande grâce à son ID
                                    {
                                        cout << "ID de la commande : ";
                                        int id = getInput();
                                        Commande * c = easystore.getCommande(id);
                                        if ( easystore.getCommande(id) != nullptr) {
                                            easystore.validerCommande(c);
                                            if (easystore.getCommande(id)->getStatut() == "Validee") {
                                                cout << ANSI_GREEN << "La commande a été validée" << ANSI_RESET << endl;
                                            } else {
                                                cout << ANSI_RED << "La commande n'a pas été validée" << ANSI_RESET << endl;
                                            }
                                        } else {
                                            cout << ANSI_RED << "La commande n'existe pas" << ANSI_RESET << endl;
                                        }
                                        sleep(SLEEP_DELAY);
                                        displayMenuCommande();
                                        break;
                                    }
                                    case 3: // Afficher toutes les commandes validées
                                        system("clear");
                                        easystore.displayCommandesValidees();
                                        press_to_continue();
                                        displayMenuCommande();
                                        break;
                                    case 4: // Afficher une commande grâce à son ID
                                     {
                                         cout << "ID de la commande : ";
                                         int id = getInput();
                                         system("clear");
                                         easystore.displayCommande(id);
                                         press_to_continue();
                                         displayMenuCommande();
                                         break;
                                     }
                                    case 5: // Afficher toutes les commandes d'un client grâce à son ID
                                    {
                                        cout << "ID du client : ";
                                        int id = getInput();
                                        system("clear");
                                        easystore.displayCommandesClient(id);
                                        press_to_continue();
                                        displayMenuCommande();
                                        break;
                                    }
                                    case 6: // Afficher toutes les commandes d'un client grâce à son nom et son prénom
                                    {
                                        string prenom, nom;
                                        cout << "Prénom du client : ";
                                        cin.ignore();
                                        getline(cin, prenom);
                                        cout << "Nom de famille du client : ";
                                        getline(cin, nom);
                                        system("clear");
                                        easystore.displayCommandesClient(prenom, nom);
                                        press_to_continue();
                                        displayMenuCommande();
                                        break;
                                    }
                                    case 7: // Retour au menu principal
                                        displayMenu();
                                        quit3 = true;
                                        break;
                                    default:
                                        displayMenuCommande();
                                        break;
                                }
                            }
                            break;
                        case 4 : // Sauvegarder le magasin                                        // Pas finis
                            to_be_implemented_next();
                            quit2 = true;
                            break;
                        case 5 : // Charger un magasin                                            // Pas finis
                            to_be_implemented_next();
                            quit2 = true;
                            break;
                        case 6 : // Retour à l'accueil
                            quit2 = true;
                            break;
                        default:
                            displayMenu();
                            break;
                    }
                }
                break;
            case 2 : // Quitter le EASYSTORE
                quit = true;
                break;
            default:
                displayAccueil();
                break;
        }
    }
    system("clear");
}
