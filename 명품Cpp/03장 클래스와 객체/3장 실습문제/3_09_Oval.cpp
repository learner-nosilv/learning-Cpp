#include <iostream>
#include "3_9_Oval.h"

// ������
Oval::Oval(int w, int h) {
	width = w;
	height = h;
}

// �Ҹ���: �Ҹ��� �˸��� + ������� ���(show()�Լ� ����)
Oval::~Oval() {
	std::cout << "Oval �Ҹ� : ";
	show();
}

// ������� ����
int Oval::getWidth() { return width; }
int Oval::getHeight() { return height; }

// ������� ����
void Oval::set(int w, int h) {
	width = w;
	height = h;
}

// ������� �ܼ����
void Oval::show() {
	std::cout << "width = " << width << ", height = " << height << std::endl;
	}