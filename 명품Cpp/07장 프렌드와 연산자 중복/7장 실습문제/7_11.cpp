/* 11. Stack 클래스 만들기
푸시 <<, 팝 >>, 스텍이 비었는지! 연산자 작성하기
*/

#include <iostream>
using namespace std;

class Stack {
	int* arr;
	int size;
	int empty;
public:
	Stack(int size = 10) {
		this->arr = new int[size];
		this->size = 10;
		this->empty = 0;
	}
	~Stack() { delete[] this->arr; }

	// isEmpty
	bool operator! () { return this->empty == 0; }
	// PUSH
	Stack& operator<< (int i) {
		if (empty < size) {
			this->arr[empty] = i;
			empty++;
		}
		else cout << "!!FULL!!" << endl;
		return *this;
	}
	// pop
	Stack& operator>> (int& x) {
		if (!(*this)) cout << "!!EMPTY!!" << endl;
		else {
			empty--;
			x = arr[empty];
		}
		return *this;
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}