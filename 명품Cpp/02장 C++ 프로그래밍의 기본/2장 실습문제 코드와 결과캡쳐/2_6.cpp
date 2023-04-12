/*
�ش� ���α׷��� �� ���ڿ��� �Է¹޾Ƽ� ������, �ٸ��� ����� ����ϴ� ���α׷��̴�.
���ڿ��� ���� ���� �� ���� ����� ����Ѵ�.
ù��°��, string ��ü�� = �����ڷ� ���غ���
�ι�°�� c-string �������, ���ڿ� �迭�� strcmp�� ���غ� ���̴�.

�̿� ����, ������ϵ� �� ����(string, cstring)�� ��� �߰��Ͽ���.
*/

#include <iostream>
#include <string>		// ���1: string ��ü �̿�
#include <cstring>		// ���2: strcmp ���
using namespace std;

int main() {

	// ���1. string ��ü�� = �����ڷ� ��
	string pw1, check1;

	// ���1-1. �Է¹ޱ�
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> pw1;
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> check1;

	// ���1-2. ���ϰ� ����ϱ�
	if (pw1 == check1)	// ���ٸ� "�����ϴ�" ���
		cout << "�����ϴ�" << endl;
	else                // �ٸ��ٸ� "���� �ʽ��ϴ�" ���
		cout << "���� �ʽ��ϴ�" << endl;
//----------------------------------------------------

	// ���2. c-string ��İ� strcmp�� ��
	char pw2[50], check2[50];	// �Է�ũ�Ⱑ �������ִٴ� ����

	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> pw2;					// cin.getline�� ������� ���� ������ ������ ������ �����߱� �����̴�.
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> check2;

	if (strcmp(pw2, check2))	// �ٸ� ���, (strcmp�� �ٸ� ��, 1�̳� -1�� ����ϹǷ�)
		cout << "���� �ʽ��ϴ�" << endl;
	else						// ���� ���,
		cout << "�����ϴ�" << endl;


	return 0;
}

/* BOOK SOLUTION

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char password1[100];
	char password2[100];
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> password1;
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> password2;
	if(strcmp(password1, password2) == 0)
		cout << "�����ϴ�";
	else
		cout << "���� �ʽ��ϴ�";
	cout << endl;
}
*/