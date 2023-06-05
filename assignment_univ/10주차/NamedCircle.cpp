/*
   FILE NAME : NamedCircle.cpp
   AUTHOR : -
   YYYYMMDD : 2023.05.21
   PURPOSE :
	�����ð��� ����� �Ͱ� ����,
	 1. 8�� ���ǽ� ������ 1,2���� ����� ��� �����ϴ� C++ ���α׷��� �ۼ��ϰ� �� ��°���� �����Ͻÿ�.
		�� 1�� �������� �䱸�ϴ� NamedCircleŬ������ 2�� ���� �ַ�� ���α׷����� ����Ͻÿ�.
			1�� �������� �����ϴ� ��°���� ���� �ڵ�� �ۼ����� ����, 2�� ������ ���ÿ�.
		�� 2�� �������� �����ϴ� ��°���� ���� �ַ�� ����, NamedCircle.cpp�� �ۼ��ϴ� �� ÷�ε� ���� ������ ����Ͻÿ�
			: NamedCircle[TEMPLATE].cpp
		�� ������Ʈ ���� �̸����� NamedCircleApplication �� ����Ͻÿ�.
*/

#include <iostream>			// ǥ�� ����� ���̺귯��
#include <string>			// ���ڿ� ���� ���̺귯��
using namespace std;		// C++ ǥ�� ���̺귯���� namespace

class Circle {				// ��
	int radius;				// ������
public:
	Circle(int radius = 0) { this->radius = radius; }			// ������
	int getRadius() { return radius; }						// ������ ����
	void setRadius(int radius) { this->radius = radius; }	// ������ �Ҵ�
	double getArea() { return 3.14 * radius * radius; };		// ������ ����
};

class NamedCircle : public Circle {			// ���� ��ӹ��� derived class 
	string name;							// �̸�
public:
	NamedCircle(int radius, string name);	// ������: Base class Constructor ���� ��, ���� ��
	void set(int radius, string name) {		// �������(�������� �̸�) �Ҵ�
		this->setRadius(radius);			// ������ �Ҵ�: Base Ŭ������ private ����̹Ƿ� setRadius ���
		this->name = name;					// �̸� �Ҵ�
	}
	string getName() { return name; }		// �̸� ����
	void show();							// �ܼ� ��� (�������� radius�� name)
};

NamedCircle::NamedCircle(int radius = 0, string name = "NONAME") : Circle(radius) {
	this->name = name;						// Base class Constructor ���� ��, �ش� ������ ����
}

void NamedCircle::show() {
	cout << "�������� " << getRadius() << "�� " << name << endl;	// �������� Base Ŭ������ private ����̹Ƿ� getRadius ���
}

string biggest(NamedCircle p[], int n) {	// ���� ���� n���� NamedCircle �迭���� ���� ���� ���� �̸� ����
	if (n <= 0)								// �迭�� ���� ���� 0�� ���(=����)
		return "";							// ����

	int big = 0;							// ���� �迭 �� ���� ū ���� Index
	//Find the biggest pizza
	for (int i = 1; i < n; i++) {					// ���� ū �������� ���� ���� Index ã��
		if (p[big].getRadius() < p[i].getRadius())	// �������� ũ�⸸ ���ص�, ���� ���� ���� �Ǵ��� �� �ִ�.
			big = i;								// ���� ū ������ ���� �� ū �������� ���� ���� �����ϸ� big ������Ʈ 
	}
		return p[big].getName();					// ���� �迭���� ���� ū ���� �̸� ����
}

int main() {
	NamedCircle c[5];								// 5���� �� ��ü ���� ����
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {					// 5���� �� ��ü �迭 �Է¹ޱ�
		int r;										// ������
		string name;								// �̸�
		cout << i + 1 << ">> ";
		cin >> r;									// ������ �Է¹ޱ�
		getline(cin, name);							// �̸� �Է¹ޱ�
		if (r <= 0) {								// �Է¹��� �������� ���� ������ �ִ� ���(0, ����)
			cout << "�ٽ� �Է��ϼ���" << endl;
			i--;									// ������ ����۵Ǹ� i�� 1�����ϹǷ�, �ٽ� �Է¹ޱ����� i ����
			continue;								// ���� �����
		}

		c[i].set(r, name);							// �Է¹��� �������� �̸����� �� ��ü �Ҵ�
	}
	cout << "���� ������ ū ���ڴ� " << biggest(c, 5) << "�Դϴ�" << endl;
}