/* 10.
* 클래스 2개: Person, Family
* main이 작동하도록 클래스의 멤버들을 추가할 것
*/
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() :Person("NONAMED") {}						// 생성자: 기본생성자		[추가]
	Person(string name) { this->name = name; }			// 생성자: 매개변수 1개
	string getName() { return name; }					// 멤버변수 name 리턴
	void setName(string name) { this->name = name; }	// 멤버변수 name 할당		[추가]
};

class Family {
	string name;			// Family 객체이름 (가족명)		[추가]
	Person* p;				// Person 객체배열 포인터	(가족구성원)
	int size;				// Person 객체배열 원소갯수 (Person 객체가 아닌 객체 배열을 만들기 위해 필요)
public:
	Family(string name, int size);
	void setName(int idx, string name);					// [추가]
	void show();			// 모든 Person 객체배열의 멤버변수 name 출력
	~Family();				// 생성자에서 동적할당받은 Person 객체배열 p 반환
};

Family::Family(string name, int size) {					// [추가]	
	this->name = name;		// 가족명
	this->size = size;		// 가족구성원 총 원
	p = new Person[size];	// Person 객체배열 동적할당
}

void Family::setName(int idx, string name) {			// [추가] 가족구성원의 이름 할당
	(p + idx)->setName(name);							// Person 객체배열의 [idx]째 객체의 멤버변수 name 할당
}														// 솔루션 : p[index].setName(name);

void Family::show() {									// [추가] 가족구성원의 이름 전부 출력
	cout << this->name << "가족은 다음과 같이 " << this->size << "명 입니다." << endl;
	for (int i = 0; i < (this->size); i++) {
		cout << (p + i)->getName() << '\t';				// 솔루션 : cout << p[i].getName() << '\t'
	}
	cout << endl;
}

Family::~Family() {										// [추가] 동적할당받은 Person 객체배열 힙 반환
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3);	// Family 객체 동적할당: 포인터 생성, 매개변수가 2개(이름, 크기)인 생성자 존재
	simpson->setName(0, "Mr. Simpson");			// Family 객체의 멤버변수 Person 객체 배열 중 [0]번 Person 객체의 멤버변수 name 할당
	simpson->setName(1, "Mrs. Simpson");		// Family 객체의 멤버변수 Person 객체 배열 중 [1]번 Person 객체의 멤버변수 name 할당
	simpson->setName(2, "Bart Simpson");		// Family 객체의 멤버변수 Person 객체 배열 중 [2]번 Person 객체의 멤버변수 name 할당

	simpson->show();
	delete simpson;
	return 0;
}

/* [Book solution]
* 
* class Person {
	string name;
public:
	Person() { name=""; }								// 생성자: 기본생성자		[추가]
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }	// [추가]
};

class Family {
	string name;										// [추가]
	Person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수
public:
	Family(string name, int size); // size 개수만큼 Person 배열 동적 생성
	void setName(int index, string name);				// [추가]
	void show(); // 모든 가족 구성원 출력
	~Family();
};

Family::Family(string name, int size) {					// [추가]
	this->name = name;
	this->size = size;
	p = new Person [size];
}

Family::~Family() {										// [추가]
	delete [] p;
}

void Family::setName(int index, string name) {
	p[index].setName(name);
}

void Family::show() {
	cout << name + " 가족은 다음과 같이 " << size << "명 입니다." << endl;
	for(int i=0; i<size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;
}

int main() {
	Family *simpson = new Family("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
*/