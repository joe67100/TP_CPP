#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <math.h>

class Triangle 
{
public:
	Triangle(const Point& _pointA, const Point& _pointB, const Point& _pointC);
	~Triangle() = default;

	void afficher() const;

	// Getters 
	inline Point getPointA() const;
	inline Point getPointB() const;
	inline Point getPointC() const;
	inline float getLengthAB() const;
	inline float getLengthAC() const;
	inline float getLengthBC() const;

	// Setters
	void setPointA(const Point& _pointA);
	void setPointB(const Point& _pointB);
	void setPointC(const Point& _pointC);

	
	inline float base() const;
	inline float height() const;
	float longueurs(const Point& _point1, const Point& _point2) const;
	inline float surface() const;

	inline bool isIsocele() const;
	inline bool isEquilateral() const;
	inline bool isRectangle() const;
	
private:
	// Attributes
	Point pointA, pointB, pointC;
};

#endif // !TRIANGLE_H

