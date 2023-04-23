/*
   FILE NAME : Person.h, Family.h, Person.cpp, Family.cpp, main.cpp
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

#include <iostream>	// ǥ�� ����� ���̺귯��
#include "Family.h"	// Family Ŭ������ �����
#include "Person.h"	// Person Ŭ������ �����

#define N 3			// ���� 9�� Person ��ü���� ���� 10�� Family �� Person��ü�� (���� 3���� ����)

using namespace std;

// ����ó���Լ�: �Է¹��ۻ��°� �������� �ƴ��� ��ȯ�ϴ� �Լ�	*������ ���, ���۸� ����ȭ�ϰ� �������� �˸���.
bool isError() {
	if (cin.fail()) {	// �Է½�Ʈ�����۰� ���������� ���
		cin.clear();			// ������ ���¸� �ʱ�ȭ�ϰ�
		cin.ignore(100, '\n');	// ���ۿ� ����ִ� �� 100�� Ȥ�� ��������� ������
		cout << "Input Error" << endl;	// �Է¿������� �ַܼ� ����Ѵ�
		return true;
	}
	else
		return false;
}

// [9��]		3���� Person ��ü�� ������ �迭�� �����ϰ� ������ ���� Ű���忡�� �̸��� ��ȭ��ȣ�� �Է¹޾� ����ϰ� �˻�
// [10��]	3���� Person ��ü�� ������ Simpson������ �����ϰ� ��� ������������ ���
int main() {
	// -[9��]-----------------------
	// 1. 3���� Person ��ü ����
	Person a[N];	// ũ�Ⱑ 3�� Person �迭 ���� (N=3)

	// 2. �̸��� ��ȭ��ȣ�� ����ڷκ��� �Է¹��� ��, ����Լ� set()�� �̿��Ͽ� �� ��ü�� �������(name, tel)�� �Ҵ��Ѵ�.
	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
	string temp_n, temp_tel;			// ����� �Է��� ������ ����
	for (int i = 0; i < N;) {			// ����: �迭�� �ε��� < N�� �� ������ ����
		cout << "��� " << i + 1 << ">> ";	// �Է¹ޱ�
		cin >> temp_n >> temp_tel;
		if (!isError()) {					// �Է¿����� �� �� ���
			a[i].set(temp_n, temp_tel);		// �Է¹��� �̸��� ��ȭ��ȣ ���� ���� �������(name, tel)�� �Ҵ��Ѵ�.
			i++;							// �ε��� 1 ������ �������Ұ�ü�� ����
		}									// �Է¿����� �� ���, �ε��� ����X
	}
	
	// 3. ��� ����� �̸��� ����Ѵ�.
	cout << "��� ����� �̸���";
	for (int i = 0; i < N; i++) {		// ����: Nȸ
		cout << ' ' << a[i].getName();	// public�� ����Լ� getName�� ���� name�� ���� ����Ѵ� 
	}
	cout << endl;

	// 4. �̸��� �Է¹����� �׿� �´� ��ȭ��ȣ�� ����Ѵ�
	// 4-1. �̸� �ӷ¹ޱ�
	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	do {							// �켱,
		cin >> temp_n;				// �Է��� 1ȸ ���� ��
	} while (isError() == true);	// ����: ���ۿ� ������ �ִٸ� �ٽ� �Է��� �޴´� (��������: ���ۿ� ������ ������)

	// 4-2. ����ڰ� �Է��� �̸����� ������ name�� ���� ��ü�� ã��, �ش� ��ü�� ��ȭ��ȣ tel ���
	for (int i = 0; i < N; i++) {		// ����: Nȸ ���� (��������: ��� ��ü(N��)�� ���� ��� or ������ �̸��� �߰ߵ� ���)
		if (temp_n == a[i].getName()) {	// ����ڰ� �Է��� �̸��� Index�� i�� ��ü�� �̸��� ��ġ�Ѵٸ�
			cout << "��ȭ ��ȣ�� " << a[i].getTel() << endl;	// �ش� �̸��� ��ȭ��ȣ�� ������� tel �� ����Ѵ�
			break;											// �� �˻��� �ʿ䰡 �����Ƿ� [��������]
		}
		else if (i == N - 1) {			// ������ ������������ ����ڰ� �Է��� �̸��� �߰ߵ��� ������(=������������)
			cout << "�ش� �̸��� ���� Person�� �����ϴ�." << endl;	// ������ �˸���
		}
	}
	// -[10��]-----------------------
	// 1. 1���� Family ��ü(������ ���� 3��) ����
	Family* simpson = new Family("Simpson", N);		// size�� 3�� person�� �迭�� ���� Family ��ü ������ simpson �� �޸𸮵����Ҵ�

	// 2. �������� �̸��ο�: Family�� ��ü�� ��������� People�� �迭�� �� ���ҿ� �̸��Ҵ�
	simpson->setName(0, "Mr. Simpson");		// person�� �迭�� 0�� ��ü �̸��� "Mr.Sim.."���� �ʱ�ȭ
	simpson->setName(1, "Mrs. Simpson");	// person�� �迭�� 1�� ��ü �̸��� "Mrs.Sim.."���� �ʱ�ȭ
	simpson->setName(2, "Bart Simpson");	// person�� �迭�� 2�� ��ü �̸��� "Bart Sim.."���� �ʱ�ȭ

	// 3. Family ��ü�� People�� ������ �� ���� �̸� ���� ���
	simpson->show();	// Family�� ��ü ����Լ� show ȣ��	
	delete simpson;		// �޸� ����

	return 0;
}


/*
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
	*/