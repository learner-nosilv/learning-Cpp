/* 연습문제 8. copy()는 int형 배열을 복사하여, 복사본의 포인터를 리턴한다.
	복사가 여의치 않는 경우, 참조 매개변수인 failCode에 적절한 오류코드를 삽입하고 NULL을 리턴한다.
	이 함수의 원형을 고치고 try-catch 블록을 사용하여 수정하라.
	코드가 튼튼하고 단순해진다.
*/
#include <iostream>
using namespace std;

int* copy(int* src, int size) throw(int) {
	if (size < 0) throw (-1);			// too small
	else if (size > 100) throw(-2);		// too big
	else if (src == NULL) throw(-4);	// NULL source
	int* p = new int[size];
	if (p == NULL) throw(-3);			// memory short
	for (int n = 0; n < size; n++) p[n] = src[n];
	return p;
}

int main() {
	int x[] = { 1, 2, 3 };
	try {
		int* p = copy(x, 3);
		for (int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (int failCode) {
		cout << "오류코드 : " << failCode << endl;
	}
	return 0;
}