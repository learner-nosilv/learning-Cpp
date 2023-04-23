/*
   FILE NAME :
   AUTHOR :
   YYYYMMDD : |
   PURPOSE : (과제의 목적 – 배포한 과제 내용에서 복사, 편집)
		   2.	3장의 실습문제 3-5,3-6,3-7은 서로 연관이 되어있는 문제들이니, 
		   이들을 다음과 같이 하나의 소스파일로, 작성하여 아래와 같은 출력 결과가 나오도록, 
		   작성하시오. (3-7은 해당 안됨)
*/


#include <iostream>
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
	int range = (high - low) + 1;
	return low + (rand() % range); // low와 high 사이의 랜덤 정수를 리턴한다. 
}

//5.7
// 짝수만 랜덤하게 발생시키는 클래스
class EvenRandom {
public:
	EvenRandom(); // seed 설정
	int next(); // 랜덤 짝수 리턴
	int nextInRange(int low, int high); // low와 high 사이의 랜덤 짝수 리턴
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // 임의의 seed를 설정하여 할 때마다 다른 랜덤 수가 나오게 한다.
}

int EvenRandom::next() {
	while (true) {
		int n = rand();
		if (n % 2 == 0) return n;
	}
}

int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	while (true) {
		int n = low + (rand() % range);
		if (n % 2 == 0) return n;
	}
}



int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;

	EvenRandom er;
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 짝수정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "10 까지의 짝수 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.nextInRange(2, 10); // 2에서 10 사이의 랜덤한 짝수정수
		cout << n << ' ';
	}
	cout << endl;

}