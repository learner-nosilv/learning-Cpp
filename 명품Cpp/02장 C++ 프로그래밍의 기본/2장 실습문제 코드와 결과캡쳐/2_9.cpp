/*
* �̸�, �ּ�, ���̸� �Է¹޾� ����ϴ� ���α׷�
* ��� c-string �� ���������,
* �̹��� ���ڿ��� ����¿� string��ü�� getline(cin,���ڿ�)�� �̿��� ��
* ����, <string> �ʿ�
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string name, address, age;

	//1. ������ ǥ���ϴ� ���ڿ� �Է¹ޱ� (�����ʰ��� ������� ����)
	cout << "�̸���?";
	getline(cin, name);

	cout << "�ּҴ�?";
	getline(cin, address);

	cout << "���̴�?";
	getline(cin, age);

	//2. �ٽ� ����ϱ�
	cout << name << ", " << address << ", " << age << "��" << endl;

	return 0;
}