/* 5. 예제 11-3의 코드를 string 으로 재작성하기*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
	while (true) {
		cout << "종료하려면 exit을 입력하세요 >> ";
		getline(cin, cmd);
		if (cmd=="exit") {
			cout << "프로그램을 종료합니다....";
			return 0;
		}
		// else
		//	cin.ignore(1);	// getline은 delimiter전까지 할당하고, delimiter은 삭제
	}
	return 0;
}