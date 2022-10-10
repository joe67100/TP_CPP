#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "tableau.hpp"

// I.1.2 (avec pointeurs) - La fonction prend pour paramètres l'adresse mémoire de tableau[j] et tableau [j+1]
void InverserValeurTableau(int *x, int *y) {
    // On échange les valeurs de tableau[j] grâce à leur adresse mémoire
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// I.1.4
void TriCroissant(std::vector<int>& tableau, int tailleTableau) {
    std::cout << "Ordre croissant : " << std::endl;
    for(int i = 0; i < tailleTableau - 1; i++){
        for(int j = 0; j < tailleTableau - i - 1; j++){
            if(tableau[j] > tableau[j + 1]){
            // On ajoute & pour passer dans la fonction l'adresse mémoire pour éviter que la valeur soit modifiée uniquement dans la fonction InverseValeurTableau
            InverserValeurTableau(&tableau[j], &tableau[j+1]);
            }
        }
    }

    // Affichage tableau trié dans l'ordre croissant
    for (int i = 0; i < tailleTableau; i++) {
        std::cout << tableau[i] << " ";
    }

    std::cout << std::endl;
}

void TriDecroissant(std::vector<int>& tableau, int tailleTableau) {
    std::cout << "Ordre décroissant : " << std::endl;
    for(int i = 0; i < tailleTableau - 1; i++){
        for(int j = 0; j < tailleTableau - i - 1; j++){
            if(tableau[j] < tableau[j + 1]){
            // On ajoute & pour passer dans la fonction l'adresse mémoire pour éviter que la valeur soit modifiée uniquement dans la fonction
            InverserValeurTableau(&tableau[j], &tableau[j+1]);
            }
        }
    }

    // Affichage tableau trié dans l'ordre décroissant
    for (int i = 0; i < tailleTableau; i++) {
        std::cout << tableau[i] << " ";
    }
    std::cout << std::endl;
}