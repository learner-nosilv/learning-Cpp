/* 3, 4 Abstract Class LoopAdder�� ��ӹ޴� Ŭ���� ForLoopAdder, WhileLoopAdder, DoWhileLoopAdder�� �ۼ��ϱ�*/
#include <iostream>
#include <string>
using namespace std;

class LoopAdder {	// Abstract Class
	string name;	// ������ �̸�
	int x, y, sum;	// x + y = sum
	void read();	// x, y�� �Է¹ޱ�
	void write();	// sum�� ���
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;		// [���������Լ�]
public:
	void run();
};

void LoopAdder::read() {				// x, y�� �Է¹ޱ�
	cout << name << ':' << endl;
	cout << "ó�� ������ �ι�° �� ���� ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}

void LoopAdder::write() {				// sum�� ���
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

void LoopAdder::run() {
	read();					// x, y�� �Է¹ޱ�
	sum = calculate();		// [���������Լ�] �����Ѵ�� ����
	write();				// ��� sum�� ���
}

class ForLoopAdder :public LoopAdder {
protected:
	virtual int calculate() {
		int result = getX();
		for (int i = result + 1; i <= getY(); i++)
			result += i;
		return result;
	}
public:
	ForLoopAdder(string name = "") :LoopAdder(name) {}
};

class WhileLoopAdder :public LoopAdder {
protected:
	virtual int calculate() {
		int result = getX();
		int next = result + 1;
		while (next <= getY()) {
			result += next;
			next++;
		}
		return result;
	}
public:
	WhileLoopAdder(string name = "") :LoopAdder(name) {}
};

class DoWhileLoopAdder :public LoopAdder {
protected:
	virtual int calculate() {
		int result = 0;
		int next = getX();
		do {
			result += next;
			next++;
		} while (next <= getY());
		return result;
	}
public:
	DoWhileLoopAdder(string name = "") :LoopAdder(name) {}
};

int main() {
	cout << "3. -----------------------" << endl;
	ForLoopAdder forLoop("For Loop");
	forLoop.run();

	cout << "4. -----------------------" << endl;
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	whileLoop.run();
	doWhileLoop.run();

	return 0;
}