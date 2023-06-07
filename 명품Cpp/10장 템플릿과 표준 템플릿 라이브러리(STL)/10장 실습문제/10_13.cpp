/* 13. map 컨테이너를 이용하여
	기능1. 저장: 이름, 성적을 저장하고
	기능2. 검색: 이름으로 성적을 조회하는
	점수관리 프로그램을 만들어라
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class adminScore {
	map<string, int> school;
	int getMenu();
	void insertScore();
public:
	adminScore() {}
	~adminScore() {}
	void run();
};

int adminScore::getMenu() {
	while (true) {
		int menu;
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3)
			return menu;
		else if (cin.fail()) {
			cout << "[입력오류] 1, 2, 3 중에서 입력하세요.\n";
			cin.clear();
			cin.ignore(20, '\n');
		}
		else
			cout << "[입력오류] 1, 2, 3 중에서 입력하세요.\n";
	}
}

void adminScore::insertScore() {
	string tempName;
	int tempScore;
	while (true) {
		cout << "이름과 점수>> ";
		cin >> tempName >> tempScore;
		if (cin.fail()) {											// 경우1. 점수에 정수가 아닌 값을 입력
			cin.clear();
			cin.ignore(50, '\n');
			cout << "(공백없이 이름)+(공백)+(정수) 형식으로 올바르게 입력해주세요.\n";
		}
		else if (tempScore < 0)										// 경우2. 점수에 음수를 입력
			cout << "점수는 (0이상의 정수) 형식으로 올바르게 입력해주세요.\n";
		else if (this->school.find(tempName) != this->school.end())	// 경우3. 이미 기록된 학생
			cout << "해당 학생은 이미 점수가 등록되어있습니다.\n";
		else {														// 경우4. 정상적
			this->school.insert(make_pair(tempName, tempScore));
			return;
		}
	}
}

void adminScore::run() {
	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****\n";
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1: {		// 1. 입력
				insertScore();
				break;
			}
			case 2: {		// 2. 조회
				string tempName;
				cout << "이름>> ";
				cin >> tempName;
				if (school.find(tempName) == school.end())
					cout << "해당 학생은 기록이 없습니다\n";
				else
					cout << tempName << "의 점수는 " << school[tempName] << endl;
				break;
			}
			case 3:		// 3. 종료
				cout << "프로그램을 종료합니다...\n";
				return;
		}
	}
}

int main() {
	adminScore hongik;
	hongik.run();
	return 0;
}