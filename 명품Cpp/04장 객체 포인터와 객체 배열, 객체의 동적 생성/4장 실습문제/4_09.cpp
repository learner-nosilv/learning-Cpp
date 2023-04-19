/* 9.
* 이름, 전화번호로 추상화한 Person 클래스
* 멤버변수: name, tel
* 멤버함수:
*	생성자(매개변수0):
*	멤버변수 리턴: getName, getTel
*	멤버변수 초기화 하는 함수 : set(string 이름, string 전화번호)
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {
		name = "NONAMED";
		tel = "000-0000-0000";
	}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) {
		this->name = name;
		this->tel = tel;
	}
};

int main() {
	// 1. 3개의 Person 객체를 가지는 배열 선언
	int n = 3;
	Person* p = new Person[3];

	// 2. 이름과 전화번호를 입력받기 
	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	for (int i = 0; i < n; i++) {
		string name, tel;
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		(p + i)->set(name, tel);
	}

	// 3. 출력하기
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < n; i++) {
		cout << (p + i)->getName() << ' ';
	}
	cout << endl;

	// 4. 검색하기
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	string name;
	cin >> name;
	int index = -1;		// 일치하는 객체의 index
	for (int i = 0; i < n; i++) {
		if ((p + i)->getName() == name) {
			index = i;
		}
	}
	cout << "전화 번호는 " << (p + index)->getTel() << endl;

	return 0;
}