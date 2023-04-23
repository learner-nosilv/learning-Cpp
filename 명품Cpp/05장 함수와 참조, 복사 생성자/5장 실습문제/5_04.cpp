/* 4.
* bool bigger(int a, int b, int& big)
* return a==b;
* big = a>b ? a : b ;
*/

#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	big = a > b ? a : b;
	return a == b;
}

int main() {
	int result = 0;
	cout << result <<" - > ";
	bigger(10, 100, result);
	cout << result;
	return 0;
}

// [Book solution] 과 핵심적인 차이 X