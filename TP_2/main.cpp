// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "point.h"
#include "rectangle.h"
#include "cercle.h"
#include "triangle.h"

int main(int argc, char const* argv[]) 
{
	//  -- Actions sur Rectangle -- 
	std::cout << "### Rectangle ###" << std::endl;	
	Rectangle rectangle1(6, 4);
	Rectangle rectangle2(4, 3);
	
	std::cout << "Rectangle 1 :" << std::endl;
	std::cout << "-------------" << std::endl;
	rectangle1.afficher();
	
	std::cout << "Rectangle 2 : " << std::endl;
	std::cout << "-------------" << std::endl;
	rectangle2.afficher();
	
	// Comparaison de deux rectangles
	if (rectangle1.isPerimeterGreater(rectangle2)){
		std::cout << "Le perimetre du rectangle 1 est superieur au perimetre du rectangle 2." << std::endl;
	} else {
		std::cout << "Le perimetre du rectangle 1 est inferieur au perimetre du rectangle 2." << std::endl;
	}
	if (rectangle1.isAreaGreater(rectangle2)) {
		std::cout << "L'aire du rectangle 1 est superieur a l'aire du rectangle 2." << std::endl;
	} else {
		std::cout << "L'aire du rectangle 1 est inferieur a l'aire du rectangle 2." << std::endl;
	}
	
	std::cout << "-------------------------" << std::endl;
	
	// -- Actions sur Cercle --
	std::cout << "### Cercle ###" << std::endl;
	Cercle cercle1(5, { 1, 1 });
	cercle1.afficher();
	std::cout << std::endl;
	
	// Vérification de la position d'un point par rapport au cercle
	Point point1({ 0, 0 });
	if (cercle1.isInsideCircle(point1)) {
		std::cout << "Le point (" << point1.x << ", " << point1.y << ") est dans le cercle." << std::endl;
	} else {
		std::cout << "Le point (" << point1.x << ", " << point1.y << ") n'est pas dans le cercle." << std::endl;
	}
	if (cercle1.isOnCircle(point1)) {
		std::cout << "Le point (" << point1.x << ", " << point1.y << ") est sur le cercle." << std::endl;
	} else {
		std::cout << "Le point (" << point1.x << ", " << point1.y << ") n'est pas sur le cercle." << std::endl;
	}
	
	std::cout << "-------------------------" << std::endl;
	
	// Actions sur Triangle
	std::cout << "### Triangle ###" << std::endl;
	Point pointA({ 0, 0 });
	Point pointB({ 0, 3 });
	Point pointC({ 4, 0 });
	Triangle triangle1(pointA, pointB, pointC);
	triangle1.afficher();
	
	return EXIT_SUCCESS;
}