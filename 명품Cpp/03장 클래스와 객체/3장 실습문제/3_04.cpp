/*
* 구상: CoffeeMachine 클래스만들기
* 멤버변수: 커피 물 설탕
* 멤버함수:	drinkEspresso/Americano/drinkSugarCoffee
*			show상태출력 fill채우기
* 부족해지면- 그런거 고려 안 함
*/

#include <iostream>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar;
public:
	// 생성자
	CoffeeMachine(int c, int w, int s) {
		coffee = c;
		water = w;
		sugar = s;
	}
	// 마시기
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

	// 충전
	void fill() {
		coffee = 10;
		water = 10;
		sugar = 10;
	}

	// 상태보고
	void show() {
		cout << "커피 머신 상태, 커피:" << coffee << '\t' << "물:" << water << '\t' << sugar << endl;
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
