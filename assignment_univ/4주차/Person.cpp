/*
   FILE NAME : Person.cpp
   AUTHOR : 
   YYYYMMDD : 2023.04.06
   PURPOSE :
		1. 4 ���� ������ ������ �ǽ����� 4-1 �� ������ �н� �Ͻÿ�. (�������� ����)
		2. 4 ���� �ǽ����� 4-9,4-10 �� ���� ������ �Ǿ��ִ� �������̴�, ������ �������� ���� �ҽ��ڵ带
		�ۼ��ϰ� �� �������� ���̽ÿ�.
			1) �ǽ����� 4-9,4-10 ��ο��� ���Ǵ� Person class �� member variables & functions ��
				��� ���ļ� ���յ� Person class �� �ۼ��Ͻÿ�.
			2) 4-9 �� ��°���� ���� �� �ֵ��� Person class �� main() �Լ��� �ۼ��Ͻÿ�.
			3) �ǽ����� 4-10 ���� ������ main()�� �۵��ǵ��� Person class �� Family class �� �ʿ���
				member ���� �߰��Ͽ� �ڵ带 �ϼ��Ͻÿ�.
			4) 1)~3)���� �ۼ� �� �ڵ��� ��°���� 4-9 �� 4-10 �� ��°�� ��θ� ������� �����ϰ�
				����� �� �־�� �մϴ�.
			5) 3 �� ���� 3-11 ���� ������ �� ����, ���� 1)~3)���� �ۼ� �� �ڵ带 ������ ���� header
				���ϰ� cpp ���ϵ�� �и��Ͽ� ���ۼ��Ͻÿ�:
					Person.h, Family.h, Person.cpp, Family.cpp, main.cpp
*/
// Person Ŭ������ ������

#include "Person.h"

// setName �Լ��� ������� name���� (��)�ʱ�ȭ�Ѵ�
void Person::setName(std::string name) {
	this->name = name;	// name�Ķ������ ���� ������� name�� �Ҵ�
}
// set �Լ��� ������� name�� tel���� �ʱ�ȭ�Ѵ�
void Person::set(std::string name, std::string tel) {
	this->name = name;	// ��ü�� ����Ű�� �����ͺ��� this ���
	this->tel = tel;	// �Ķ���� tel�� ���� ������� tel�� �Ҵ�
}

/* [�б� �ַ��]
* ���� �ַ���� ����: ���� �ζ����� ����Ͽ��� .....�ФФ� 
#include "Person.h"									// Person Ŭ���� ���� ������� include

#include <string>									// string ������� include
using namespace std;

Person::Person() : Person("", "") { }				// name �� tel�� ""�� �ʱ�ȭ�ϴ� �⺻ ������
Person::Person(string name, string tel) {			// name �� tel�� �Ű����� ���� �����ϴ� ������
	this->name = name;								// �Ű������� ��� ���� ���� �̸��� �����Ƿ� this ������ ���
	this->tel = tel;
}
string Person::getName() {							// ��� ���� name�� �����ϴ� ��� �Լ�
	return name;
}
string Person::getTel() {							// ��� ���� tel�� �����ϴ� ��� �Լ�
	return tel;
}
void Person::set(string name, string tel) {			// ��� ������ ������ ���� �����ϴ� ��� �Լ�
	this->name = name;								// �Ű������� ��������� �̸��� �����Ƿ� this ������ ���
	this->tel = tel;
}
void Person::set(string name) {						// ��� ���� name�� ������ ���� �����ϴ� ��� �Լ�
	this->name = name;								// �Ű������� ��������� �̸��� �����Ƿ� this ������ ���
*/