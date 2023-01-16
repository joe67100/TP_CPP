#ifndef OTHELLO_H
#define OTHELLO_H

#include "Grid.h"

class Othello : public Grid
{
public:
	Othello();
	~Othello();


private:
	bool isLineFull(const Player& _player) const override;
	bool isColumnFull(const Player& _player) const override;
	bool isDiagonalFull(const Player& _player) const override;
	bool isValidMove(int x, int y, const Player& _player);
	void initOthello();
	void flipping(int x, int y, const Player& _player);
	bool addToken(const int _playerId, const int _column, const int _lines = NO_LINES) override;
};

#endif // !OTHELLO_H
