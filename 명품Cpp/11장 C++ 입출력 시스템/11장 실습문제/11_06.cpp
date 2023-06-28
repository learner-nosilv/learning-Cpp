/* 6. 필드간격 15칸, 빈칸_로 채우기, 유효숫자 3자리*/
#include <iostream>
#include <iomanip>			// 매개변수가 있는 조작자
#include <cmath>			// 제곱근을 구하는 함수 sqrt
using namespace std;

int main() {
	cout.setf(ios::left);	// [flag] left-align
	cout << setw(15) << "Number" << setw(15) << "Square" << setw(15) << "Square Root" << endl;
	for (int i = 0; i < 50; i += 5) {
		cout << setw(15) << setfill('_') << i;									// Number
		cout << setw(15) << setfill('_') << i * i;								// Square
		cout << setw(15) << setfill('_') << setprecision(3) << sqrt(i) << '\n';	// Square Root
	}
	return 0;
}