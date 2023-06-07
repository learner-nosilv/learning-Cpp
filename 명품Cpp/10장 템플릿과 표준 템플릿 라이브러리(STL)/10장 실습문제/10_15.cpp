/* 15. vector을 이용하여 Circle 클래스의 객체를 삽입하고 삭제하는 프로그램 작성하기.
 삭제 시, 이름이 같은 모든 원을 삭제한다. */

#include <iostream>
#include <vector>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14 * this->radius * this->radius; }
	string getName() { return this->name; }
};

class managementCircle {
	vector<Circle*> v;
	void insertCircle();
	void removeCircle();
	void showAll();
	int getMenu();
public:
	managementCircle() {}
	~managementCircle(){
		for (int i = 0; i < v.size(); i++)
			delete v[i];
	}
	void run();
};

void managementCircle::insertCircle() {
	int circleRadius; 
	string circleName;
	while (true) {
		cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
		cin >> circleRadius >> circleName;
		if (cin.fail()) {
			cout << "알맞는 형식:(정수형태의 반지름)+(공백)+(이름) 으로 입력하세요.'\n'";
			cin.clear();
			cin.ignore(50, '\n');
		}
		else {
			v.push_back(new Circle(circleRadius, circleName));	// 동적할당
			return;
		}
	}
}

void managementCircle::removeCircle() {
	string circleName;
	cout << "삭제하고자 하는 원의 이름은 >> ";
	cin >> circleName;
	vector<Circle*>::iterator it = v.begin();
	while (it != v.end()) {
		Circle* pTemp = *it;	// it가 가리키는 곳이 Circle* 형이므로
		if ((*it)->getName() == circleName) {
			it = v.erase(it);	// 삭제 후 다음 노드의 포인터 리턴
			delete pTemp;
		}
		else it++;
	}
	// for (int i = 0; i < v.size(); i++) 를 이용해도 되지만 힌트이용
	// erase하면 다음 노드로 넘어가기때문에 for문을 사용하는게 까다로웠다
	// 그리고, erase한다고 동적할당이 해제되는 것은 아니었다....
}

void managementCircle::showAll() {
	for (int i = 0; i < v.size(); i++)
		cout << v[i]->getName() << '\n';
	cout << endl;
}

int managementCircle::getMenu() {
	int menu;
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> menu;

		if (cin.fail()) {
			cout << "1, 2, 3, 4 중에 하나를 입력하세요.'\n'";
			cin.clear();
			cin.ignore(50, '\n');
		}
		else if (menu != 1 && menu != 2 && menu != 3 && menu != 4)
			cout << "1, 2, 3, 4 중에 하나를 입력하세요.'\n'";
		else return menu;
	}
}
void managementCircle::run() {
	cout << "원을 삽입하고 삭제하는 프로그램입니다.\n";
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1:
				insertCircle(); break;
			case 2:
				removeCircle(); break;
			case 3:
				showAll(); break;
			case 4:
				return;
		}
	}
}

int main() {
	managementCircle mark1;
	mark1.run();
	return 0;
}