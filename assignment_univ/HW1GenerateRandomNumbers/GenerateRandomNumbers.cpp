#include <iostream>	// 표준 입출력 라이브러리
#include <cstdlib>	// 난수 생성을 위해 srand(), rand(), RAND_MAX 사용
#include <ctime>	// 난수 생성 패턴을 결정하는 seed로 해당 라이브러리의 time() 사용

using namespace std;

//3.5
// 임의의 정수를 랜덤하게 제공하는 클래스
class Random {
public:
	Random();							// 생성자
	int next();							// 0이상 32767이하의 임의의 정수를 반환하는 함수
	int nextInRange(int low, int high);	// low이상 high이하의 임의의 정수를 반환하는 함수
};

// 생성자는 아무런 일을 하지 않는다 (=기본생성자)
Random::Random() {
	// srand((unsigned)time(0)); 초 단위로 변화하는 time(0)을 seed로 객체 생성시 난수생성패턴결정
	// 프로그램은 초 단위 미만으로 객체를 생성하므로 seed인 time(0)값이 변하지않는다.
	// = 모든 객체의 난수생성패턴이 동일해진다.
	// 따라서, 생성자에 위 코드를 사용하는 것보다는 main에서 한번 사용해주는 것이 적절하다고 판단
}

// 멤버함수 next는 0이상 32767이하 임의의 정수를 리턴한다
int Random::next() {
	return rand();	// 0~32767 사이의 난수 리턴
}

// 멤버함수 nextInRange는 low~high 사이의 임의의 정수를 리턴한다
int Random::nextInRange(int low, int high) {
	// 원리	1. 0~32767 사이의 난수를 N 으로 나눈 나머지, 즉 0 ~ (N-1) 사이의 난수로 스케일링한다.
	//		2. low를 더한다
	//		3. N을 high-low+1로 하면, 최종적으로 난수의 범위는 low~high 사이의 정수가 된다.

	int gap = high - low + 1;

	if (gap <= 0) {						// 만일 입력이 잘못된 경우(low > high),
		cout << "!!입력오류!!" << endl;	//	 에러임을 알리고
		exit(1);						//	 프로그램을 종료한다. (1=비정상종료)
	}

	int num = (rand() % gap) + low;		// 0 ~ (high-low) 사이의 난수에 low를 더하여 원하는 범위(low~high)의 난수를 만든다.
	return num;							// low~high 사이의 난수를 리턴한다
}
/* [학교 솔루션과 동일]
	int Random::nextInRange(int low, int high) {
		int range = (high - low) + 1;
		return low + (rand() % range); // low와 high 사이의 랜덤 정수를 리턴한다. 
*/


//3.6
// 임의의 짝수를 랜덤하게 제공하는 클래스 (0도 짝수로 처리한다)
class EvenRandom {
public:
	EvenRandom();
	int next();							// 0이상 32767이하의 임의의 짝수를 반환하는 함수
	int nextInRange(int low, int high);	// low이상 high이하의 임의의 짝수를 반환하는 함수
};

// 생성자는 아무런 일을 하지 않는다 (=기본생성자)
EvenRandom::EvenRandom() {
}

// 멤버함수 next는 0이상 32766이하 임의의 짝수를 리턴한다
int EvenRandom::next() {
	int num = rand();	// num: 0이상 32767이하의 임의의 정수
	num /= 2;			// num: 0이상 16383이하의 임의의 정수
	num *= 2;			// num: 0이상 32766이하의 임의의 "짝수" (num = (rand()/2)*2; 와 동일)
	return num;			// 0이상 32766이하의 임의의 짝수를 리턴한다.
}
/* [학교 솔루션은 if(랜덤값이 짝수일때 리턴하기)를 반복하는 방식]
* int EvenRandom::next() {
	while (true) {
		int n = rand();
		if (n % 2 == 0) return n;
	}
}
*/

// 멤버함수 nextInRange는 low이상 high이하 임의의 짝수를 리턴한다
int EvenRandom::nextInRange(int low, int high) {
	int gap = high - low ;

	if (gap < 0) {						// 만일 입력이 잘못된 경우(low > high),
		cout << "!!입력오류!!" << endl;	//	 에러임을 알리고
		exit(1);						//	 프로그램을 종료한다. (1=비정상종료)
	}

	gap++;	// gap = high-low+1

	int num = rand() % gap;	// num: 0이상 high-low이하의 임의의 정수
	num /= 2;				// num: 0이상 high-low/2이하의 임의의 정수 (high-low가 홀수인 경우, high-low-1/2)
	num *= 2;				// num: 0이상 high-low이하의 임의의 "짝수" (high-low가 홀수인 경우, high-low-1)
	num += low;				// num: low이상 high이하의 임의의 짝수 (high-low가 홀수인 경우, high-1)
	return num;				// low이상 high이하 임의의 짝수인 num을 리턴한다
}
/* [학교 솔루션은 if(...위와 동일]
int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	while (true) {
		int n = low + (rand() % range);
		if (n % 2 == 0) return n;
	}
}
*/


// main: 0~32767사이의 랜덤정수, 2~4사이의 랜덤정수, 두 범위의 랜덤짝수를 콘솔에 출력한다
int main() {
	// 0. rand()의 seed 설정: 프로그램을 돌릴 때 time(0)를 seed로 하여 난수패턴이 결정된다.
	srand((unsigned) time(0));	// 1970년 1월 1일 0시 0분 0초 ~ 현재의 시간차 time(0)를 강제형변환하여 rand()의 seed로 설정

	// 1. 임의의 정수를 리턴할 수 있는 객체 r 생성
	Random r;

	// 2. range가 0 ~ RAND_MAX인 임의의 정수 10회 콘솔 출력하기, 따라서 멤버함수 next 사용
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;	// RAND_MAX는 rand()의 반환값 중 최댓값(32767)
	for (int i = 0; i < 10; i++) {	// 아래 두 문장을 10회 반복
		int n = r.next();			//	 0 ~ RAND_MAX의 임의의 정수를 n에 할당
		cout << n << ' ';			//	 n 과 공백문자 출력
	}

	// 3. range가 2 ~ 4인 임의의 정수 10회 콘솔 출력하기, 따라서 멤버함수 nextInRange 사용
	cout << endl<<endl<< "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {		// 아래 두 문장을 10회 반복
		int n = r.nextInRange(2, 4);	//	 2 ~ 4의 임의의 정수를 n에 할당
		cout << n << ' ';				//	 n 과 공백문자 출력
	}
	cout << endl;						// 개행

	cout << "-------------------------------------------------------" << endl;
	cout << endl;

	// 4. 임의의 짝수를 리턴할 수 있는 객체 er 생성 
	EvenRandom er;

	// 5. range가 0 ~ RAND_MAX인 임의의 짝수 10회 콘솔 출력하기, 따라서 멤버함수 next 사용
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {	// 아래 두 문장을 10회 반복
		int n = er.next();			//	 0 ~ RAND_MAX의 임의의 짝수를 n에 할당
		cout << n << ' ';			//	 n 과 공백문자 출력
	}

	// 6. range가 2 ~ 10인 임의의 짝수 10회 콘솔 출력하기, 따라서 멤버함수 nextInRange 사용
	cout << endl << endl << "-- 2에서 " << "10 까지의 짝수 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {		// 아래 두 문장을 10회 반복
		int n = er.nextInRange(2, 10);	//	 2 ~ 10의 임의의 짝수를 n에 할당
		cout << n << ' ';				// 	 n 과 공백문자 출력
	}
	cout << endl;

	return 0;
}



/* [학교 솔루션]
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
*/