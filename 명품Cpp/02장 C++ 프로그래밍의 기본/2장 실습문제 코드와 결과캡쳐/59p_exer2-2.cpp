// cout�� <<�� �̿��� ȭ�� ���
#include <iostream>

double area(int r);	// return: ���� ����
int main(void) {
	int n = 3;
	char c = '#';
	std::cout << c << 5.5 << '-' << n << "Hello" << true << std::endl;
	std::cout << "n + 5 = " << n + 5 << '\n';
	std::cout << "������ " << area(n);

	return 0;
}

double area(int r) {
	return 3.14 * r * r;
}