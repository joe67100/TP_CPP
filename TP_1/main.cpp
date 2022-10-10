// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "recupSaisies.hpp"
#include "tableau.hpp"
#include "tennis.hpp"

// I.1.1
int Somme(int x, int y) {
    return x + y;
}

// I.1.2 -- Exemple : X = 3 et Y = 8 => X = 8 et Y = 3
void Inverser(int x, int y) {
    std::cout << "X = " << x << " et Y = " << y << std::endl;
    int tmp = x;
    x = y;
    y = tmp;
    std::cout << " --- Inversion en cours --- " << std::endl;
    std::cout << "X = " << x << " et Y = " << y << std::endl;

    std::cout << std::endl;
}

// I.1.3 => Avec pointeur
void RemplacerAvecPointeur(int x, int y, int* pointeurZ) {
    *pointeurZ = Somme(x, y);
}

// I.1.3 => Avec reference
void RemplacerAvecReference(int x, int y, int& referenceZ) {
    referenceZ = Somme(x, y);
}

void fonctionsPartie1(){

    // ----- Appels fonctions I.1.1 à I.1.3 ----- //

    std::cout << "Somme = " << Somme(3, 8) << std::endl;
    
    Inverser(3, 8); 

    // Fonctions de remplacement :
    int x = 14, y = 2, z = 1;

        // Avec pointeur :
    int* pointeurZ = &z;
    std::cout << "Modification valeur par pointeur : " << std::endl;
    RemplacerAvecPointeur(x, y, pointeurZ);
    std::cout << "La valeur de Z est " << z << std::endl; // Affiche 16
    
        // Avec référence : 
    std::cout << "Modification valeur avec référence " << std::endl;
    x = 7, y = 3;
    int& referenceZ = z;
    RemplacerAvecReference(x, y, referenceZ);
    std::cout << "La valeur de Z est " << z << std::endl; // Affiche 10

    std::cout << std::endl;
}



void fonctionsTableau() {

    // ----- Appels fonctions tableau.cpp - I.1.4 ----- //

    const int CROISSANT = 1;
    const int DECROISSANT = 2;

    // Création du vecteur (similaire aux tableaux) avec taille variable
    int tailleTableau = 0;
    std::cout << "Veuillez indiquer la taille du tableau de random : ";
    std::cin >> tailleTableau;
    std::vector<int> tableau(tailleTableau);

    // Affichage du tableau avant tri

    std::cout << "Valeur du tableau : " << std::endl;
    for (int i = 0; i < tailleTableau; i++) {
        tableau[i] = rand() % 100 ;
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl;

    // Demande tri
    int inputTri = 0; 
    std::cout << "Dans quel ordre souhaitez-vous que le tableau soit trié ?" << std::endl;
    std::cout << "1 - Ordre croissant" << std::endl;
    std::cout << "2 - Ordre décroissant" <<std::endl;
    std::cin >> inputTri;

    // Appels fonctions pour le tri

    std::cout << "Tri du tableau : " << std::endl;

    switch (inputTri)
    {
    case CROISSANT:
        TriCroissant(tableau, tailleTableau);
        TriDecroissant(tableau, tailleTableau);
        break;
    case DECROISSANT:
        TriDecroissant(tableau, tailleTableau);
        TriCroissant(tableau, tailleTableau);
        break;
    default:
        break;
    }
}

void fonctionsPartie2() {

    // ----- Jeu de Tennis - II ----- //

    bool victoire = false;
    int gagnantCoup = 0;

    int joueur1 = 0;
    int joueur2 = 1;

    // Tableau avec score du joueur 1 & score du joueur 2
    int nbPoints[] = {0, 0};

    int nbService = 1;

    while(!victoire){

        // Input manuel :
        /* 
        do{
        std::cout << "Quel joueur remporte le service " << nbService << " ? : (1 ou 2)" << std::endl;
        std::cin >> gagnantCoup;
        } while (gagnantCoup != 1 && gagnantCoup != 2);
        */

        // Gagnant du coup généré par l'ordinateur :
        gagnantCoup = (rand() % 2) + 1;
        std::cout << "Le joueur " << gagnantCoup << " a remporté le service numéro " << nbService << " !" << std::endl;
        

        nbService++;

        calculPoints(gagnantCoup - 1, nbPoints);
        
        affichageResultats(nbPoints, joueur1);
        affichageResultats(nbPoints, joueur2);
        std::cout << std::endl;

        if(nbPoints[joueur1] == 69 || nbPoints[joueur2] == 69){
            victoire = true;
        }
    }
}

void fonctionsPartie3(){

    // ----- Appels fonctions recupSaisies.cpp - III ----- //

    affichageNomPrenomVersion1();
    affichageNomPrenomVersion2();
    devinerNombre();
    programmeDevineNombre();
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int userChoice = 0;
    int reloadProgram = 0;

    do {
        do {
            std::cout << "----- Bonjour, veuillez choisir le programme à exécuter -----" << std::endl;
            std::cout << "1 : Partie 1 - Manipulation des nombres " << std::endl;
            std::cout << "2 : Partie 1 - Tableaux" << std::endl;
            std::cout << "3 : Partie 2 - Jeu de tennis" << std::endl;
            std::cout << "4 : Partie 3 - Récupération des saisies" << std::endl;
            std::cin >> userChoice;
        } while(userChoice > 4 || userChoice < 1);

        std::cout << std::endl;

        switch (userChoice)
        {
        case 1:
            fonctionsPartie1();
            break;
        case 2:
            fonctionsTableau();
            break;
        case 3:
            fonctionsPartie2();
            break;
        case 4:
            fonctionsPartie3();
            break;
        default:
            break;
        }

        do {
            std::cout << std::endl;
            std::cout << "Fin du programme. Souhaitez vous le relancer ? 1 - Oui / 0 - Non" << std::endl;
            std::cin >> reloadProgram;
        } while(reloadProgram != 0 && reloadProgram != 1);

    } while(reloadProgram);

    return EXIT_SUCCESS;
}