#include <iostream>

int main(void) {
	int row,star;

	// 1. row: 1~4번째 행에서
	for (row = 0; row < 4; row++) {
		// 별을 행번호만큼 반복출력(예: 3행은 별3개)
		for (star = 0; star <= row; star++) {
			std::cout << "*";
		}
		std::cout << "\n"; // 다 출력되면 개행
	}
	return 0;
}