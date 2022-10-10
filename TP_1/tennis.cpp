#include <iostream>
#include <string>

#include "tennis.hpp"

void calculPoints(int gagnantCoup, int nbPoints[]){

    int autreJoueur = !gagnantCoup;

    switch(nbPoints[gagnantCoup]){
        case 0: case 15:
            nbPoints[gagnantCoup] += 15;
            break;
        case 30:
            nbPoints[gagnantCoup] += 10;
            break;
        case 40:
            if(nbPoints[autreJoueur] == 40)
            {
                nbPoints[gagnantCoup] = 42;
            } 
            else if (nbPoints[autreJoueur] == 42)
            {
                nbPoints[autreJoueur] = 40;
            } 
            else 
            {
                nbPoints[gagnantCoup] = 69;
            }
            break;
        case 42:
            nbPoints[gagnantCoup] = 69;
            break;
        default:
            break;
    }
}

void affichageResultats(int nbPoints[], int joueur){

    if(nbPoints[joueur] == 69)
    {
        std::cout << "Le joueur " << joueur + 1 << " a gagné le jeu !" << std::endl;
    } 
    else if(nbPoints[joueur] == 42)
    {
        std::cout << "Le joueur " << joueur + 1<< " a l'avantage, il doit gagner la prochaine balle pour l'emporter" << std::endl;
    } 
    else {
        std::cout << "Le joueur " << joueur + 1 << " a " << nbPoints[joueur] << " points !" << std::endl;
    }
}