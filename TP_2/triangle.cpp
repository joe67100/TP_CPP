#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "point.h"
#include "triangle.h"

Triangle::Triangle(const Point& _point1, const Point& _point2, const Point& _point3):
	pointA(_point1),
	pointB(_point2),
	pointC(_point3)
	{ }

void Triangle::afficher() const {
	std::cout << "Point A : " << getPointA();
	std::cout << " Point B : " << getPointB();
	std::cout << " Point C : " << getPointC();
	
	std::cout << std::endl;
	std::cout << "Longueur AB : " << getLengthAB() << std::endl;
	std::cout << "Longueur AC : " << getLengthAC() << std::endl;
	std::cout << "Longueur BC : " << getLengthBC() << std::endl;

	std::cout << "Base (plus grand cote) : " << base() << std::endl;
	std::cout << "Hauteur : " << height() << std::endl;
	std::cout << "Surface : " << surface() << std::endl;

	if (isIsocele()) {
		std::cout << "Le triangle est isocele. " << std::endl;
	}
	if (isEquilateral()) {
		std::cout << "Le triangle est equilateral. " << std::endl;
	}
	if (isRectangle()) {
		std::cout << "Le triangle est rectangle." << std::endl;
	}
}

// Getters 
inline Point Triangle::getPointA() const{
	return pointA;
}

inline Point Triangle::getPointB() const {
	return pointB;
}

inline Point Triangle::getPointC() const {
	return pointC;
}

inline float Triangle::getLengthAB() const {
	return longueurs(pointA, pointB);
}

inline float Triangle::getLengthAC() const {
	return longueurs(pointA, pointC);
}

inline float Triangle::getLengthBC() const {
	return longueurs(pointB, pointC);
}

// Setters
void Triangle::setPointA(const Point& _pointA) {
	pointA = _pointA;
}

void Triangle::setPointB(const Point& _pointB) {
	pointB = _pointB;
}

void Triangle::setPointC(const Point& _pointC) {
	pointC = _pointC;
}


float Triangle::longueurs(const Point& _point1, const Point& _point2) const {
	return sqrt(pow(_point2.x - _point1.x, 2) + pow(_point2.y - _point1.y, 2));
}

// Le côté le plus grand correspondra à la base du triangle
inline float Triangle::base() const {
	if (getLengthAB() > getLengthAC() && getLengthAB() > getLengthBC()) {
		return getLengthAB();
	}
	else if (getLengthAC() > getLengthAB() && getLengthAC() > getLengthBC()) {
		return getLengthAC();
	}
	return getLengthBC();
}

// Calcul de la surface sans utiliser la hauteur (formule de Héron)
inline float Triangle::surface() const {
	const float s = (getLengthAB() + getLengthAC() + getLengthBC()) / 2;
	return sqrt(s * (s - getLengthAB()) * (s - getLengthAC()) * (s - getLengthBC()));
}

inline float Triangle::height() const {
	return (2 * surface()) / base();
}

// Méthodes vérifiant la nature du rectangle
inline bool Triangle::isEquilateral() const {
	// Un triangle équilatéral a les trois côtés de même longueur. Si AB = AC et AB = BC alors AC = BC et le triangle est équilatéral
	return getLengthAB() == getLengthAC() && getLengthAB() == getLengthBC();
}

inline bool Triangle::isIsocele() const {
	// Un triangle isocèle possède deux côtés de même longueur
	return getLengthAB() == getLengthAC() || getLengthAB() == getLengthBC() || getLengthAC() == getLengthBC();
}

inline bool Triangle::isRectangle() const {
	// On vérifie pour chaque angle si le carré de la longueur de l'hypoténuse (côté opposé à l'angle droit) est égal à la somme des carrés des deux autres côtés (pythagore)
	return pow(getLengthAB(), 2) == pow(getLengthAC(), 2) + pow(getLengthBC(), 2) ||
		pow(getLengthAC(), 2) == pow(getLengthAB(), 2) + pow(getLengthBC(), 2) ||
		pow(getLengthBC(), 2) == pow(getLengthAB(), 2) + pow(getLengthAC(), 2);
}