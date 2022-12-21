#include <vector>
#include <string>
#include <iostream>

#include "Othello.h"

Othello::Othello() : Grid(8, 8)
{
	initOthello();
}

Othello::~Othello()
{
}

bool Othello::addToken(const int _playerId, const int _column, const int _lines)
{
	if (isValidMove(_column, _lines, _playerId))
	{
		grid[_lines][_column] = _playerId;
		// flipping(_column, _lines, _playerId);
		return true;
	}
	return false;
}


bool Othello::isLineFull(const Player& _player) const
{
	return false;
}

bool Othello::isColumnFull(const Player& _player) const
{
	return false;
}

bool Othello::isDiagonalFull(const Player& _player) const
{
	return false;
}

void Othello::initOthello() {
	for (int i = 0; i < LINES_NUMBER; i++)
	{
		for (int j = 0; j < COLUMNS_NUMBER; j++)
		{
			grid[i][j] = 0;
		}
	}
	grid[3][3] = 1;
	grid[3][4] = 2;
	grid[4][3] = 2;
	grid[4][4] = 1;
}

bool Othello::isValidMove(int x, int y, const Player& _player)
{
	if (x < 0 || x > 7 || y < 0 || y > 7)
	{
		return false;
	}
	if (grid[x][y] != 0)
	{
		return false;
	}
	if (x > 0 && grid[x - 1][y] == _player.getId())
	{
		return true;
	}
	if (x < 7 && grid[x + 1][y] == _player.getId())
	{
		return true;
	}
	if (y > 0 && grid[x][y - 1] == _player.getId())
	{
		return true;
	}
	if (y < 7 && grid[x][y + 1] == _player.getId())
	{
		return true;
	}
	if (x > 0 && y > 0 && grid[x - 1][y - 1] == _player.getId())
	{
		return true;
	}
	if (x < 7 && y < 7 && grid[x + 1][y + 1] == _player.getId())
	{
		return true;
	}
	if (x > 0 && y < 7 && grid[x - 1][y + 1] == _player.getId())
	{
		return true;
	}
	if (x < 7 && y > 0 && grid[x + 1][y - 1] == _player.getId())
	{
		return true;
	}
	return false;
}

void Othello::flipping(int x, int y, const Player& _player)
{
	// TODO : implement
}