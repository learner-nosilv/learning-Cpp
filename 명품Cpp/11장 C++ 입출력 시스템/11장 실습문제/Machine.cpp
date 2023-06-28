#include "Machine.h"

Machine::Machine() {															// ������: ������ ������ ����
	this->material[0].setMaterial("Coffee", FILL);								// 1. Machine�� ����� ����
	this->material[1].setMaterial("Sugar", FILL);
	this->material[2].setMaterial("CREAM", FILL);
	this->material[3].setMaterial("Water", FILL);
	this->material[4].setMaterial("Cup", FILL);
	this->coffee[0].setRecipe("���� Ŀ��", new int[MATERIAL] {1, 0, 1, 1, 1});	// 2. �ӽ��� ������ ������ ����
	this->coffee[1].setRecipe("���� Ŀ��", new int[MATERIAL] {1, 1, 0, 1, 1});
	this->coffee[2].setRecipe("�� Ŀ��", new int[MATERIAL] {1, 0, 0, 1, 1});	
}

bool Machine::operator-= (Recipe r) {		// [������ �����ε�] �ӽſ��� �����Ǹ�ŭ�� ��ᷮ �Ҹ�
	Material* recipe = r.showMaterial();	// �������� Material�迭
	for (int i = 0; i < MATERIAL; i++) {								// �˻�
		if (this->material[i].getNumber() < recipe[i].getNumber())		// �� �� ���� �����ϴٸ�, false ����
			return false;
		else if (this->material[i].getName() != recipe[i].getName())	// ��� ������ �����ǿ� �ӽ��� �ٸ��ٸ�, false ����
			return false;
	}
	for (int i = 0; i < MATERIAL; i++)				// ��� �Ҹ� ����
		this->material[i] -= recipe[i];
	return true;
}

bool Machine::make(int recipeIdx) {					// �����Ǵ�� ���� ����
	return ((*this) -= this->coffee[recipeIdx]);
}

void Machine::fill() {								// ����� ä��� [3]��ŭ
	for (int i = 0; i < MATERIAL; i++)
		this->material[i].setNumber(FILL);
}

void Machine::run() {					// �ӽ� ����
	MachineUI::greeting();										// �ӽ� ���� ��, Ư�� ���� ���
	while (true) {
		MachineUI::showMaterial(this->material);				// �ӽ��� ����� ���� ���
		int menu = MachineUI::getMenu(this->coffee, RECIPE);	// �ӽ��� �޴�����
		switch (menu) {
			case 0:						// ���� �޴�
			case 1:
			case 2:
				if (make(menu)) MachineUI::making(this->coffee[menu].showRecipeName());
				else MachineUI::lacking();
				break;
			case 3:						// ä��� �޴�
				fill();					// �ӽ� ����� ä���
				MachineUI::filling();	// �ӽ��� ����� ���� ��, Ư�� ���� ���
				break;
			case 4:
				MachineUI::parting();	// �ӽ� ���� ��, Ư�� ���� ���
				return;					// �ӽ� ����
		}
	}
}