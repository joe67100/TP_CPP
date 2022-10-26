#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point
{
	float x;
	float y;
	void friend operator << (std::ostream&, const Point&);
};

#endif // !POINT_H