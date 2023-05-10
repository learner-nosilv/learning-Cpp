/* 10. 통계를 내는 Statistics 클래스
데이터는 int 배열 동적할당
! >> << ~ 연산자 함수 작성하기
*/
#include <iostream>
using namespace std;

class Statistics {
	int size;
	int* arr;
	int empty;
public:
	Statistics() {
		this->size = 7;
		this->arr = new int[this->size];
		this->empty = 0;
	}
	~Statistics() { delete[] arr; }

	// ! : 데이터가 비었는지 논리연산
	bool operator!() { return this->empty == 0; }

	// << : Push the data
	Statistics& operator<<(int i) {
		if (empty < size) {
			*((this->arr) + empty) = i;
			empty++;
		}
		else cout << "!!용량 초과!!" << endl;
		return *(this);
	}

	// >> 평균 출력
	int& operator>>(int& avg);

	// ~ Data전부출력
	void operator~();
};

int& Statistics::operator>>(int& avg) {
	avg = 0;
	if (!(*this)==false) {
		for (int i = 0; i < this->empty; i++)
			avg += *(this->arr + i);
		avg /= this->empty;
	}
	return avg;
}

void Statistics::operator~() {
	for (int i = 0; i < empty; i++)
		cout << this->arr[i] << ' ';
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	
	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
	return 0;
}