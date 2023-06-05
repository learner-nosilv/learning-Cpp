/* 5. 디지털 논리회로에서의 기본적인 게이트(OR AND XOR)를 AbstractGate클래스를 상속받은 클래스들로 구현하기 */
#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	bool getX() { return x; }
	bool getY() { return y; }
	virtual bool operation() = 0;	// [Pure Virtual Function]
};

class ORGate :public AbstractGate {
public:
	virtual bool operation() { return (getX() || getY()); }	// [Pure Virtual Function]의 구현
};

class ANDGate :public AbstractGate {
public:
	virtual bool operation() { return (getX() && getY()); }	// [Pure Virtual Function]의 구현
};

class XORGate :public AbstractGate {
public:
	virtual bool operation() { return (getX() || getY()) && (!(getX() && getY())); }	// [Pure Virtual Function]의 구현
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);	// 출력 format을 ios클래스의 boolalpha (불린값의 문자열형태)로 설정
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
	return 0;
}