/* 3, 4 Abstract Class LoopAdder을 상속받는 클래스 ForLoopAdder, WhileLoopAdder, DoWhileLoopAdder를 작성하기*/
#include <iostream>
#include <string>
using namespace std;

class LoopAdder {	// Abstract Class
	string name;	// 루프의 이름
	int x, y, sum;	// x + y = sum
	void read();	// x, y값 입력받기
	void write();	// sum값 출력
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;		// [순수가상함수]
public:
	void run();
};

void LoopAdder::read() {				// x, y값 입력받기
	cout << name << ':' << endl;
	cout << "처음 수에서 두번째 수 까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write() {				// sum값 출력
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
	read();					// x, y값 입력받기
	sum = calculate();		// [순수가상함수] 정의한대로 연산
	write();				// 결과 sum값 출력
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