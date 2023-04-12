// �޴���ȣ�� ��� ���� �Է¹ް� �̸� ����ϴ� ���α׷�
// ����ó��: �ٸ� ��ȣ�� �Է��� ���, �������� �˸��� ���ֹ� �޴´�(continue) 

#include <iostream>
using namespace std;

bool isInputError();
void ErrorMessage() {
	cout << "�ٽ� �ֹ��ϼ���!!" << endl;
}

int main() {
	cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;
	int num_menu, people = 0;						// �Է¹��� �޴���ȣ�� �����
	char menu[3][7] = { "«��", "¥��", "������" };	// ��� �뵵
	
	while (1) {
		cout << "«��:1, ¥��:2, ������:3, ����:4>>  ";
		cin >> num_menu;
		if (isInputError()) {	// 1. �޴��� ���ڿ� �Է¿����� �߻��� ���, �������� �˸��� ������ �ٽ� ����
			continue;
		}

		if (num_menu == 4) {	// 2. �޴��� ����(4) �Է½�, ����
			cout << "���� ������ �������ϴ�." << endl;
			return 0;
		}

		else if (num_menu == 1 || num_menu == 2 || num_menu == 3) {	// 3. �޴��� ����� �ֹ�(1~3)��, �ο� �� ����
			cout << "���κ�?";							// �ο� �� ����
			cin >> people;	
			if (!isInputError() && people > 0) {		// �ο� ���� ����� �Է½�, ���� ����ϰ� �ٽ� �ֹ��޴� ���� ����
				cout << menu[num_menu - 1] << " " << people << "�κ� ���Խ��ϴ�" << endl;
				continue;
			}
		}
		// 4. �ֹ��� 1, 2, 3, 4�� �Է¾��߰ų�, �ο� ���� 1�̻��� �ڿ����� �Է����� ���� ���
		cout << "�ٽ� �ֹ��ϼ���!!" << endl;
		continue;								// �ٽ� �ֹ��ޱ�
	}

	return 0;
}

bool isInputError() {
	if (cin.fail()) {	// �Է½�Ʈ���� ���������� ���
		cin.clear();	// �Է½�Ʈ���� ���¸� �������� �ʱ�ȭ�ϰ�
		cin.ignore(100, '\n');	// �Է¹��۰��� ���๮�� ������ 100�� ����
		cout << "�ٽ� �ֹ��ϼ���!!" << endl;
		return true;	// �� ��ȯ
	}
	else
		return false;	// ���� ��ȯ
}


/*
* #include <iostream>
#include <cstring>
using namespace std;

bool checkInputError() {
	if (cin.fail()) { // ������� ���ڿ��� �ԷµǾ� ������ �߻��ϴ� ��� ��ó. �η� C�� ���� C-1����
		cin.clear();
		cin.ignore(100, '\n');
		cout << "�Է� ����" << endl;
		return true; // ���� ����
	}
	else
		return false; // ���� ����
}

int main() {
	int menu; // 1~4
	int num; // ���κ�

	cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;
	while (true) {
		cout << "«��:1, ¥��:2, ������:3, ����:4>>  ";
		cin >> menu;
		if (checkInputError()) continue; // menu�� ���� �� �ٸ� �Է��Ͽ����� �˻�

		if (menu < 1 || menu > 4) {
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			continue;
		}
		else if (menu == 4) {
			cout << "���� ������ �������ϴ�." << endl;
			return 0;
		}

		// �Է��� ���������� �̷�����ٸ�
		cout << "���κ�?";
		cin >> num;
		if (checkInputError()) continue; // num�� ���� �� �ٸ� �Է��Ͽ����� �˻�
		if (num < 1) {
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			continue;
		}
		switch (menu) {
			case 1:
				cout << "«�� " << num << "�κ� ���Խ��ϴ�" << endl;
				break;
			case 2:
				cout << "¥�� " << num << "�κ� ���Խ��ϴ�" << endl;
				break;
			case 3:
				cout << "������ " << num << "�κ� ���Խ��ϴ�" << endl;
				break;
		}
	}
}
*/