/*
   FILE NAME : Family.cpp
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
// Family Ŭ������ ������

#include <iostream>		// ǥ�� ����� ���̺귯��
#include "Family.h"		// Family Class�� People Class�� ���� ���

// ���ڰ� 2��(�̸�, ������ ��)�� ������
Family::Family(std::string name, int size) {
	this->name = name;			// �Է¹��� �Ķ���� name�� ���� ������� name�� �Ҵ�
	this->size = size;			// �Է¹��� �Ķ���� size�� ���� ������� size�� �Ҵ�
	this->p = new Person[size];	// ��ü �迭 �޸� �����Ҵ�
}

// �ε����� �̸��� ���ڷ� �޾Ƽ�, Family �� People ��ü�� �̸��� �Ҵ��ϴ� �Լ�
void Family::setName(int index, std::string person_name) {
	p[index].setName(person_name);	// �йи� �ش� index�� person ��ü�� name �Ҵ�
}

// ������ �� �ο�(size)�� ������������ �̸��� ���� ����ϴ� �Լ�
void Family::show() {
	std::cout << name << "������ ������ ���� " << size << "�� �Դϴ�." << std::endl;
	for (int i = 0; i < size; i++) {			// ����: sizeȽ����ŭ ���
		std::cout << p[i].getName() << '\t';	// Family Ŭ������ ��������� �迭�����͸� �̿��Ͽ� i��° People��ü�� �ҷ�����, 
	}											// PeopleŬ������ ����Լ��� getName()�� ȣ���Ͽ� PeopleŬ������ ��������� name���� �ܼ����
	std::cout << std::endl;						// ����
}