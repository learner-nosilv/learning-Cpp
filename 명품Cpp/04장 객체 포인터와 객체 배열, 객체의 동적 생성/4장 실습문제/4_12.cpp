/* 12.
* Circle 클래스 > 이름, 반지름
* CircleManager 클래스 > Circle 클래스를 배열로 관리
* 
* 메인함수:
* 키보드로 원의 개수 입력받기
* 그 개수만큼 원의 이름과 반지름 입력받기
* 다음과 같이 실행되도록 클래스와 메인함수 작성
*/

#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;	// Circle 객체배열 포인터
	int size;	// Circle 객체배열 크기
public:
	CircleManager(int size) { this->size = size; p = new Circle[size]; }
	~CircleManager() { delete[] p; }
	void searchByName();
	void searchByArea();
	void setCircle(int index, string name, int radius);
};

void CircleManager::searchByName() {
	string name;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> name;

	int index = -1;
	for (int i = 0; i < size; i++) {
		if ((p + i)->getName() == name) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "그런 이름의 원은 없습니다." << endl;
	}
	else {
		cout << name << "의 면적은 " << (p + index)->getArea() << endl;
	}
}

void CircleManager::searchByArea() {
	int cutline;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> cutline;
	cout << cutline << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++) {
		double area = (p + i)->getArea();
		if (area > cutline) {
			cout << (p + i)->getName() << "의 면적은 " << area << ",";
		}
	}
	cout << endl;
}

void CircleManager::setCircle(int index, string name, int radius) {
	(p + index)->setCircle(name, radius);
}

int main() {
	int num;
	cout << "원의 개수 >> ";
	cin >> num;

	CircleManager twelve(num);

	for (int i = 0; i < num; i++) {
		string name;
		int radius;
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		twelve.setCircle(i, name, radius);
	}

	twelve.searchByName();

	twelve.searchByArea();

	return 0;
}