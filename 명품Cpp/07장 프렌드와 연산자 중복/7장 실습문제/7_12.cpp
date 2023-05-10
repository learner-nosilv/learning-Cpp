/* 12. 정수 배열을 항상 증가 순으로 유지하는 SortedArray 클래스를 작성하려고 한다.
* 아래의 main() 함수가 작동할 만큼만 SortedArray 클래스를 작성하고 +와 =연산자도 작성하라
*/

#include <iostream>
using namespace std;

class SortedArray {
	int size;		// 배열크기
	int* p;			// 배열
	void sort();	// 오름차순 정렬
public:
	SortedArray() { this->p = NULL; this->size = 0; }	// 1. 기본생성자
	SortedArray(int p[], int size);						// 2. 생성자: 정렬 안 된 배열
	SortedArray(const SortedArray& src);				// 3. 복사생성자
	~SortedArray() { delete[] p; }						// 소멸자

	void show();										// 객체 내 배열 출력
	SortedArray operator+(SortedArray& op2);			// 두 객체를 합친 객체 값return
	SortedArray& operator=(const SortedArray& op2);		// 동기화 & 현 객체 참조return
	
};

// Private : 오름차순 정렬
void SortedArray::sort() {
	if (this->size <= 1) return;

	for (int i = 0; i < (this->size)-1; i++) {
		for (int j = i + 1; j < (this->size); j++) {
			if ((this->p[i]) > (this->p[j])) {
				int temp = this->p[i];
				this->p[i] = this->p[j];
				this->p[j] = temp;
			}
		}
	}
}

// 2. 생성자: 정렬 안 된 배열
SortedArray::SortedArray(int p[], int size) {
	this->size = size;				// 단순 복사 후,
	this->p = new int[this->size];
	for (int i = 0; i < size; i++) this->p[i] = p[i];
	this->sort();					// 정렬
}

// 3. 복사 생성자
SortedArray::SortedArray(const SortedArray& src) {
	this->size = src.size;
	this->p = new int[this->size];
	for (int i = 0; i < (this->size); i++) this->p[i] = src.p[i];
}

// 객체 내 배열 출력
void SortedArray::show() {
	cout << "배열 출력 :";
	for (int i = 0; i<(this->size); i++)
		cout << ' ' << this->p[i];
	cout << endl;
}

// 두 객체를 합친 객체 값return
SortedArray SortedArray::operator+(SortedArray& op2) {	// 두 객체를 합친 객체 return
	SortedArray temp;
	temp.size = (this->size + op2.size);
	temp.p = new int[temp.size];

	int idx = 0;

	for (int i = 0; i < this->size; i++) {
		temp.p[idx] = this->p[i];
		idx++;
	}
	for (int i = 0; i < op2.size; i++) {
		temp.p[idx] = op2.p[i];
		idx++;
	}
	temp.sort();
	return temp;
}

// 동기화 & 현 객체 참조return
SortedArray& SortedArray::operator=(const SortedArray& op2) {
	delete[] this->p;				// 기존 배열의 동적할당 해제
	this->size = op2.size;
	this->p = new int[this->size];	// 재할당
	for (int i = 0; i < this->size; i++) this->p[i] = op2.p[i];
	return *this;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();

	return 0;
}