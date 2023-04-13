/* 교수님 픽
* 구상: Random 클래스만들기
* 멤버변수: ?
* 멤버함수:	생성자, next(), nextInRange(int, int)
*
* 필요한 헤더
	1. <cstdlib> random 관련(srand rand RAND_MAX, ...)
	2. <ctime> time()
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	int next();
	int nextInRange(int l, int h);
};

int Random::next() {
	return rand();
}

int Random::nextInRange(int l, int h) {
	if (l > h) {			// 입력오류처리1. 오류임을 알리고 프로그램 종료 
		cout << "!!입력오류!!" << endl;
		exit(1);
	}
	return l + (rand() % (h - l + 1));
}

// -----------------------------------------------

class EvenRandom {
public:
	int next();
	int nextInRange(int l, int h);
};

int EvenRandom::next() {
	int even_num = 0;
	while (1) {
		even_num = rand();
		if ((even_num % 2) == 0)
			return even_num;
	}
}

int EvenRandom::nextInRange(int l, int h) {
	if (l > h) {			// 입력오류처리2. 뒤바꾸기
		int temp = l;
		l = h;
		h = l;
	}
	else if (l % 2 != 0) {
		l++;
	}
	int even_num = (h - l + 2) / 2;				// (예) l, h가 2, 3이면 1 / 2, 4이면 2 / 2, 5이면 2
	even_num = l + (rand() % even_num) * 2;		// (예) num이 1이면 2 + 0, 2이면 2 + (0, 2)

	return even_num;
}

int main() {
	srand((unsigned)time(NULL));

	Random r;
	EvenRandom er;

	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}