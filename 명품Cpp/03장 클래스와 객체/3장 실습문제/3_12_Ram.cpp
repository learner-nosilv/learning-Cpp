#include "3_12_Ram.h"
#include <iostream>

Ram::Ram() {
	mem[100 * 1024] = { 0, };	// �迭 ��� ���θ� 0���� �ʱ�ȭ
	size = 100 * 1024;
}

Ram::~Ram() {
	std::cout << "�޸� ���ŵ�" << std::endl;
}

char Ram::read(int address) {
	return mem[address];
}

void Ram::write(int address, char value) {
	mem[address] = value;
}