#include <vector>
#include <string>
#include <iostream>

#include "OthelloGrid.h"

OthelloGrid::OthelloGrid() : Grid(8, 8)
{
	initOthello();
}

OthelloGrid::~OthelloGrid()
{
}

bool OthelloGrid::setToken(const int _playerId, const Token& _token)
{
	if (isValidMove(_token.line, _token.column, _playerId) || isCaseEmpty(_token.line, _token.column))
	{
		grid[_token.line][_token.column] = _playerId;
		flippingLine(_token.line, _token.column, _playerId);
		flippingColumn(_token.line, _token.column, _playerId);
		flippingDiagonal(_token.line, _token.column, _playerId);
		return true;
	}
	return false;
}


bool OthelloGrid::isLineFull(const Player& _player) const
{
	return false;
}

bool OthelloGrid::isColumnFull(const Player& _player) const
{
	return false;
}

bool OthelloGrid::isDiagonalFull(const Player& _player) const
{
	return false;
}

void OthelloGrid::initOthello() {
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

bool OthelloGrid::isValidMove(int x, int y, const Player& _player)
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

void OthelloGrid::flippingColumn(int x, int y, const Player& _player)
{
	int i = 1;
	while (x + i < 8 && grid[x + i][y] != 0 && grid[x + i][y] != _player.getId())
	{
		i++;
	}
	if (x + i < 8 && grid[x + i][y] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x + j][y] = _player.getId();
		}
	}
	i = 1;
	while (x - i >= 0 && grid[x - i][y] != 0 && grid[x - i][y] != _player.getId())
	{
		i++;
	}
	if (x - i >= 0 && grid[x - i][y] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x - j][y] = _player.getId();
		}
	}
}

void OthelloGrid::flippingDiagonal(int x, int y, const Player& _player)
{
	int i = 1;
	while (x + i < 8 && y + i < 8 && grid[x + i][y + i] != 0 && grid[x + i][y + i] != _player.getId())
	{
		i++;
	}
	if (x + i < 8 && y + i < 8 && grid[x + i][y + i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x + j][y + j] = _player.getId();
		}
	}
	i = 1;
	while (x - i >= 0 && y - i >= 0 && grid[x - i][y - i] != 0 && grid[x - i][y - i] != _player.getId())
	{
		i++;
	}
	if (x - i >= 0 && y - i >= 0 && grid[x - i][y - i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x - j][y - j] = _player.getId();
		}
	}
	i = 1;
	while (x + i < 8 && y - i >= 0 && grid[x + i][y - i] != 0 && grid[x + i][y - i] != _player.getId())
	{
		i++;
	}
	if (x + i < 8 && y - i >= 0 && grid[x + i][y - i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x + j][y - j] = _player.getId();
		}
	}
	i = 1;
	while (x - i >= 0 && y + i < 8 && grid[x - i][y + i] != 0 && grid[x - i][y + i] != _player.getId())
	{
		i++;
	}
	if (x - i >= 0 && y + i < 8 && grid[x - i][y + i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x - j][y + j] = _player.getId();
		}
	}
}

void OthelloGrid::flippingLine(int x, int y, const Player& _player)
{
	int i = 1;
	while (y + i < 8 && grid[x][y + i] != 0 && grid[x][y + i] != _player.getId())
	{
		i++;
	}
	if (y + i < 8 && grid[x][y + i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x][y + j] = _player.getId();
		}
	}
	i = 1;
	while (y - i >= 0 && grid[x][y - i] != 0 && grid[x][y - i] != _player.getId())
	{
		i++;
	}
	if (y - i >= 0 && grid[x][y - i] == _player.getId())
	{
		for (int j = 1; j < i; j++)
		{
			grid[x][y - j] = _player.getId();
		}
	}
}