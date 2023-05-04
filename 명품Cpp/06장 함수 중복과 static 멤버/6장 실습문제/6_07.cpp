/* 7. 다음과 같은 static 멤버를 가진 Ramdom 클래스 완성하기
* Random 클래스를 이용하여 다음과 같이 랜덤한 값을 출력하는 main()함수도 작성하기
* seed()는 main()에서 활용하기
* 
* 1. 랜덤정수: rand(max-min+1) + min
* 2. 랜덤문자: 'a'-'z', 'A'-'Z'
*/
#include <iostream>	// 표준입출력 관련
#include <cstdlib>	// random 관련
using namespace std;

class Random {
public:
	// 항상 다른 랜덤수를 발생시키기 위한 seed를 설정하는 함수
	static void seed() { srand((unsigned)time(NULL)); }	// 랜덤패턴을 결정하는 seed설정
	static int nextInt(int min = 0, int max = 32767);	// min - max 사이(끝 포함)의 랜덤정수리턴
	static char nextAlphabet();							// 랜덤알파벳 리턴
	static double nextDouble();							// 0이상 1미만인 0.- 형태의 랜덤실수리턴
};

int Random::nextInt(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

char Random::nextAlphabet() {
	if (rand() % 2)	// 0 or 1
		return ((rand() % ('z' - 'a' + 1)) + 'a');
	else
		return ((rand() % ('Z' - 'A' + 1)) + 'A');
}

double Random::nextDouble() {
	double result= (double)rand() / RAND_MAX;
	return (result != 1 ? result : nextDouble()); // (RAND_MIN~RAND_MAX) / RAND_MAX = [0~1]
}

int main() {
//	Random a;					// 랜덤 정수/실수를 발생시킬 수 있는 클래스 객체 안 만들어도 되네

	int size = 10;				// 랜덤 정수, 문자, 실수 갯수
	int min = 1, max = 100;		// 랜덤 정수 범위

	Random::seed();

	cout << min << "에서 " << max << "까지 랜덤한 정수 " << size << "개를 출력합니다" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextInt(min, max)<< ' ';
	cout << endl;

	cout << "알파벳을 랜덤하게 " << size << "개를 출력합니다" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "랜덤한 실수 " << size << "개를 출력합니다" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;

	return 0;
}