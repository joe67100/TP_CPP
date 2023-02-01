#include "CheckersGrid.h"

CheckersGrid::CheckersGrid() : Grid(10,10)
{
	initCheckers();
}

CheckersGrid::~CheckersGrid()
{
}

bool CheckersGrid::isLineFull(const Player& _player) const
{
	return false;
}

bool CheckersGrid::isColumnFull(const Player& _player) const
{
	return false;
}

bool CheckersGrid::isDiagonalFull(const Player& _player) const
{
	return false;
}

bool CheckersGrid::isValidMove(int x, int y, const Player& _player)
{
	return false;
}

void CheckersGrid::initCheckers()
{
	// init pions jeu de dames
}

void CheckersGrid::flippingLine(int x, int y, const Player& _player)
{
	
}

void CheckersGrid::flippingColumn(int x, int y, const Player& _player)
{

}

void CheckersGrid::flippingDiagonal(int x, int y, const Player& _player)
{

}

bool CheckersGrid::setToken(const int _playerId, const int _column, const int _lines)
{
	if (isCaseEmpty(_lines, _column))
	{
		grid[_lines][_column] = _playerId;
		flippingColumn(_column, _lines, _playerId);
		flippingLine(_column, _lines, _playerId);
		flippingDiagonal(_column, _lines, _playerId);
		return true;
	}
	return false;
}