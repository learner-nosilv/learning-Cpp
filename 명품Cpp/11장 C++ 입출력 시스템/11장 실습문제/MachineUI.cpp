#include "MachineUI.h"

bool MachineUI::isErr() {			// �Է¿���üĿ
	if (std::cin.fail()) {
		std::cin.clear();			// �����ʱ�ȭ
		std::cin.ignore(99, '\n');	// ���ۺ���
		return true;
	}
	return false;
}

void MachineUI::greeting() { std::cout << "-----��ǰ Ŀ�� ���Ǳ� �մϴ�.-----\n"; }
void MachineUI::parting() { std::cout << "���α׷��� �����մϴ�...\n"; }
void MachineUI::filling() { std::cout << "��� ���� ä��ϴ�~~\n"; }
void MachineUI::making(std::string name) { std::cout << "���ִ� " << name << " ���Խ��ϴ�~~\n"; }
void MachineUI::lacking() { std::cout << "��ᰡ �����մϴ�.\n"; }

int MachineUI::getMenu(Recipe* r, int size) {			// �ӽ��� �޴�����
	int menu = 0;
	while (true) {
		for (int i = 0; i < size; i++)										// 1. �ӽ��� ���������� �����Ǹ� ���
			std::cout << r[i].showRecipeName() << ':' << i << ", ";
		std::cout << "ä���:" << size << ", ����:" << size + 1 << ">> ";		// 2. �� �� ä���, ���� �޴��� ���
		std::cin >> menu;													// 3. �޴� �Է¹ޱ�
		if (isErr()) std::cout << "[�Է¿���] ���ڿ��� �ƴ� ������ �Է��ϼ���.\n";			// ���ڿ� �Է½�
		else if (0 <= menu && menu <= size + 1) return menu;							// �ùٸ� �Է½�
		else std::cout << "[�Է¿���] 0 ~ " << size + 1 << " ������ ������ �Է��ϼ���.\n";	// �ùٸ��� ���� ���� �Է½�
	}
}

void MachineUI::showMaterial(Material* m) {				// �ӽ��� ����� ���� ���
	for (int i = 0; i < MATERIAL; i++) {
		std::cout.setf(std::ios::left);
		std::cout << std::setw(9) << m[i].getName();	// ���� ���
		int num = m[i].getNumber();						// ��ᷮ
		for (int j = 0; j < num; j++) std::cout << '*';	// ��ᷮ ��ŭ * ���
		std::cout << '\n';
	}
	std::cout << '\n';
}