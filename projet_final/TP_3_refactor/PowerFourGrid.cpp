#include <vector>
#include <string>
#include <iostream>

#include "PowerFourGrid.h"

PowerFourGrid::PowerFourGrid() : Grid(4, 7)
{}

PowerFourGrid::~PowerFourGrid()
{}

bool PowerFourGrid::setToken(const int _playId, const int _column, const int _line)
{
	for (int i = LINES_NUMBER - 1; i >= 0; i--)
	{
		if (isCaseEmpty(i, _column))
		{
			grid[i][_column] = _playId;
			return true;
		}
	}
	return false;
}

bool PowerFourGrid::isLineFull(const Player& _player) const
{
	for (int i = 0; i < LINES_NUMBER; i++)
	{
		for (int j = 0; j < COLUMNS_NUMBER - 3; j++)
		{
			if (grid[i][j] == _player.getId() && grid[i][j + 1] == _player.getId() && grid[i][j + 2] == _player.getId() && grid[i][j + 3] == _player.getId())
			{
				return true;
			}
		}
	}
	return false;
}

bool PowerFourGrid::isColumnFull(const Player& _player) const
{
	for (int j = 0; j < COLUMNS_NUMBER; j++)
	{
		for (int i = 0; i < LINES_NUMBER - 3; i++)
		{
			if (grid[i][j] == _player.getId() && grid[i + 1][j] == _player.getId() && grid[i + 2][j] == _player.getId() && grid[i + 3][j] == _player.getId())
			{
				return true;
			}
		}
	}
	return false;
}

bool PowerFourGrid::isDiagonalFull(const Player& _player) const
{
	for (int i = 0; i < LINES_NUMBER - 3; i++)
	{
		for (int j = 0; j < COLUMNS_NUMBER - 3; j++)
		{
			if (grid[i][j] == _player.getId() && grid[i + 1][j + 1] == _player.getId() && grid[i + 2][j + 2] == _player.getId() && grid[i + 3][j + 3] == _player.getId())
			{
				return true;
			}
		}
	}

	for (int i = COLUMNS_NUMBER - 1; i > 2; i--)
	{
		for (int j = 0; j < LINES_NUMBER - 3; j++)
		{
			if (grid[j][i] == _player.getId() && grid[j + 1][i - 1] == _player.getId() && grid[j + 2][i - 2] == _player.getId() && grid[j + 3][i - 3] == _player.getId())
			{
				return true;
			}
		}
	}
	return false;
}

