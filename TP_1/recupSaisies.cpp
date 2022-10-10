#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#include "recupSaisies.hpp"

// III.1.1
void affichageNomPrenomVersion1() {

    std::string prenom = "", nom = "";
    std::cout << "(Version1) Veuillez indiquez votre Prénom Nom : " << std::endl;
    std::cin >> prenom;
    std::cin >> nom;

    std::cout << "Bonjour " << prenom << " " << nom << " !" << std::endl; 
}

// III.1.2 (avec bonus)
void affichageNomPrenomVersion2() {

    std::string prenom = "", nom = "";
    std::cout << "(Version 2) Veuillez indiquez votre Prénom Nom : " << std::endl;
    std::cin >> prenom >> nom;

        // Bonus
    // Nom to uppercase
    std::transform(nom.begin(), nom.end(), nom.begin(), ::toupper);
    // Première lettre prénom uppercase
    prenom[0] = toupper(prenom[0]);

    std::cout << "Bonjour " << prenom << " " << nom << " !" << std::endl; 
}

// III.2 Deviner un nombre aléatoire => III.2.2 

void devinerNombre(){

    srand(time(0));

    int nombreADeviner = rand() % 1000;
    int saisieUtilisateur = 0;
    int nbEssais = 0;
    bool nombreTrouve = false;

    while(!nombreTrouve) {
        std::cout << "Essayez de deviner le nombre mystère : " << std::endl;
        std::cin >> saisieUtilisateur;
        if(saisieUtilisateur == nombreADeviner){
            nombreTrouve = true;
        } else if (saisieUtilisateur > nombreADeviner) {
            std::cout << "Raté, le nombre mystère est inférieur à " << saisieUtilisateur << " ! " << std::endl;
        } else {
            std::cout << "Raté, le nombre mystère est supérieur à " << saisieUtilisateur << " ! " << std::endl;
        }
        nbEssais++;
        std::cout << std::endl;
    }
    std::cout << "Bravo, le nombre mystère était le " << nombreADeviner << "." << std::endl;
    std::cout << "Tu as réussi en " << nbEssais << " essais ! " << std::endl;
}

// III.2.3. L'ordinateur doit deviner un nombre saisie par l'utilisateur

void programmeDevineNombre() {

    int nombreADeviner = 0, nbEssais = 0, borneDebut = 1, borneFin = 1000, nombreOrdinateur = 0;
    bool nombreTrouve = false;

    std::cout << "Indiquez le nombre que vous souhaitez faire deviner à l'ordinateur (1 - 1000) : " << std::endl;
    std::cin >> nombreADeviner;

    while(!nombreTrouve) {
        // Méthode de la recherche dichotomique
        nombreOrdinateur = (borneDebut + borneFin) / 2;

        if(nombreOrdinateur == nombreADeviner){
            nombreTrouve = true;
        } else if(nombreADeviner > nombreOrdinateur) {
            borneDebut = nombreOrdinateur + 1; //  
        } else {
            borneFin = nombreOrdinateur - 1; // 
        }
        nbEssais++;
        std::cout << "---- Nombre généré par l'ordinateur ----" << std::endl;
        std::cout << nombreOrdinateur << std::endl;
        std::cout << std::endl; 
    }

    std::cout << "L'ordinateur a deviné votre nombre : " << nombreADeviner << "." << std::endl;
    std::cout << "En " << nbEssais << " essais ! " << std::endl;
}
