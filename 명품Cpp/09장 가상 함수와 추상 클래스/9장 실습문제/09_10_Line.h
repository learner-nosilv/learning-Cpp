#ifndef LINE_H
#define LINE_H
#include <iostream>
#include "09_10_Shape.h"
class Line : public Shape {
protected:
	virtual void draw() { std::cout << "Line" << std::endl; }
};
#endif // !LINE_H