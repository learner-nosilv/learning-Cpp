/* 10.
* Ŭ���� 2��: Person, Family
* main�� �۵��ϵ��� Ŭ������ ������� �߰��� ��
*/
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() :Person("NONAMED") {}						// ������: �⺻������		[�߰�]
	Person(string name) { this->name = name; }			// ������: �Ű����� 1��
	string getName() { return name; }					// ������� name ����
	void setName(string name) { this->name = name; }	// ������� name �Ҵ�		[�߰�]
};

class Family {
	string name;			// Family ��ü�̸� (������)		[�߰�]
	Person* p;				// Person ��ü�迭 ������	(����������)
	int size;				// Person ��ü�迭 ���Ұ��� (Person ��ü�� �ƴ� ��ü �迭�� ����� ���� �ʿ�)
public:
	Family(string name, int size);
	void setName(int idx, string name);					// [�߰�]
	void show();			// ��� Person ��ü�迭�� ������� name ���
	~Family();				// �����ڿ��� �����Ҵ���� Person ��ü�迭 p ��ȯ
};

Family::Family(string name, int size) {					// [�߰�]	
	this->name = name;		// ������
	this->size = size;		// ���������� �� ��
	p = new Person[size];	// Person ��ü�迭 �����Ҵ�
}

void Family::setName(int idx, string name) {			// [�߰�] ������������ �̸� �Ҵ�
	(p + idx)->setName(name);							// Person ��ü�迭�� [idx]° ��ü�� ������� name �Ҵ�
}														// �ַ�� : p[index].setName(name);

void Family::show() {									// [�߰�] ������������ �̸� ���� ���
	cout << this->name << "������ ������ ���� " << this->size << "�� �Դϴ�." << endl;
	for (int i = 0; i < (this->size); i++) {
		cout << (p + i)->getName() << '\t';				// �ַ�� : cout << p[i].getName() << '\t'
	}
	cout << endl;
}

Family::~Family() {										// [�߰�] �����Ҵ���� Person ��ü�迭 �� ��ȯ
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3);	// Family ��ü �����Ҵ�: ������ ����, �Ű������� 2��(�̸�, ũ��)�� ������ ����
	simpson->setName(0, "Mr. Simpson");			// Family ��ü�� ������� Person ��ü �迭 �� [0]�� Person ��ü�� ������� name �Ҵ�
	simpson->setName(1, "Mrs. Simpson");		// Family ��ü�� ������� Person ��ü �迭 �� [1]�� Person ��ü�� ������� name �Ҵ�
	simpson->setName(2, "Bart Simpson");		// Family ��ü�� ������� Person ��ü �迭 �� [2]�� Person ��ü�� ������� name �Ҵ�

	simpson->show();
	delete simpson;
	return 0;
}

/* [Book solution]
* 
* class Person {
	string name;
public:
	Person() { name=""; }								// ������: �⺻������		[�߰�]
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }	// [�߰�]
};

class Family {
	string name;										// [�߰�]
	Person* p; // Person �迭 ������
	int size; // Person �迭�� ũ��. ���� ������ ��
public:
	Family(string name, int size); // size ������ŭ Person �迭 ���� ����
	void setName(int index, string name);				// [�߰�]
	void show(); // ��� ���� ������ ���
	~Family();
};

Family::Family(string name, int size) {					// [�߰�]
	this->name = name;
	this->size = size;
	p = new Person [size];
}

Family::~Family() {										// [�߰�]
	delete [] p;
}

void Family::setName(int index, string name) {
	p[index].setName(name);
}

void Family::show() {
	cout << name + " ������ ������ ���� " << size << "�� �Դϴ�." << endl;
	for(int i=0; i<size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;
}

int main() {
	Family *simpson = new Family("Simpson", 3); // 3������ ������ Simpson ����
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}
*/