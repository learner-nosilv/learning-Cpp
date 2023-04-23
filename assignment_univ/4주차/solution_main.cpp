/*
FILE NAME : main.cpp
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

#include "Family.h"						// ������� include
#include "Person.h"						

#include <iostream>						// ������� ���� iostream ������� include 
#include <string>						// string ������� include
using namespace std;

int main() {
	Person p[3];						// ��ü �迭 ����
	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
	for (int i = 0; i < 3; i++) {		// �̸��� ��ȭ ��ȣ�� �Է�
		string n = ""; string t = "";
		cout << "��� " << i + 1 << ">> ";
		cin >> n >> t;
		p[i].set(n, t);					// Person Ŭ���� ��� �Լ��� ����� name�� tel �� ����
	}
	cout << "��� ����� �̸��� ";			// �̸� ���
	for (int i = 0; i < 3; i++) {
		cout << p[i].getName() << ' ';	// getName �ɹ��Լ��� name �� ������
	}
	cout << endl << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>> ";
	string sn = ""; int count = 0;			// �˻��Ҷ� �� string ���� sn�� ���������� ���� ���� count ���� �� �ʱ�ȭ
	cin >> sn;
	for (int i = 0; i < 3; i++) {
		if (sn == p[i].getName()) {			// �˻�
			cout << "��ȭ ��ȣ�� " << p[i].getTel() << endl << endl << endl;
			count++;						// count == 0 �̸� �˻���� ����
		}
	}
	if (count == 0)							// count == 0 �̸� �˻���� ����
		cout << "�̸��� �� �� �Է��߰ų� ���� �̸��Դϴ�." << endl;

	Family* simpson = new Family("Simpson", 3); // �����ڴ� p�� Person ������Ʈ 3���� ��ҷ� ������ �迭�� �ʱ�ȭ�ϰ� new �Լ��� ���� �׸�ŭ�� �޸𸮸� �����Ҵ� �� simpson �����Ϳ� �ּҰ� ���� 
	simpson->setName(0, "Mr. Simpson");			// index 0 ��° ��ҿ� ����
	simpson->setName(1, "Mrs. Simpson");		// index 1 ��° ��ҿ� ����
	simpson->setName(2, "Bart Simpson");		// index 2 ��° ��ҿ� ����
	simpson->show();							// ���� ������ ���
	delete simpson;								// �������� �Ҵ�� �޸� ����
}