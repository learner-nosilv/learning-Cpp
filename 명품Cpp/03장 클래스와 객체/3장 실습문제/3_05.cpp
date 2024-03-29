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
	return l + (rand() % (h - l + 1));
}

int main() {
	srand((unsigned)time(NULL));

	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl;
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}
//-------[BOOK SOLUTION]--------------
/*
* #include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// 임의의 정수를 랜덤하게 제공하는 클래스
class Random {
public:
	Random(); // 생성자. 랜덤 seed를 설정한다.
	int next(); // 랜던 정수를 리턴한다.
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 정수를 리턴한다.
};

Random::Random() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

int Random::next() {
	return rand(); // 0에서 RAND_MAX 사이의 랜덤한 정수 리턴
}

int Random::nextInRange(int low, int high) {
    int range=(high-low)+1;
    return low + (rand() % range); // low와 high 사이의 랜덤 정수를 리턴한다. 
}

int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for(int i=0; i<10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for(int i=0; i<10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}
*/