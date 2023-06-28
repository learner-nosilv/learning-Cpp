/* 8. Circle Ŭ���� �������� �����Ͽ� << >> �����ڸ� �ۼ��ϰ�, Ŭ������ �����Ͽ� ���α׷��ϼ��ϱ�
* cin>>Circle��ü�� ��������Ҵ���� �Ϸ�, cout <<Circle��ü�� ��ü�������
*	class Circle;
	istream& operator >> (istream& ins, Circle& a);
	ostream& operator << (ostream& outs, Circle a);
*/
#include <iostream>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}
	friend istream& operator >> (istream& ins, Circle& a);
	friend ostream& operator << (ostream& outs, Circle a);
};

istream& operator >> (istream& ins, Circle& a) {
	string name;
	int radius;
	while (true) {
		cout << "������ >> ";
		cin >> radius;
		if (cin.fail()) {
			cout << "'����'�� �Է��ϼ���.\n";
			cin.clear();
			cin.ignore(99, '\n');
		}
		else if (radius <= 0)
			cout << "������ ������ ������ �������� �ʽ��ϴ�.\n";
		else break;
	}
	a.radius = radius;

	cout << "�̸�>> ";
	cin >> a.name;

	return ins;
}

ostream& operator << (ostream& outs, Circle a) {
	outs << "(��������" << a.radius << "�� " << a.name << ')';
	return outs;
}

int main() {
	Circle d, w;
	cin >> d >> w;			// Ű���� �Է��� �޾� ��ü d�� w�� �ϼ�
	cout << d << w << endl; // ��ü d, w ���
	return 0;
}