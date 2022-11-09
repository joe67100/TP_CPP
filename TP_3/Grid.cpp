#include <iostream>
#include <vector>

#include "Grid.h"
#include "Player.h"
#include "TicTacToe.h"
#include "PowerFour.h"

Grid::Grid(const int _LINES_NUMBER, const int _COLUMNS_NUMBER) : LINES_NUMBER(_LINES_NUMBER), COLUMNS_NUMBER(_COLUMNS_NUMBER)
{
	init();
}

Grid::~Grid()
{}


void Grid::init()
{
	// Initialisation du vecteur avec des 0
	grid.assign(LINES_NUMBER, std::vector<int>(COLUMNS_NUMBER, 0));
}

void Grid::displayGrid() const 
{
	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < COLUMNS_NUMBER; i++) {
		std::cout << "\033[36m" << i << "\033[0m";
	}
	std::cout << std::endl;

	for (int i = 0; i < LINES_NUMBER; i++)
	{
		std::cout << "\033[36m" << i  << "\033[0m" << "|";
		for (int j = 0; j < COLUMNS_NUMBER; j++)
		{
			
			if (grid[i][j] == 0)
			{
				std::cout << "\x1B[31m#\033[0m";
			}
			else if (grid[i][j] == 1)
			{
				std::cout << "\x1B[34mX\033[0m";
			}
			else if (grid[i][j] == 2)
			{
				std::cout << "\x1B[32m0\033[0m";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Grid::isCaseEmpty(const int _line, const int _column) const 
{
	// == 0 car le vecteur est initialisé à 0
	return grid[_line][_column] == 0;
}

bool Grid::isWinner(const Player& _player) const
{
	// Un joueur gagne si une colonne, une ligne ou une diagonale est complétée 
	return (isLineFull(_player) || isColumnFull(_player) || isDiagonalFull(_player));
}

bool Grid::isDraw(const Player& _player1, const Player& _player2) const
{
	// Vérifier uniquement que la grille est pleine ne suffit pas. Il existe des cas où la grille est pleine avec un gagnant. 
	return !isWinner(_player1) && !isWinner(_player2) && isGridFull();
}

bool Grid::isGridFull() const 
{
	// Vérifie si chaque case si elle est pleine
	for (int i = 0; i < LINES_NUMBER; i++) 
	{
		for (int j = 0; j < COLUMNS_NUMBER; j++)
		{
			if (isCaseEmpty(i, j))
			{
				return false;
			}
		}
	}
	return true;
}