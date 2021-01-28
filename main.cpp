#define ANSI_GREEN "\033[0;92m"
#define ANSI_RED   "\033[0;91m"
#define ANSI_RESET "\033[0;0m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_BLUE "\033[34m"

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

//Création du titre du magasin sur l'écran d'accueil
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
    cout << ANSI_CYAN << top.c_str();
    move(x,y+1);
    cout << ANSI_CYAN << mid.c_str();
    move(x,y+2);
    cout << ANSI_CYAN << bot.c_str();

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
    cout << ANSI_GREEN << "1 - Gestion des stocks" << ANSI_RESET << endl;
    cout << ANSI_BLUE << "2 - Gestions des clients" << ANSI_RESET << endl;
    cout << ANSI_RED << "3 - Gestions des commandes" << ANSI_RESET << endl;
    cout << ANSI_CYAN << "4 - Retour à l'accueil" << ANSI_RESET  << endl;
    Box();
}

//Affichage menu client
void displayMenuClient() {
    system("clear");
    cout << ANSI_BLUE << "1 - Ajouter un client"<< ANSI_RESET << endl;
    cout << ANSI_BLUE << "2 - Afficher la liste des clients"<< ANSI_RESET << endl;
    cout << ANSI_BLUE << "3 - Afficher un client grâce à son ID"<< ANSI_RESET << endl;
    cout << ANSI_BLUE << "4 - Afficher un client grâce à son nom et son prénom"<< ANSI_RESET << endl;
    cout << ANSI_CYAN << "5 - Retour au menu principal"<< ANSI_RESET << endl;
    Box();
}

//Affichage menu commande
void displayMenuCommande() {
    system("clear");
    cout<< ANSI_RED << "1 - Afficher la liste des commandes"<< ANSI_RESET << endl;
    cout<< ANSI_RED << "2 - Valider une commande grâce à son ID" << ANSI_RESET<< endl;
    cout<< ANSI_RED << "3 - Afficher la liste des commandes validées"<< ANSI_RESET << endl;
    cout<< ANSI_RED << "4 - Afficher une commande grâce à son ID"<< ANSI_RESET << endl;
    cout<< ANSI_RED << "5 - Afficher toutes les commandes d'un client grâce à son ID"<< ANSI_RESET << endl;
    cout<< ANSI_RED << "6 - Afficher toutes les commandes d'un client grâce à son nom et son prénom"<< ANSI_RESET << endl;
    cout<< ANSI_CYAN << "7 - Retour au menu principal" << ANSI_RESET << endl;
    Box();
}

//Affichage menu magasin/stock
void displayMenuMagasin() {
    system("clear");
    cout << ANSI_GREEN  << "1 - Ajouter un produit" << ANSI_RESET << endl;
    cout << ANSI_GREEN << "2 - Modifier la quantité d'un produit" << ANSI_RESET << endl;
    cout << ANSI_GREEN << "3 - Afficher tous les produits du magasin" << ANSI_RESET << endl;
    cout << ANSI_GREEN << "4 - Afficher les détails d'un produit grâce à son nom" << ANSI_RESET << endl;
    cout << ANSI_CYAN << "5 - Retour au menu principal" << ANSI_RESET << endl;
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
//Fonction "press to continue"
void press_to_continue() {
    cout << ANSI_CYAN<< "Appuyer sur ENTREE pour continuer ..." << ANSI_RESET << endl;
    system("read var");
}
//Initialisation de toute les valeurs de base du store
void initialisation_store(Magasin* shop){
    Produit* p3 = new Produit("Xbox One", "Console de jeu Microsoft", 15, 179.99);
    Produit* p = new Produit("PS4", "Console de jeu Sony", 8, 249.99);
    Produit* p4 = new Produit("PS5", "Console de jeu Sony", 14, 599.99);
    Produit* p2 = new Produit("Switch", "Console de jeu Nintendo", 30, 299.99);
    Produit* p5 = new Produit("3DS", "Console de jeu Nintendo", 20, 299.99);
    Produit* p6 = new Produit("PC", "Ordinateur portable", 10, 799.90);

    shop->addProduit(p);
    shop->addProduit(p2);
    shop->addProduit(p3);
    shop->addProduit(p4);
    shop->addProduit(p5);
    shop->addProduit(p6);

    Client* client = new Client(shop->generateClientID(), "Ginhac", "Dominique", shop->getProduits());
    Client* client2 = new Client(shop->generateClientID(), "Krecina", "Baptiste", shop->getProduits());
    Client* client3 = new Client(shop->generateClientID(), "Paris", "Marion", shop->getProduits());
    Client* client4 = new Client(shop->generateClientID(), "Senechal", "Hugo", shop->getProduits());
    
    shop->addClient(client);
    shop->addClient(client2);
    shop->addClient(client3);
    shop->addClient(client4);
    
    Commande* co = new Commande(client, client->getPanier(), "En cours de traitement", shop->generateOrderID());
    Commande* co2 = new Commande(client2, client->getPanier(), "En cours de traitement", shop->generateOrderID());
    Commande* co3 = new Commande(client3, client->getPanier(), "En cours de traitement", shop->generateOrderID());
    Commande* co4 = new Commande(client4, client->getPanier(), "En cours de traitement", shop->generateOrderID());

    shop->addCommande(co);
    shop->addCommande(co2);
    shop->addCommande(co3);
    shop->addCommande(co4);
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
                                        cout << ANSI_CYAN << "Le produit a été ajouté" << ANSI_RESET << endl;
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
                                        cout << ANSI_CYAN << "Le produit a été modifié" << ANSI_RESET << endl;
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
                                        cout << ANSI_CYAN << "Le client a été ajouté" << ANSI_RESET << endl;
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
                                                cout << ANSI_CYAN << "La commande a été validée" << ANSI_RESET << endl;
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
                        case 4 : // Retour à  l'accueil
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
