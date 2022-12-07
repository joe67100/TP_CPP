#include <iostream>

#include "Player.h"

Player::Player(const int _id) : id(_id)
{}

Player::~Player()
{}

void Player::setName(const std::string _name)
{
	name = _name;
}