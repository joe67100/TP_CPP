#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <algorithm>

#include "Player.h"
#include "TicTacToe.h"
#include "PowerFour.h"
#include "Othello.h"

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

	// Vérification victoire 
	bool isWinner(const Player& player) const;
	bool isDraw(const Player& player1, const Player& player2) const;
	
	
	// Grid
	Grid* grid;
};

#endif // !GAME_H