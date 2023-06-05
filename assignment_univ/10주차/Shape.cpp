#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::paint() {			// �׸��� : �������̵��� �����ϰ� �ϱ����� �Լ�
	draw();						// Pure virtual function
}

Shape* Shape::add(Shape *p) {	// linked-list: �� Shape��ü�� ����Ű�� ���� Shape��ü ���� & ���� Shape��ü�� �ּҰ� ����
	this->next = p;				// Shape��ü�� ��������� ������(next)�� ����Ű�� ��ü�� �ش� �Լ��� �Ķ������ Shape��ü�� ���� 
	return p;					// �Ķ������ Shape��ü �ּ� ����
}