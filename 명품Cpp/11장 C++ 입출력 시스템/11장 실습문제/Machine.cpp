#include "Machine.h"

Machine::Machine() {															// 생성자: 재료통과 레시피 세팅
	this->material[0].setMaterial("Coffee", FILL);								// 1. Machine의 재료통 세팅
	this->material[1].setMaterial("Sugar", FILL);
	this->material[2].setMaterial("CREAM", FILL);
	this->material[3].setMaterial("Water", FILL);
	this->material[4].setMaterial("Cup", FILL);
	this->coffee[0].setRecipe("보통 커피", new int[MATERIAL] {1, 0, 1, 1, 1});	// 2. 머신이 보유한 레시피 세팅
	this->coffee[1].setRecipe("설탕 커피", new int[MATERIAL] {1, 1, 0, 1, 1});
	this->coffee[2].setRecipe("블랙 커피", new int[MATERIAL] {1, 0, 0, 1, 1});	
}

bool Machine::operator-= (Recipe r) {		// [연산자 오버로딩] 머신에서 레시피만큼의 재료량 소모
	Material* recipe = r.showMaterial();	// 레시피의 Material배열
	for (int i = 0; i < MATERIAL; i++) {								// 검사
		if (this->material[i].getNumber() < recipe[i].getNumber())		// 단 한 재료라도 부족하다면, false 리턴
			return false;
		else if (this->material[i].getName() != recipe[i].getName())	// 재료 순서가 레시피와 머신이 다르다면, false 리턴
			return false;
	}
	for (int i = 0; i < MATERIAL; i++)				// 재료 소모 진행
		this->material[i] -= recipe[i];
	return true;
}

bool Machine::make(int recipeIdx) {					// 레시피대로 실제 제작
	return ((*this) -= this->coffee[recipeIdx]);
}

void Machine::fill() {								// 재료통 채우기 [3]만큼
	for (int i = 0; i < MATERIAL; i++)
		this->material[i].setNumber(FILL);
}

void Machine::run() {					// 머신 실행
	MachineUI::greeting();										// 머신 실행 시, 특정 문구 출력
	while (true) {
		MachineUI::showMaterial(this->material);				// 머신의 재료통 상태 출력
		int menu = MachineUI::getMenu(this->coffee, RECIPE);	// 머신의 메뉴선택
		switch (menu) {
			case 0:						// 제작 메뉴
			case 1:
			case 2:
				if (make(menu)) MachineUI::making(this->coffee[menu].showRecipeName());
				else MachineUI::lacking();
				break;
			case 3:						// 채우기 메뉴
				fill();					// 머신 재료통 채우기
				MachineUI::filling();	// 머신의 재료통 충전 시, 특정 문구 출력
				break;
			case 4:
				MachineUI::parting();	// 머신 종료 시, 특정 문구 출력
				return;					// 머신 종료
		}
	}
}