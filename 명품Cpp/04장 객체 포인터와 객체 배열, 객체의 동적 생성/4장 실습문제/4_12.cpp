/* 12.
* Circle Ŭ���� > �̸�, ������
* CircleManager Ŭ���� > Circle Ŭ������ �迭�� ����
* 
* �����Լ�:
* Ű����� ���� ���� �Է¹ޱ�
* �� ������ŭ ���� �̸��� ������ �Է¹ޱ�
* ������ ���� ����ǵ��� Ŭ������ �����Լ� �ۼ�
*/

#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;	// Circle ��ü�迭 ������
	int size;	// Circle ��ü�迭 ũ��
public:
	CircleManager(int size) { this->size = size; p = new Circle[size]; }
	~CircleManager() { delete[] p; }
	void searchByName();
	void searchByArea();
	void setCircle(int index, string name, int radius);
};

void CircleManager::searchByName() {
	string name;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;

	int index = -1;
	for (int i = 0; i < size; i++) {
		if ((p + i)->getName() == name) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "�׷� �̸��� ���� �����ϴ�." << endl;
	}
	else {
		cout << name << "�� ������ " << (p + index)->getArea() << endl;
	}
}

void CircleManager::searchByArea() {
	int cutline;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> cutline;
	cout << cutline << "���� ū ���� �˻��մϴ�." << endl;

	for (int i = 0; i < size; i++) {
		double area = (p + i)->getArea();
		if (area > cutline) {
			cout << (p + i)->getName() << "�� ������ " << area << ",";
		}
	}
	cout << endl;
}

void CircleManager::setCircle(int index, string name, int radius) {
	(p + index)->setCircle(name, radius);
}

int main() {
	int num;
	cout << "���� ���� >> ";
	cin >> num;

	CircleManager twelve(num);

	for (int i = 0; i < num; i++) {
		string name;
		int radius;
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		twelve.setCircle(i, name, radius);
	}

	twelve.searchByName();

	twelve.searchByArea();

	return 0;
}