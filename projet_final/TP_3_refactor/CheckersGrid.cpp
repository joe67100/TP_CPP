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

bool CheckersGrid::setToken(const int _playerId, const Token& _token)
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