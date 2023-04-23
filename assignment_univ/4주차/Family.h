/*
   FILE NAME : Family.h
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
// Family Ŭ������ �����
#ifndef FAMILY_H		// �ش� ��������� �ѹ��� include�ǵ��� ����
#define FAMILY_H

#include <string>		// ���ڿ� ��ü
#include "Person.h"		// Family class�� Person class�� ����Ѵ�

// ������ �ǹ��ϴ� Family Ŭ���� �����
class Family {
	std::string name;	// ���� �̸�
	Person* p;		// Person�� �迭�� ����Ű�� ������: �� ������������ Person�� ��ü�� ����
	int size;		// Person�� �迭 p�� ũ��: ���������� ��
public:
	Family(std::string name, int size);	// ������: �����̸��� ������������ ���� �Է°����� ���´�
	void setName(int index, std::string person_name);	// ������������ �̸��� �����ϴ� �Լ�
	void show();	// ������ �� �ο�(size)�� ������������ �̸��� ���� ����ϴ� �Լ�
	~Family() {};	// �Ҹ���

};

#endif

/*
* #ifndef FAMILY_H							// �ߺ� include ����
#define FAMILY_H

#include "Person.h"							// Person �ش����� include
#include <string>							// string �ش����� include 
using namespace std;

class Family {								// Family Ŭ���� �����
	Person* p;								// Person�� ��ü�迭�� �����Ҷ� ���� ������
	int size;								// �迭�� ������
	string famName;							// ���� �̸�
public:
	Family(string name, int size);			// ������
	void setName(int index, string fn);		// ���� ������ �̸� ����
	void show();							// ������ ���
	~Family();								// �Ҹ���
};

#endif
*/