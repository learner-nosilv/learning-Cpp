#include <iostream>
#include "3_9_Oval.h"

// 생성자
Oval::Oval(int w, int h) {
	width = w;
	height = h;
}

// 소멸자: 소멸을 알리고 + 멤버변수 출력(show()함수 재사용)
Oval::~Oval() {
	std::cout << "Oval 소멸 : ";
	show();
}

// 멤버변수 리턴
int Oval::getWidth() { return width; }
int Oval::getHeight() { return height; }

// 멤버변수 변경
void Oval::set(int w, int h) {
	width = w;
	height = h;
}

// 멤버변수 콘솔출력
void Oval::show() {
	std::cout << "width = " << width << ", height = " << height << std::endl;
	}