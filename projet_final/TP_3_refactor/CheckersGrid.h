#ifndef CHECKERS_H
#define CHECKERS_H

#include "Grid.h"

class CheckersGrid : public Grid
{
public:
	CheckersGrid();
	~CheckersGrid();


private:
	bool isLineFull(const Player& _player) const override;
	bool isColumnFull(const Player& _player) const override;
	bool isDiagonalFull(const Player& _player) const override;
	bool isValidMove(int x, int y, const Player& _player);
	void initCheckers();
	void flippingLine(int x, int y, const Player& _player);
	void flippingColumn(int x, int y, const Player& _player);
	void flippingDiagonal(int x, int y, const Player& _player);
	bool setToken(const int _playerId, const int _column, const int _lines = NO_LINES) override;
};

#endif // !CHECKERS_H
