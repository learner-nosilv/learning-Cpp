/* 3. big() 을 호출하는 main함수를 보고 (1) function overloading 구현 (2) default parameter 구현
	big(int a, int b, int 상한선): a와 b중 큰 값을 구하고, 그 값이 상한선을 넘지않으면 리턴, 상한을 넘으면 상한선리턴
*/
#include <iostream>
using namespace std;

int big(int a, int b, int max=100) {
	int bigger = (a > b ? a : b);
	bigger = (bigger > max ? max : bigger);
	return bigger;
}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;

	return 0;
}