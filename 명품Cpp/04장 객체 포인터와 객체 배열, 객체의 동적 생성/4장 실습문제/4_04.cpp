/* 4.
* 다음 main() 함수가 실행되도록 Sample 클래스를 완성하라.
* 
* Sample 클래스
* 0) 멤버변수: 배열 포인터 변수 p, 배열의 크기 size
* 1) 매개변수가 1개인 생성자 : int형 배열 p 동적생성
* 2) 멤버함수 void read() : 키보드로 정수배열 입력받아서 배열 p의 원소에 할당하기
* 3) 멤버함수 void write() : 배열의 모든 원소 화면 출력
* 4) 멤버함수 int big() : 원소 중 가장 큰 수 리턴
* 5) 소멸자 : 동적생성된 배열 p 반환
*/

#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {			// 1) 매개변수가 1개인 생성자 : int형 배열 p 동적생성
		size = n;
		p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++)
		cin >> *(p + i);
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << *(p + i)<< ' ';
	cout << endl;
}

int Sample::big() {
	int biggest = *(p);
	for (int i = 1; i < size; i++) {
		if (biggest < *(p + i))
			biggest = *(p + i);
	}
	return biggest;
}

Sample::~Sample() {
	delete[] p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
	return 0;
}