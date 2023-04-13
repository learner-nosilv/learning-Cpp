#include "3_12_Ram.h"
#include <iostream>

Ram::Ram() {
	mem[100 * 1024] = { 0, };	// 배열 요소 전부를 0으로 초기화
	size = 100 * 1024;
}

Ram::~Ram() {
	std::cout << "메모리 제거됨" << std::endl;
}

char Ram::read(int address) {
	return mem[address];
}

void Ram::write(int address, char value) {
	mem[address] = value;
}