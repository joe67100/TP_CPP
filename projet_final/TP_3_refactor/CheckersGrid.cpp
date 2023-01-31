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