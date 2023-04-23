/* 9.
클래스 Accumulator는 add()함수를 통해 계속 값을 누적하는 클래스 - 구현하기
*/

#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n);
	int get() { return value; }
};

Accumulator& Accumulator::add(int n) {
	value += n;		// 현 객체의 value 변경
	return *this;	// 현 객체 리턴
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);	// add()가 실 객체를 리턴해야함
	cout << acc.get();
	return 0;
}

// solution이랑 완전 동일 ㄷㄷ 