#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "09_10_Shape.h"
class Circle : public Shape {
protected:
	virtual void draw() { std::cout << "Circle" << std::endl; }
};
#endif // !CIRCLE_H