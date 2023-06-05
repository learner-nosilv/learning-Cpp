#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "09_10_Shape.h"
class Rect : public Shape {
protected:
	virtual void draw() { std::cout << "Rectangle" << std::endl; }
};
#endif // !RECT_H