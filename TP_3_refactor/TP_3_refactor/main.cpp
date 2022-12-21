// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

#include "Player.h"
#include "Game.h"
#include "Grid.h"

void Clear()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__lin ux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

std::string gameChoice()
{
	std::string userInput;
	std::cout << "A quel jeu souhaitez-vous jouer ?" << std::endl;
	std::cout << "1 - TicTacToe" << std::endl;
	std::cout << "2 - Puissance 4" << std::endl;
	std::cout << "3 - Othello" << std::endl;
	std::cout << "4 - Je ne veux plus jouer..." << std::endl;
	std::cout << "-> ";
	std::cin >> userInput;

	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input invalide... un peu d'effort" << std::endl;
		std::cout << "-> ";
		std::cin >> userInput;
	}
	return userInput;
}

void launchGame()
{
	std::string userInput = gameChoice();

	// Lancement des différents jeux en fonction du choix de l'utilisateur
	if (userInput == "1")
	{
		std::cout << " ########## TIC TAC TOE ##########" << std::endl;
		Game game(new TicTacToe);
	}
	else if (userInput == "2")
	{
		std::cout << "########## POWER 4 ##########" << std::endl;
		Game game(new PowerFour);
	}
	else if (userInput == "3")
	{
		std::cout << "########## OTHELLO ##########" << std::endl;
		Game game(new Othello);
	}
	else if (userInput == "4")
	{
		std::cout << std::endl;
		std::cout << "Fin du programme. Fermeture" << std::endl;
		exit(0);
	}
	else
	{
		Clear();
		std::cout << "Input invalide... Un peu d'effort" << std::endl;
		std::cout << std::endl;
		launchGame();
	}
}

int main(const int argc, const char* argv[])
{
	bool replay = true;
	while (replay)
	{ 
		launchGame();
	}
	return 0;
}
