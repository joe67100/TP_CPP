#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include <math.h>

class Cercle
{
public:
	Cercle(const int _diametre, const Point& _centre);
	~Cercle() = default;

	void afficher() const;
	
	// Getters
	inline int getDiametre() const;
	inline Point getCentre() const;

	// Setters 
	void setDiametre(const int _diametre);
	void setCentre(const Point& _centre);

	
	inline float perimeter() const;
	inline float area() const;
	
	// Pas de inline car paramètre externe à la classe
	bool isOnCircle(const Point& point) const; 
	bool isInsideCircle(const Point& point) const;

private:
	// Attributes
	Point centre;
	int diametre;
};

#endif // !CERCLE_H
