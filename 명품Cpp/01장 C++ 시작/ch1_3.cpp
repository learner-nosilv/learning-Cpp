#include<iostream>

int main(void) {
	int result=0;
	int i;

	// result <- 1~10의 합, 55
	for (i = 1; i <= 10; i++)
		result += i;

	std::cout << "1에서 10까지 더한 결과는 " << result << "입니다\n";
	return 0;
}