/* 2. istream& get(char& ch)�� �� ������ �а� ' '�� �� ������ ����ϴ� ���α׷�*/
#include <iostream>
int main() {
	char ch;
	int count = 0;
	std::cout << "���� �Է�>> ";
	while (true) {
		std::cin.get(ch);
		if (ch == ' ') count++;
		else if (ch == '\n') break;
	}
	std::cout << "��ĭ����>> " << count << std::endl;
	return 0;
}