#include <iostream>

#include "point.h"

void operator << (std::ostream& os, const Point& point) {
	os << "(" << point.x << ", " << point.y << ")";
}
