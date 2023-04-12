// 메뉴번호와 사람 수를 입력받고 이를 출력하는 프로그램
// 예외처리: 다른 번호를 입력한 경우, 오류임을 알리고 재주문 받는다(continue) 

#include <iostream>
using namespace std;

bool isInputError();
void ErrorMessage() {
	cout << "다시 주문하세요!!" << endl;
}

int main() {
	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	int num_menu, people = 0;						// 입력받을 메뉴번호와 사람수
	char menu[3][7] = { "짬뽕", "짜장", "군만두" };	// 출력 용도
	
	while (1) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>  ";
		cin >> num_menu;
		if (isInputError()) {	// 1. 메뉴에 문자열 입력오류가 발생한 경우, 에러임을 알리고 루프문 다시 돌기
			continue;
		}

		if (num_menu == 4) {	// 2. 메뉴에 종료(4) 입력시, 종료
			cout << "오늘 영업은 끝났습니다." << endl;
			return 0;
		}

		else if (num_menu == 1 || num_menu == 2 || num_menu == 3) {	// 3. 메뉴를 제대로 주문(1~3)시, 인원 수 묻기
			cout << "몇인분?";							// 인원 수 묻기
			cin >> people;	
			if (!isInputError() && people > 0) {		// 인원 수도 제대로 입력시, 상태 출력하고 다시 주문받는 루프 시작
				cout << menu[num_menu - 1] << " " << people << "인분 나왔습니다" << endl;
				continue;
			}
		}
		// 4. 주문을 1, 2, 3, 4로 입력안했거나, 인원 수를 1이상의 자연수로 입력하지 않은 경우
		cout << "다시 주문하세요!!" << endl;
		continue;								// 다시 주문받기
	}

	return 0;
}

bool isInputError() {
	if (cin.fail()) {	// 입력스트림이 오류상태인 경우
		cin.clear();	// 입력스트림의 상태를 정상으로 초기화하고
		cin.ignore(100, '\n');	// 입력버퍼값을 개행문자 전까지 100자 삭제
		cout << "다시 주문하세요!!" << endl;
		return true;	// 참 반환
	}
	else
		return false;	// 거짓 반환
}


/*
* #include <iostream>
#include <cstring>
using namespace std;

bool checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우 대처. 부록 C의 예제 C-1참고
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}

int main() {
	int menu; // 1~4
	int num; // 몇인분

	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	while (true) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>  ";
		cin >> menu;
		if (checkInputError()) continue; // menu에 정수 외 다른 입력하였는지 검사

		if (menu < 1 || menu > 4) {
			cout << "다시 주문하세요!!" << endl;
			continue;
		}
		else if (menu == 4) {
			cout << "오늘 영업은 끝났습니다." << endl;
			return 0;
		}

		// 입력이 정상적으로 이루어졌다면
		cout << "몇인분?";
		cin >> num;
		if (checkInputError()) continue; // num에 정수 외 다른 입력하였는지 검사
		if (num < 1) {
			cout << "다시 주문하세요!!" << endl;
			continue;
		}
		switch (menu) {
			case 1:
				cout << "짬뽕 " << num << "인분 나왔습니다" << endl;
				break;
			case 2:
				cout << "짜장 " << num << "인분 나왔습니다" << endl;
				break;
			case 3:
				cout << "군만두 " << num << "인분 나왔습니다" << endl;
				break;
		}
	}
}
*/