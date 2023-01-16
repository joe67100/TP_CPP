#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include <iostream>

#include "Player.h"

class Grid
{
public:
	Grid(const int _COLUMNS_NUMBER, const int _LINES_NUMBER);
	~Grid();

	void init();
	void displayGrid() const;
	bool virtual addToken(const int _playerId, const int _column, const int _line = NO_LINES) = 0;

	inline int getColumnsNumber() { return COLUMNS_NUMBER; };
	inline int getLinesNumber() { return LINES_NUMBER; };
	int getNumberOfTokens(const Player& _player);

	// Boolean
	bool isCaseEmpty(const int _line, const int _column) const;
	bool isGridFull() const;

	// Virtual functions
// Vérifie chaque lignes, colonnes et diagonales
	bool virtual isLineFull(const Player& _player) const = 0;
	bool virtual isColumnFull(const Player& _player) const = 0;
	bool virtual isDiagonalFull(const Player& _player) const = 0;

protected:
	const int COLUMNS_NUMBER;
	const int LINES_NUMBER;
	const static int NO_LINES = -50;
	std::vector<std::vector<int>> grid;
};

#endif
