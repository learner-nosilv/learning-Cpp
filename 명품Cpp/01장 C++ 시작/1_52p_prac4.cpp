#include <iostream>

int main(void) {
	int row,star;

	// 1. row: 1~4��° �࿡��
	for (row = 0; row < 4; row++) {
		// ���� ���ȣ��ŭ �ݺ����(��: 3���� ��3��)
		for (star = 0; star <= row; star++) {
			std::cout << "*";
		}
		std::cout << "\n"; // �� ��µǸ� ����
	}
	return 0;
}