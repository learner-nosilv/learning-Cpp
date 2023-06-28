#include "MachineUI.h"

bool MachineUI::isErr() {			// 입력에러체커
	if (std::cin.fail()) {
		std::cin.clear();			// 상태초기화
		std::cin.ignore(99, '\n');	// 버퍼비우기
		return true;
	}
	return false;
}

void MachineUI::greeting() { std::cout << "-----명품 커피 자판기 켭니다.-----\n"; }
void MachineUI::parting() { std::cout << "프로그램을 종료합니다...\n"; }
void MachineUI::filling() { std::cout << "모든 통을 채웁니다~~\n"; }
void MachineUI::making(std::string name) { std::cout << "맛있는 " << name << " 나왔습니다~~\n"; }
void MachineUI::lacking() { std::cout << "재료가 부족합니다.\n"; }

int MachineUI::getMenu(Recipe* r, int size) {			// 머신의 메뉴선택
	int menu = 0;
	while (true) {
		for (int i = 0; i < size; i++)										// 1. 머신이 제공가능한 레시피명 출력
			std::cout << r[i].showRecipeName() << ':' << i << ", ";
		std::cout << "채우기:" << size << ", 종료:" << size + 1 << ">> ";		// 2. 그 외 채우기, 종료 메뉴명 출력
		std::cin >> menu;													// 3. 메뉴 입력받기
		if (isErr()) std::cout << "[입력오류] 문자열이 아닌 정수를 입력하세요.\n";			// 문자열 입력시
		else if (0 <= menu && menu <= size + 1) return menu;							// 올바른 입력시
		else std::cout << "[입력오류] 0 ~ " << size + 1 << " 사이의 정수를 입력하세요.\n";	// 올바르지 않은 숫자 입력시
	}
}

void MachineUI::showMaterial(Material* m) {				// 머신의 재료통 상태 출력
	for (int i = 0; i < MATERIAL; i++) {
		std::cout.setf(std::ios::left);
		std::cout << std::setw(9) << m[i].getName();	// 재료명 출력
		int num = m[i].getNumber();						// 재료량
		for (int j = 0; j < num; j++) std::cout << '*';	// 재료량 만큼 * 출력
		std::cout << '\n';
	}
	std::cout << '\n';
}