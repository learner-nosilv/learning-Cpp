#ifndef GE_H
#define GE_H
#include <vector>
#include <string>
#include "Shape.h"

class GE {
	std::vector<Shape*> v;
	int getAnswer(std::string menu[], int size);
	void insertShape();
	void removeShape();
	void drawAll();
public:
	GE() {}
	~GE();
	void run();
};
#endif // !GE_H
