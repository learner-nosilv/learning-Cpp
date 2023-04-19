#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles;		// static ����� ��ü���� üũ
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; }	// �Ҹ�� ��ü �� ����
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; }	// static ������� �� ��ȯ
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;					// ��ü ������ ī��Ʈ++
}

int Circle::numOfCircles = 0;		// ** 0���� �ʱ�ȭ **

int main() {
	Circle* p = new Circle[10];		// CircleŬ������ ��ü10���� �迭�� ���� & ������ p
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;		// ��ü 10�� �����߹Ƿ� 10 ���

	delete[]p;	// ��ü 10���� �� �迭 ���� �Ҹ�
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;		// 10�� ���� �Ҹ�����Ƿ� 0 ���

	Circle a;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;		// ��ü 1�� �����߹Ƿ� 1 ���
	
	Circle b;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircles() << endl;		// ��ü 1�� �� �����߹Ƿ� 2 ���
	return 0;
}