#include<iostream>

int main(void) {
	int result=0;
	int i;

	// result <- 1~10�� ��, 55
	for (i = 1; i <= 10; i++)
		result += i;

	std::cout << "1���� 10���� ���� ����� " << result << "�Դϴ�\n";
	return 0;
}