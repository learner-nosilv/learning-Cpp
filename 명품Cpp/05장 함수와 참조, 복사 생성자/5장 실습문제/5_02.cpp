/* 2.
* main() 함수와 실행결과를 참고하여 half() 함수 작성하기
* 호출문 half(n) : n의 반값을 구해서 n으로 바꾸기
*	n으로 호출하므로 call by address 불가능 -> reference 사용
*/

#include <iostream>
using namespace std;

void half(double& num) {
	num /= 2.0;
}

int main() {
	double n = 20;
	half(n);
	cout << n;
	return 0;
}
// [book solution]과 핵심은 동일