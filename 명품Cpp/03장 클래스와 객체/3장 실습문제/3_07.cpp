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

class SelectableRandom {
	int table;
public:
	// 생성자: 객체를 생성할 때, 짝수생성(t=0)인지 홀수생성(t=1)인지 설정하도록 함
	SelectableRandom(int t) {
		table = t;
	}
	int next();
	int nextInRange(int l, int h);
};

int SelectableRandom::next() {
	int even_num = (rand() / 2) * 2;	// 0~32767사이의 짝수생성
	switch (table) {	// 짝수/홀수 생성객체 체크
	case 0:				// 짝수생성객체라면,
		return even_num;		// 그대로 리턴
	case 1:				// 홀수생성객체라면,
		return even_num + 1;	// 1을 더해서 리턴
	}
}

int SelectableRandom::nextInRange(int l, int h) {
	if (l > h) {
		int temp = l;
		l = h;
		h = temp;
	}

	switch (table) {
		case 0:
			if (l % 2 == 1) {
				l++;
			}
				
		case 1:
			if (l % 2 == 0) {
				l++;
			}
		return l + 2 * (rand() % ((h - l + 2) / 2));
	}
}

int main() {
	srand((unsigned)time(NULL));

	SelectableRandom even_rand(0);	// 짝수 랜덤 객체
	SelectableRandom odd_rand(1);	// 홀수 랜덤 객체

	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = even_rand.next();
		cout << n << ' ';
	}

	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = odd_rand.nextInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}