#include <iostream>

#include "point.h"
#include "rectangle.h"

// Const 

const int ABSCISSE = 0; // Pour le coin supérieur gauche, la valeur sur l'axe des abscisse est toujours égale à 0

// Methods
Rectangle::Rectangle(const int _length, const int _width):
	length(_length), 
	width(_width), 
	topLeftCorner({ABSCISSE, static_cast<float>(_width)})
	{ }

void Rectangle::afficher() const {
	std::cout << "Longueur du rectangle :" << std::endl;
	std::cout << getLength() << std::endl;

	std::cout << "Largeur du rectangle :" << std::endl;
	std::cout << getWidth() << std::endl;

	std::cout << "Aire du rectangle :" << std::endl;
	std::cout << area() << std::endl;

	std::cout << "Perimetre du rectangle : " << std::endl;
	std::cout << perimeter() << std::endl;

	std::cout << "Position du coin superieur gauche (x, y):" << std::endl;
	std::cout << getTopLeftCorner();
	std::cout << std::endl;
}

// Getters
inline int Rectangle::getLength() const {
	return length;
}
inline int Rectangle::getWidth() const {
	return width;
}
inline Point Rectangle::getTopLeftCorner() const {
	return topLeftCorner;
}

// Setters
void Rectangle::setLength(const int _length) {
	length = _length;
}
void Rectangle::setWidth(const int _width) {
	width = _width;
	topLeftCorner.y = (float)_width;
}


inline int Rectangle::area() const {
	return length * width;
}

inline int Rectangle::perimeter() const {
	return (length * 2) + (width * 2);
}

// Fonctions de comparaison entre 2 rectangles

bool Rectangle::isPerimeterGreater(const Rectangle& rectangle) const {
	return perimeter() > rectangle.perimeter();
}

bool Rectangle::isAreaGreater(const Rectangle& rectangle) const {
	return area() > rectangle.area();
}

