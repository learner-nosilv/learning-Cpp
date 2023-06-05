/*
   FILE NAME : Sol2HWCh8Ch9.cpp
   AUTHOR : -
   YYYYMMDD : 2023.05.14
   PURPOSE :
   �����ð��� ����� �Ͱ� ����,
	1. 8 �� ���ǽ� ������ 1,2 ���� ����� ��� �����ϴ� C++ ���α׷��� �ۼ��ϰ� �� ��°���� �����Ͻÿ�.

*/

/* 1, 2. Circle Ŭ������ ��ӹ޴� NamedCircle�� �ۼ��ϱ�
*/
#include <iostream>												// ǥ�� ����� ���̺귯��
#include <string>												// ���ڿ� ���̺귯��
using namespace std;											// C++ ǥ��

class Circle {													// �� Ŭ����
	int radius;													// ������
public:
	Circle(int radius = 0) { this->radius = radius; }			// ������: ������� radius �Ҵ�
	int getRadius() { return this->radius; }					// Return �������radius
	void setRadius(int radius) { this->radius = radius; }		// Assign �������radius
	double getArea() { return 3.14 * radius * radius; }			// Return �� ����
};

class NamedCircle : public Circle {								// �� Ŭ������ ��ӹ޴� �̸��ִ� �� Ŭ����
	string name;												// �̸�
public:
	NamedCircle(int radius=0, string name = "") : Circle(radius) { this->name = name; }	// ������: ������� name �Ҵ�
	void show() { cout << "�������� " << getRadius() << "�� " << name << endl; }			// �ܼ����: �������� radius�� name
	void setName(string name) { this->name = name; }									// Assign ������� name
	string getName() { return this->name; }												// Return ������� name
};

int main() {
	NamedCircle waffle(3, "waffle");							// �������� 3, �̸��� "waffle"�� NamedCircleŬ���� ��ü waffle ����
	waffle.show();												// �ܼ����: �������� 3�� waffle
	cout << "---P8.1----------------------------------------------" << endl;

	NamedCircle pizza[5];										// NamedCircleŬ���� ��ü�迭 pizza ����, ũ�� 5��
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;	// �Է¹ޱ�
	for (int i = 0; i < 5; i++) {								// 5ȸ
		int radius;						// ������
		string name;					// �̸�
		cout << i + 1 << ">> ";			// 1>>
		cin >> radius;					// ������ �Է¹ޱ�
		cin >> name;					// �̸� �Է¹ޱ�(������X)
		pizza[i].setRadius(radius);		// Assign �������radius
		pizza[i].setName(name);			// Assign ������� name
	}

	int widest = 0;													// ��ü���� pizza�� ���� �� ���� ���� ���� ������ INDEX
	for (int i = 1; i < 5; i++) {									// ��� ���� ���캸��
		if (pizza[widest].getRadius() < pizza[i].getRadius())		//	�������� ū ������ INDEX��
			widest = i;												//	widest�� �Ҵ�
	}
	cout << "���� ������ ū ���ڴ� " << pizza[widest].getName() << "�Դϴ�" << endl;	// ���� ���� �� ���
	cout << "---P8.2----------------------------------------------" << endl;
	return 0;
}