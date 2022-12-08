#include <iostream>
#include <string>
#include <algorithm>

#include "Player.h"
#include "Game.h"
#include "Grid.h"
#include "TicTacToe.h"
#include "PowerFour.h"

Game::Game(Grid* _grid) : player1(ID_PLAYER_1), player2(ID_PLAYER_2), grid(_grid)
{
	init();
}
Game::~Game()
{
	delete grid;
}

void Game::init()
{
	playersInformation();
	gameInformation();

	grid->displayGrid();

	bool playerPlayed = false;
	bool closeGame = false;
	while (!closeGame)
	{
		for (int i = 1; i <= NUMBER_OF_PLAYERS; i++)
		{
			if (closeGame)
			{
				break;
			}
			while (!playerPlayed)
			{
				playerPlayed = playerPlays(i);
				if (!playerPlayed)
				{
					std::cout << "Input error. Try again" << std::endl;
					std::cout << std::endl;
				}
			}
			grid->displayGrid();
			closeGame = isGameFinished();
			playerPlayed = false;
		}
	}
}

void Game::playersInformation()
{
	std::cout << std::endl;
	for (int i = 1; i <= NUMBER_OF_PLAYERS; i++)
	{
		std::string name;
		std::cout << "Joueur " << i << ", veuillez indiquer votre nom : ";
		std::cin >> name;
		if (i == 1)
		{
			player1.setName(name);
		}
		else
		{
			player2.setName(name);
		}
	}
}
void Game::gameInformation() const
{
	std::cout << std::endl;
	std::cout << "Joueur 1 : " << player1.getName() << " (X)" << " - " << "Joueur 2 : " << player2.getName() << " (O)" << std::endl;
}

bool Game::isGameFinished() const
{
	if (isDraw(player1, player2))
	{
		std::cout << "Aucun gagnant ! Egalite parfaite." << std::endl;
		std::cout << std::endl;
		return true;
	}
	else if (isWinner(player1))
	{
		std::cout << "Congrats ! " << player1.getName() << " remporte cette partie !" << std::endl;
		std::cout << std::endl;
		return true;
	}
	else if (isWinner(player2))
	{
		std::cout << "Congrats ! " << player1.getName() << " remporte cette partie !" << std::endl;
		std::cout << std::endl;
		return true;
	}
	return false;
}

bool Game::playerPlays(const int _player)
{
	std::string name;
	if (_player == 1)
	{
		name = player1.getName();
	}
	else
	{
		name = player2.getName();
	}

	int col = 0;
	std::string inputCol;

	if (dynamic_cast<PowerFour*>(grid) != 0)
	{
		std::cout << name << ", veuillez renseigner une colonne : ";
		std::cin >> inputCol;

		if (!isNumber(inputCol))
		{
			return false;
		}
		col = std::atoi(inputCol.c_str());

		if (!isInputValid(col))
		{
			return false;
		}
		return grid->addToken(_player, col);
	}
	else if (dynamic_cast<TicTacToe*>(grid) != 0)
	{
		int line = 0;
		std::string inputLine;

		std::cout << name << ", veuillez renseigner une ligne : ";
		std::cin >> inputLine;
		std::cout << std::endl;
		std::cout << "Veuillez renseigner une colonne : ";
		std::cin >> inputCol;
		std::cout << std::endl;

		if (!isNumber(inputLine) || !isNumber(inputCol))
		{
			return false;
		}
		line = std::atoi(inputLine.c_str());
		col = std::atoi(inputCol.c_str());

		if (!isInputValid(line) || !isInputValid(col))
		{
			return false;
		}
		return grid->addToken(_player, col, line);
	}
}

bool Game::isNumber(const std::string& s) const
{
	return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

bool Game::isInputValid(const int input) const
{
	if (input >= 0 && input < grid->getColumnsNumber())
	{
		return true;
	}
	return false;
}

bool Game::isWinner(const Player& _player) const
{
	// Un joueur gagne si une colonne, une ligne ou une diagonale est complétée 
	return (grid->isLineFull(_player) || grid->isColumnFull(_player) || grid->isDiagonalFull(_player));
}

bool Game::isDraw(const Player& _player1, const Player& _player2) const
{
	// Vérifier uniquement que la grille est pleine ne suffit pas. Il existe des cas où la grille est pleine avec un gagnant. 
	return !isWinner(_player1) && !isWinner(_player2) && grid->isGridFull();
}