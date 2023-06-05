/* 5. ������ ��ȸ�ο����� �⺻���� ����Ʈ(OR AND XOR)�� AbstractGateŬ������ ��ӹ��� Ŭ������� �����ϱ� */
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
	virtual bool operation() { return (getX() || getY()); }	// [Pure Virtual Function]�� ����
};

class ANDGate :public AbstractGate {
public:
	virtual bool operation() { return (getX() && getY()); }	// [Pure Virtual Function]�� ����
};

class XORGate :public AbstractGate {
public:
	virtual bool operation() { return (getX() || getY()) && (!(getX() && getY())); }	// [Pure Virtual Function]�� ����
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);	// ��� format�� iosŬ������ boolalpha (�Ҹ����� ���ڿ�����)�� ����
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
	return 0;
}