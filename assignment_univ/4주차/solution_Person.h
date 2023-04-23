//#pragma once
/*
FILE NAME : Person.h
AUTHOR : ----�а� -�г� A123456 ȫ�浿
YYYYMMDD : 20230413
PURPOSE : 
�����ð��� ����� �Ͱ� ����,
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

#ifndef PERSON_H					// �ߺ� include ����
#define PERSON_H
#include <string>					// string �ش����� include
using namespace std;

class Person {						// Person Ŭ���� �����
	string name;					// �ɹ����� : �̸� 
	string tel;						// �ɹ����� : ��ȭ��ȣ
public:
	Person();							// ������
	Person(string name, string tel);	// ������
	string getName();					// �ɹ����� name ����
	string getTel();					// �ɹ����� tel ����
	void set(string name, string tel);	// ��������� ������ name�� tel ���� ��� �����ϴ� �Լ�
	void set(string name);				// ��������� ������ name �� ���� �����ϴ� �Լ� (�Լ� �����ε��� �̿���)
};

#endif