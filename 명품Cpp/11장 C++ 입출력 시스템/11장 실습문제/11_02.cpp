/* 2. istream& get(char& ch)로 한 라인을 읽고 ' '이 몇 개인지 출력하는 프로그램*/
#include <iostream>
int main() {
	char ch;
	int count = 0;
	std::cout << "라인 입력>> ";
	while (true) {
		std::cin.get(ch);
		if (ch == ' ') count++;
		else if (ch == '\n') break;
	}
	std::cout << "빈칸갯수>> " << count << std::endl;
	return 0;
}