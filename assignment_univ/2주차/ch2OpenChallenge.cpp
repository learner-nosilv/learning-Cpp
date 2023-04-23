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
	if (!strcmp(s, t))
		cout << "비겼습니다" << endl;
	else if ((s == "가위" && t == "보") || (s == "바위" && t == "가위") || (s == "보" && t == "바위"))
		cout <<"로미오가 이겼습니다." << endl;
	else
		cout << "줄리엣이 이겼습니다." << endl;

	return 0;
}

/* Solution
// ch2OpenChallenge

#include <iostream>
using namespace std;

int main() {
	cout << "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요." << endl;

	// 입력 받기
	char s[10];
	cout << "로미오>>";
	cin >> s;

	char t[10];
	cout << "줄리엣>>";
	cin >> t;

	// 틀린 입력 골라내기
	if(strcmp(s, "가위") != 0 && strcmp(s, "바위") != 0 && strcmp(s, "보") != 0) {
		cout << "로미오의 입력이 틀렸습니다." << endl;
		return 0;
	}
	if(strcmp(t, "가위") != 0 && strcmp(t, "바위") != 0 && strcmp(t, "보") != 0) {
		cout << "줄리엣의 입력이 틀렸습니다." << endl;
			return 0;
	}

	// 승자 결정
	if(strcmp(s, "가위") == 0 && strcmp(t, "보") == 0)
		cout << "로미오가 이겼습니다." << endl;
	else if(strcmp(s, "가위") == 0 && strcmp(t, "바위") == 0)
		cout << "줄리엣이 이겼습니다." << endl;
	else if(strcmp(s, "바위") == 0 && strcmp(t, "가위") == 0)
		cout << "로미오가 이겼습니다." << endl;
	else if(strcmp(s, "바위") == 0 && strcmp(t, "보") == 0)
		cout << "줄리엣이 이겼습니다." << endl;
	else if(strcmp(s, "보") == 0 && strcmp(t, "바위") == 0)
		cout << "로미오가 이겼습니다." << endl;
	else if(strcmp(s, "보") == 0 && strcmp(t, "가위") == 0)
		cout << "줄리엣이 이겼습니다." << endl;
	else
		cout << "비겼습니다." << endl;
}
*/