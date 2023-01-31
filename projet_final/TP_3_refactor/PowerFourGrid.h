#ifndef POWER_FOUR
#define POWER_FOUR

#include <vector>
#include <string>
#include <iostream>

#include "Player.h"
#include "Grid.h"

class PowerFourGrid : public Grid
{
public:
	PowerFourGrid();
	~PowerFourGrid();

private:
	bool isLineFull(const Player& _player) const override;
	bool isColumnFull(const Player& _player) const override;
	bool isDiagonalFull(const Player& _player) const override;

	bool setToken(const int _playerId, const int _column, const int _lines = NO_LINES) override;
};


#endif // !POWER_FOUR