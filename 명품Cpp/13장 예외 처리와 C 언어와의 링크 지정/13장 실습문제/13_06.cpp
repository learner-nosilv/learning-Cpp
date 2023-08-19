/* 연습문제 6. concat()함수 작성하기
	배열 a, b를 연결한 새로운 배열을 생성하여 리턴하는 함수
	예외: 메모리부족시
	예외: 두 배열 중 하나라도 NULL인 경우
	예외: sizea, b를 음수로 적은 경우 int 타입의 예외 발생 */
#include <iostream>
using namespace std;

int* concat(int a[], int sizea, int b[], int sizeb) throw (int) {
	if (sizea <= 0 || sizeb <= 0) throw 1;
	if (a == NULL || b == NULL) throw 2;
	int* result = new int[sizea + sizeb];
	int idx = 0;
	for (; idx < sizea; idx++)
		result[idx] = a[idx];
	for (int i = 0; i < sizeb; i++, idx++)
		result[idx] = b[i];
	return result;
}

int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	int y[] = { 10, 20, 30, 40 };
	try {
		int* p = concat(x, 5, y, 4);
		for (int n = 0; n < 9; n++) cout << p[n] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (int failCode) {
		cout << "오류 코드 : " << failCode << endl;
	}
	return 0;
}