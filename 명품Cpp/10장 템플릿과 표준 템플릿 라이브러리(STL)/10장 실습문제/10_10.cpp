/* 10.	STL의 vector 클래스를 이용하여 나라 수도 맞추기 게임만들기
*	나라이름nation과 수도capital 문자열로 구성된 Nation 클래스
*	Nation 클래스의 객체를 원소로 하는 vetcor v 생성하기
*	게임기능 1. 정보입력, 2. 퀴즈, 3. 종료
*/
#include <iostream>
#include <string>
#include <vector>		// Standard Template Library
#include <cstdlib>		// to make random integer
#include <ctime>		// to make random integer
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation = "", string capital = "") { this->nation = nation; this->capital = capital; }
	string getNation() { return this->nation; }
	string getCapital() { return this->capital; }
};

class NationGame {
	vector<Nation> v;
	int getMenu();
	void setNation();
	void doQuiz();
public:
	NationGame() {
		v.push_back(Nation("대한민국", "서울"));
		v.push_back(Nation("그리스", "아테네"));
		v.push_back(Nation("네팔", "카트만두"));
		v.push_back(Nation("노르웨이", "오슬로"));
		v.push_back(Nation("덴마크", "코펜하겐"));
		v.push_back(Nation("룩셈부르크", "룩셈부르크"));
		v.push_back(Nation("모나코", "모나코"));
		v.push_back(Nation("베트남", "하노이"));
		v.push_back(Nation("이라크", "바그다드"));
	}
	~NationGame() {}
	void run();
};
int NationGame::getMenu() {
	int answer;
	while (true) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		cin >> answer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10, '\n');
			cout << "[오류] 1, 2, 3 중 하나를 입력하여야 합니다.\n";
			continue;
		}
		else if (answer != 1 && answer != 2 && answer != 3) {
			cout << "[오류] 1, 2, 3 중 하나를 입력하여야 합니다.\n";
			continue;
		}
		else
			return answer;
	}
}
void NationGame::setNation() {
	cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다.\n";
	cout << "나라와 수도를 입력하세요(no no 이면 입력끝)\n";
	while (true) {
		string nat = "", cap = "";				// 나라와 수도를 입력받을 변수
		bool isExist = false;					// 이미 존재하는지 여부를 담은 변수

		cout << v.size() + 1 << ">>";			// 입력받기
		cin >> nat >> cap;

		if (nat == "no" && cap == "no") return;	// [루프 탈출조건] 입력 종료
		for (int i = 0; i < v.size(); i++) {	// 동일한 나라가 가변배열에 이미 있는지 검사
			if (v[i].getNation() == nat) {		//	이미 존재한다면
				cout << "already exists !!\n";	//	이미 존재함을 알리고
				isExist = true;					//	부울변수에 반영 후
				break;							//	루프 즉각 탈출
			}
		}
		if (isExist == false)						// 동일한 나라가 없다면
			v.push_back(Nation(nat, cap));	// 입력반영
	}
}
void NationGame::doQuiz() {
	while (true) {
		int idx = rand() % (v.size());			// 퀴즈가 될 원소의 인덱스 선정
		string answer = "";
		cout << v[idx].getNation() << "의 수도는?(exit 이면 퀴즈끝)";
		while (true) {
			cin >> answer;
			if (cin.fail()) {
				cout << "[오류] 띄어쓰기 금지\n";
				cin.clear();
				cin.ignore(99, '\n');
			}
			break;
		}
		if (answer == "exit") return;				// [루프 탈출조건]
		else if (answer == v[idx].getCapital())
			cout << "Correct !!\n";
		else
			cout << "NO !!\n";
	}
}
void NationGame::run() {
	srand((unsigned)time(NULL));
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****\n";
	while (true) {
		int answer = getMenu();
		switch (answer) {
			case 1:
				setNation();
				break;
			case 2:
				doQuiz();
				break;
			case 3:
				return;
		}
	}
}

int main() {
	NationGame first;
	first.run();

	return 0;
}