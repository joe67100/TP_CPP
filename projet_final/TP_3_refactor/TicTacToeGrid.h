#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>
#include <iostream>

#include "Player.h"
#include "Grid.h"

class TicTacToeGrid : public Grid
{
public:
	TicTacToeGrid();
	~TicTacToeGrid();
private:
	bool isLineFull(const Player& _player) const override;
	bool isColumnFull(const Player& _player) const override;
	bool isDiagonalFull(const Player& _player) const override;

	bool setToken(const int _playerId, const Token& _token) override;
};


#endif // !TICTACTOE_H