/*
   FILE NAME : Person.h
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
// Person Ŭ������ ����� (+ �ζ��� �Լ����)

#ifndef PERSON_H		// �ش� ��������� �ѹ��� include�ǵ��� ����
#define PERSON_H

#include <string>		// PersonŬ������ ������� string Ŭ������ ����ϹǷ� string ��������� �߰� https://kldp.org/node/163194
// using namespace std;	string�� std namespace���� ���������Ƿ� �ش籸���� ����Ϸ� ������
// " C++ using namespace�� ��� ���Ͽ� ������� ���� " ��� ���� �а� ��������(std::)�� �ϱ�� �Ͽ��� https://linkmemo.tistory.com/200

class Person {
	std::string name;	// �̸�
	std::string tel;	// ��ȭ��ȣ
public:
	Person() {};		// �����ڷ� �̸��� ��ȭ��ȣ�� �Ҵ����� �ʴ´� -> set ����Լ� �̿�
	std::string getName() { return name; }	// ������� �̸� ��ȯ
	std::string getTel() { return tel; }	// ������� ��ȭ��ȣ ��ȯ
	void setName(std::string name);	// �̸� ���� �������(name)�� �Ҵ��ϴ� ����Լ�
	void set(std::string name, std::string tel);	// �̸��� ��ȭ��ȣ ���� �� ��������� �Ҵ��ϴ� ����Լ�
};

#endif