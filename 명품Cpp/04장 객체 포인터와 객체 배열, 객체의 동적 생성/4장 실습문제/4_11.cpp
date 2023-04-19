/* 11.
* ������ ���� ����ȭ���� ��Ÿ������ main�� �� Ŭ������ �ۼ��϶�
* ����!!! Ŀ�Ǹ� ������ �� ���� ���� ���ᰡ �����մϴ�. �� ����϶�
*/

#include <iostream>
#include <string>
using namespace std;

// �� �ϳ�
class Container {
	int size;						// �뷮
public:
	Container() { size = 10; }		// �⺻������: size=10
	void fill() { size = 10; }		// �뷮 ä���
	void consume() { size--; }		// �뷮 �Ҹ��ϱ�
	int getSize() { return size; }	// �뷮 ����
};

// Ŀ�����Ǳ�
class CoffeeVendingMachine {
	Container tong[3];				// Ŀ��, ��, ���� �� ��ü
	void fill();
	void selectEspresso();			// Ŀ��1, ��1 �Ҹ�
	void selectAmericano();			// Ŀ��1, ��1 �Ҹ�
	void selectSugarCoffee();		// Ŀ��1, ��1 �Ҹ�
	void show();					// �� �ܷ� ���
public:
	void run();
};

void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
		cout << "���ᰡ �����մϴ�." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		cout << "���������� �弼��" << endl;
	}
}

void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
		cout << "���ᰡ �����մϴ�." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "�Ƹ޸�ī�� �弼��" << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
		cout << "���ᰡ �����մϴ�." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "����Ŀ�� �弼��" << endl;
	}
	
}

void CoffeeVendingMachine::show() {
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	show();
}

void CoffeeVendingMachine::run() {
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	while (true) {
		int menu;
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
		cin >> menu;

		switch (menu) {
			case 1:
				selectEspresso();
				break;
			case 2:
				selectAmericano();
				break;
			case 3:
				selectSugarCoffee();
				break;
			case 4:
				show();
				break;
			case 5:
				fill();
				break;
			default:
				cout << "�Է� �������� ������ �����մϴ�." << endl;
				return;
		}
	}
}



int main() {
	CoffeeVendingMachine game;		// ��ü ����
	game.run();

	return 0;
}