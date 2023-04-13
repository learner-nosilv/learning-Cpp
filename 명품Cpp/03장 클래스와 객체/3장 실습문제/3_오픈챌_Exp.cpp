#include "Exp.h"

// 밑과 지수의 계산 값을 계산하는 함수
int Exp::getValue() {
	int result = base;	// 지수가 1인 경우 선계산
	for (int i = 1; i < exp; i++)
		result *= base;
	return result;
}

// 두 지수계산값이 동일한지 논리값을 출력하는 함수
bool Exp::equals(Exp n) {
	if (getValue() == n.getValue())
		return true;
	else
		return false;
}