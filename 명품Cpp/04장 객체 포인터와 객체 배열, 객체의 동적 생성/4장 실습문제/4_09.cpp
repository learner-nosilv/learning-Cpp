/* 9.
* �̸�, ��ȭ��ȣ�� �߻�ȭ�� Person Ŭ����
* �������: name, tel
* ����Լ�:
*	������(�Ű�����0):
*	������� ����: getName, getTel
*	������� �ʱ�ȭ �ϴ� �Լ� : set(string �̸�, string ��ȭ��ȣ)
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {
		name = "NONAMED";
		tel = "000-0000-0000";
	}
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) {
		this->name = name;
		this->tel = tel;
	}
};

int main() {
	// 1. 3���� Person ��ü�� ������ �迭 ����
	int n = 3;
	Person* p = new Person[3];

	// 2. �̸��� ��ȭ��ȣ�� �Է¹ޱ� 
	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
	for (int i = 0; i < n; i++) {
		string name, tel;
		cout << "��� " << i + 1 << ">> ";
		cin >> name >> tel;
		(p + i)->set(name, tel);
	}

	// 3. ����ϱ�
	cout << "��� ����� �̸��� ";
	for (int i = 0; i < n; i++) {
		cout << (p + i)->getName() << ' ';
	}
	cout << endl;

	// 4. �˻��ϱ�
	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	string name;
	cin >> name;
	int index = -1;		// ��ġ�ϴ� ��ü�� index
	for (int i = 0; i < n; i++) {
		if ((p + i)->getName() == name) {
			index = i;
		}
	}
	cout << "��ȭ ��ȣ�� " << (p + index)->getTel() << endl;

	return 0;
}