#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요." << endl;

	// 1. 로미오와 줄리엣의 수를 입력받는다.
	string s, t;
	cout << "로미오>>";
	cin >> s;
	cout << "줄리엣>>";
	cin >> t;

	// 2. 누가 이기고 졌는지 판단하고 출력한다.
	if (s == t)
		cout << "비겼습니다" << endl;
	else if ((s == "가위" && t == "보") || (s == "바위" && t == "가위") || (s == "보" && t == "바위"))
		cout <<"로미오가 이겼습니다." << endl;
	else
		cout << "줄리엣이 이겼습니다." << endl;

	return 0;
}
