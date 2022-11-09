#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <algorithm>


#include "Player.h"
#include "Grid.h"
#include "TicTacToe.h"
#include "PowerFour.h"

class Game
{
public:
	Game(Grid* grid);
	~Game();

private:
	const int NUMBER_OF_PLAYERS = 2;
	static const int ID_PLAYER_1 = 1;
	static const int ID_PLAYER_2 = 2;
	Player player1;
	Player player2;

	// Fonction qui permet de lancer le jeu
	void init();

	void playersInformation();
	void gameInformation() const;

	bool playerPlays(const int player);
	bool isGameFinished() const;

	// Vérification des input
	bool isNumber(const std::string& s) const;
	bool isInputValid(const int input) const;

	// Grid
	Grid* grid;
};

#endif // !GAME_H