#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle
{
public:
	Rectangle(const int _length, const int _width);
	~Rectangle()=default;
	
	void afficher() const;

	// Getters	
	inline int getLength() const;
	inline int getWidth() const;
	inline Point getTopLeftCorner() const;

	// Setters
	void setLength(const int _length);
	void setWidth(const int _width);

	
	inline int perimeter() const;
	inline int area() const;

	// Bonus :
	bool isPerimeterGreater(const Rectangle& rectangle) const;
	bool isAreaGreater(const Rectangle& rectangle) const;
	
private:
	// Attributes
	int length, width;
	Point topLeftCorner;
};

#endif // !RECTANGLE_H
