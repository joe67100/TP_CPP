#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player 
{
public:
	Player(const int _id);
	~Player();

	inline std::string getName() const { return name; };
	inline int getId() const { return id; };
	
	void setName(const std::string _name);
	
private:
	const int id;
	std::string name;
};

#endif // !PLAYER_H
