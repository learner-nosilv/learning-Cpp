/* �����Ǹ�� �ʿ��� ���(Material:����, ��ᷮ)���� �߻�ȭ �� ������ Ŭ���� Recipe */
#ifndef RECIPE_H
#define RECIPE_H
#include "Material.h"		// <string>����� MATERIAL����� ����
class Recipe {
	std::string name;				// ������ �̸�
	Material material[MATERIAL];	// �ʿ� ��� �迭[5]
public:
	Recipe() {}						// �⺻������
	// void setRecipe(std::string name, int size = 0);			// [�Լ� �����ε�] ��ᷮ�� ��� ���� ���
	void setRecipe(std::string name, int* size);			// [�Լ� �����ε�] ��ᷮ�� �ٸ� ���(�����Ҵ� ���� �迭��)
	std::string showRecipeName() { return this->name; }		// ������ �� ����
	Material* showMaterial() { return this->material; }		// ������ ��� �迭 ����
};
#endif // !RECIPE_H