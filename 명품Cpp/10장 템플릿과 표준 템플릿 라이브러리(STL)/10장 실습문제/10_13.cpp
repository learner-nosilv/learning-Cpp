/* 13. map �����̳ʸ� �̿��Ͽ�
	���1. ����: �̸�, ������ �����ϰ�
	���2. �˻�: �̸����� ������ ��ȸ�ϴ�
	�������� ���α׷��� ������
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class adminScore {
	map<string, int> school;
	int getMenu();
	void insertScore();
public:
	adminScore() {}
	~adminScore() {}
	void run();
};

int adminScore::getMenu() {
	while (true) {
		int menu;
		cout << "�Է�:1, ��ȸ:2, ����:3 >> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3)
			return menu;
		else if (cin.fail()) {
			cout << "[�Է¿���] 1, 2, 3 �߿��� �Է��ϼ���.\n";
			cin.clear();
			cin.ignore(20, '\n');
		}
		else
			cout << "[�Է¿���] 1, 2, 3 �߿��� �Է��ϼ���.\n";
	}
}

void adminScore::insertScore() {
	string tempName;
	int tempScore;
	while (true) {
		cout << "�̸��� ����>> ";
		cin >> tempName >> tempScore;
		if (cin.fail()) {											// ���1. ������ ������ �ƴ� ���� �Է�
			cin.clear();
			cin.ignore(50, '\n');
			cout << "(������� �̸�)+(����)+(����) �������� �ùٸ��� �Է����ּ���.\n";
		}
		else if (tempScore < 0)										// ���2. ������ ������ �Է�
			cout << "������ (0�̻��� ����) �������� �ùٸ��� �Է����ּ���.\n";
		else if (this->school.find(tempName) != this->school.end())	// ���3. �̹� ��ϵ� �л�
			cout << "�ش� �л��� �̹� ������ ��ϵǾ��ֽ��ϴ�.\n";
		else {														// ���4. ������
			this->school.insert(make_pair(tempName, tempScore));
			return;
		}
	}
}

void adminScore::run() {
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****\n";
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1: {		// 1. �Է�
				insertScore();
				break;
			}
			case 2: {		// 2. ��ȸ
				string tempName;
				cout << "�̸�>> ";
				cin >> tempName;
				if (school.find(tempName) == school.end())
					cout << "�ش� �л��� ����� �����ϴ�\n";
				else
					cout << tempName << "�� ������ " << school[tempName] << endl;
				break;
			}
			case 3:		// 3. ����
				cout << "���α׷��� �����մϴ�...\n";
				return;
		}
	}
}

int main() {
	adminScore hongik;
	hongik.run();
	return 0;
}