/*
* ����: CoffeeMachine Ŭ���������
* �������: Ŀ�� �� ����
* ����Լ�:	drinkEspresso/Americano/drinkSugarCoffee
*			show������� fillä���
* ����������- �׷��� ��� �� ��
*/

#include <iostream>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar;
public:
	// ������
	CoffeeMachine(int c, int w, int s) {
		coffee = c;
		water = w;
		sugar = s;
	}
	// ���ñ�
	void drinkEspresso() {
		coffee -= 1;
		water -= 1;
	}
	void drinkAmericano() {
		coffee -= 1;
		water -= 2;
	}
	void drinkSugarCoffee() {
		coffee -= 1;
		water -= 2;
		sugar -= 1;
	}

	// ����
	void fill() {
		coffee = 10;
		water = 10;
		sugar = 10;
	}

	// ���º���
	void show() {
		cout << "Ŀ�� �ӽ� ����, Ŀ��:" << coffee << '\t' << "��:" << water << '\t' << sugar << endl;
	}
};

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();

	return 0;
}
