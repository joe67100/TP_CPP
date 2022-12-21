#include <vector>
#include <string>
#include <iostream>

#include "TicTacToe.h"

TicTacToe::TicTacToe() : Grid(3, 3)
{}

TicTacToe::~TicTacToe()
{}

bool TicTacToe::addToken(const int _playerId, const int _column, const int _line)
{
	if (isCaseEmpty(_line, _column))
	{
		grid[_line][_column] = _playerId;
		return true;
	}
	return false;
}

bool TicTacToe::isLineFull(const Player& _player) const
{
	for (int i = 0; i < LINES_NUMBER; i++)
	{
		if ((grid[i][0] == _player.getId() && grid[i][1] == _player.getId() && grid[i][2] == _player.getId()))
		{
			return true;
		}
	}
	return false;
}

bool TicTacToe::isColumnFull(const Player& _player) const
{
	for (int j = 0; j < COLUMNS_NUMBER; j++)
	{
		if ((grid[0][j] == _player.getId() && grid[1][j] == _player.getId() && grid[2][j] == _player.getId()))
		{
			return true;
		}
	}
	return false;
}

bool TicTacToe::isDiagonalFull(const Player& _player) const
{
	// La case [1][1] doit être remplie dans tous les cas pour que la diagonale soit complète
	return grid[1][1] == _player.getId() &&
		((grid[0][0] == _player.getId() && grid[2][2] == _player.getId()) ||
			(grid[0][2] == _player.getId() && grid[2][0] == _player.getId()));
}