#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include "Material.h"
#include "Recipe.h"

class MachineUI {
	static bool isErr();
public:
	static void greeting();						// �ӽ� ���� ��, Ư�� ���� ���
	static void parting();						// �ӽ� ���� ��, Ư�� ���� ���
	static void filling();						// �ӽ��� ����� ���� ��, Ư�� ���� ���
	static void making(std::string name);		// �ӽ����� Ư�� �޴� ���� ��, Ư�� ���� ���
	static void lacking();						// �ӽ��� ���������� ���۽��� ��, Ư�� ���� ���
	static int getMenu(Recipe* r, int size);	// �ӽ��� �޴����� (parameter: �ӽ��� �����ǹ迭, �����ǰ���)
	static void showMaterial(Material* m);		// �ӽ��� ����� ���� ���
};
#endif // !UI_H