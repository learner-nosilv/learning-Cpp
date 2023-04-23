/*
FILE NAME : Family.cpp
AUTHOR : ----�а� -�г� A123456 ȫ�浿
YYYYMMDD : 20230413
PURPOSE :
�����ð��� ����� �Ͱ� ����,
1.	4���� ������ ������ �ǽ����� 4-1�� ������ �н� �Ͻÿ�. (�������� ����)
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

#include "Family.h"									// Family Ŭ���� ���� ������� include
#include <iostream>									// ������� ���� iostream include	
#include <string>									// string Ÿ�� ���

Family::Family(string name, int size) {				// ���� �̸��� �迭 ����� �Ű������� �޾� ���� �̸��� ��������� �����ϰ�, size��ŭ�� Person�� ��ü �迭�� ���� �����ϴ� ������
	famName = name;									// �����̸� ����
	this->size = size;								// size ����
	p = new Person[size];							// size��ŭ�� ��Ҹ� ���� Person �� ��ü �迭�� ���� �Ҵ��� �ּҸ� p�� ����
}
void Family::setName(int index, string name) {		// p�� ��ҵ��� name ���� �����ϴ� �Լ�
	p[index].set(name);
}
void Family::show() {								// ���������� ��� �ɹ��Լ�
	cout << famName << "������ ������ ���� " << size << "���Դϴ�" << endl;
	for (int i = 0; i < size; i++)					// �迭�� ����� �̸� ���
		cout << p[i].getName() << '\t';				
	cout << endl;
}
Family::~Family() {									// ��ü�� ������ �� �����Ҵ�� p�� �޸� ����
	delete[] p;
}