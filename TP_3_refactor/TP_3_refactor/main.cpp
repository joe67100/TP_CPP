// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Player.h"
#include "Game.h"
#include "Grid.h"

// Vériifie si une chaine de caractères est un nombre
bool isInputNumber(const std::string& s)
{
	return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

void displayMenu()
{
	bool replay = true;
	std::string input;
	int whichGame = 0;

	while (replay)
	{
		std::cout << "A quel jeu souhaitez-vous jouer ?" << std::endl;
		std::cout << "1 - TicTacToe" << std::endl;
		std::cout << "2 - Puissance 4" << std::endl;
		std::cout << "3 - Je ne veux plus jouer" << std::endl;
		do {
			std::cout << "-> ";
			std::cin >> input;
			if (isInputNumber(input))
			{
				whichGame = std::atoi(input.c_str());
			}
		} while (whichGame < 1 || whichGame > 3);


		// Lancement des différents jeux en fonction du choix de l'utilisateur
		if (whichGame == 1)
		{
			std::cout.flush();
			std::cout << " ########## TIC TAC TOE ##########" << std::endl;
			Game game(new TicTacToe);
		}
		else if (whichGame == 2)
		{
			std::cout.flush();
			std::cout << "########## POWER 4 ##########" << std::endl;
			Game game(new PowerFour);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Fin du programme. Fermeture" << std::endl;
			replay = false;
		}
	}
}

int main(const int argc, const char* argv[])
{
	displayMenu();

	return 0;
}
