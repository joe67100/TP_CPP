#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "point.h"
#include "cercle.h"

Cercle::Cercle(const int _diametre, const Point& _centre) :
	diametre(_diametre),
	centre(_centre)
	{ }

void Cercle::afficher() const {
	std::cout << "Diametre du cercle : " << std::endl;
	std::cout << getDiametre() << std::endl;

	std::cout << "Aire du cercle : " << std::endl;
	std::cout << area() << std::endl;

	std::cout << "Perimetre du cercle : " << std::endl;
	std::cout << perimeter() << std::endl;

	std::cout << "Position du centre (x, y): " << std::endl;
	std::cout << getCentre();
}

// Getters
inline int Cercle::getDiametre() const {
	return diametre;
}

inline Point Cercle::getCentre() const {
	return centre;
}

// Setters
void Cercle::setDiametre(const int _diametre) {
	diametre = _diametre;
}

void Cercle::setCentre(const Point& _centre) {
	centre = _centre;
}


inline float Cercle::perimeter() const {
	return M_PI * diametre;
}

inline float Cercle::area() const {
	return M_PI * powf((diametre / 2), 2);
}

// Vérifie si le point passé en paramètre se trouve à l'intérieur du cercle
bool Cercle::isInsideCircle(const Point& point) const {
	return sqrt(pow(point.x - centre.x, 2) + pow(point.y - centre.y, 2)) < static_cast<float>(diametre) / 2;
}

// Vérifie si le point passé en paramètre se trouve sur le cercle
bool Cercle::isOnCircle(const Point& point) const {
	return sqrt(pow(point.x - centre.x, 2) + pow(point.y - centre.y, 2)) == static_cast<float>(diametre) / 2;
}
