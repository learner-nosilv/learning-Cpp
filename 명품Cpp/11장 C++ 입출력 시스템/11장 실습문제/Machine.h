#ifndef MACHINE_H
#define MACHINE_H

#include "Material.h"	// <string>, MATERIAL 5
#include "Recipe.h"
#include "MachineUI.h"

#define RECIPE 3		// �ӽ��� ������ ������ ����
#define FILL 3			// �ӽ��� ����� �뷮

class Machine {
	Material material[MATERIAL];	// �ӽ��� �����
	Recipe coffee[RECIPE];			// �ӽ��� ������ ������
	bool operator -= (Recipe r);	// [������ �����ε�] �ӽſ��� �����Ǹ�ŭ�� ��ᷮ �Ҹ�
	void fill();					// ����� ä��� [3]��ŭ
	bool make(int recipeIdx);		// �����Ǵ�� ���� ����
public:
	Machine();			// ������: ������ ������ ����
	void run();			// �ӽ� ����
};
#endif // !MACHINE_H