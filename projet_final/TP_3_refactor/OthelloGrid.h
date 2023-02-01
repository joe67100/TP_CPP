#ifndef OTHELLO_H
#define OTHELLO_H

#include "Grid.h"

class OthelloGrid : public Grid
{
public:
	OthelloGrid();
	~OthelloGrid();


private:
	bool isLineFull(const Player& _player) const override;
	bool isColumnFull(const Player& _player) const override;
	bool isDiagonalFull(const Player& _player) const override;
	bool isValidMove(int x, int y, const Player& _player);
	void initOthello();
	void flippingLine(int x, int y, const Player& _player);
	void flippingColumn(int x, int y, const Player& _player);
	void flippingDiagonal(int x, int y, const Player& _player);
	bool setToken(const int _playerId, const Token& _token) override;
};

#endif // !OTHELLO_H
