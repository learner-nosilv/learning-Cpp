#include "Exp.h"

// �ذ� ������ ��� ���� ����ϴ� �Լ�
int Exp::getValue() {
	int result = base;	// ������ 1�� ��� �����
	for (int i = 1; i < exp; i++)
		result *= base;
	return result;
}

// �� ������갪�� �������� ������ ����ϴ� �Լ�
bool Exp::equals(Exp n) {
	if (getValue() == n.getValue())
		return true;
	else
		return false;
}