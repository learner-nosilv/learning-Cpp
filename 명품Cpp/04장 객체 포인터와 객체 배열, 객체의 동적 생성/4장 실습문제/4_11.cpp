/* 11.
* 다음과 같은 실행화면이 나타나도록 main과 두 클래스를 작성하라
* 만일!!! 커피를 제공할 수 없는 경우는 원료가 부족합니다. 를 출력하라
*/

#include <iostream>
#include <string>
using namespace std;

// 통 하나
class Container {
	int size;						// 용량
public:
	Container() { size = 10; }		// 기본생성자: size=10
	void fill() { size = 10; }		// 용량 채우기
	void consume() { size--; }		// 용량 소모하기
	int getSize() { return size; }	// 용량 리턴
};

// 커피자판기
class CoffeeVendingMachine {
	Container tong[3];				// 커피, 물, 설탕 통 객체
	void fill();
	void selectEspresso();			// 커피1, 물1 소모
	void selectAmericano();			// 커피1, 물1 소모
	void selectSugarCoffee();		// 커피1, 물1 소모
	void show();					// 통 잔량 출력
public:
	void run();
};

void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}
}

void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "설탕커피 드세요" << endl;
	}
	
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	show();
}

void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	while (true) {
		int menu;
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
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
				cout << "입력 값오류로 게임을 종료합니다." << endl;
				return;
		}
	}
}



int main() {
	CoffeeVendingMachine game;		// 객체 생성
	game.run();

	return 0;
}