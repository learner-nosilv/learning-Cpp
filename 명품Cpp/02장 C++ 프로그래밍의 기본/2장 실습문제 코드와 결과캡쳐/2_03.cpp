#include <iostream>
using namespace std;

// IN: 두 수를 입력받아서
// COMPUTE: 크기를 비교하여
// OUT: 큰 수를 출력한다

int main() {
	int max, num;				// 두 수 선언
	cout << "두 수를 입력하라>>";
	cin >> max >> num;			// 두 수 입력받기
	
	if (max < num) max = num;	// 큰 수를 max에 할당

	cout << "큰 수 = " << max;	// 큰 수 출력

	return 0;
}