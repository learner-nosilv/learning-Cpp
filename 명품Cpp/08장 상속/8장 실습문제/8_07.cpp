/* 7 BaseMemory 클래스를 상속받는 ROM, RAM 클래스를 작성하라
* ROM: 읽기전용메모리, 초기화=굽기(burn)
* 1. ROM의 0-4번지까지 읽기
* 2. RAM메모리의 0-4번지에 쓰기
* 3. RAM메모리의 값을 화면에 출력하기
*/

#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;		// data를 저장할 배열 포인터
	int capacity;	// Memory 용량 
protected:
	BaseMemory(int size) { mem = new char[size]; this->capacity = size; }
	~BaseMemory() { delete[] mem; }
	void memWrite(int address, char data) { mem[address] = data; }
public:
	char read(int address) { return mem[address]; }
};

class ROM : virtual public BaseMemory {
public:
	ROM(int memSize, char data[], int dataSize) : BaseMemory(memSize) {		// 생성자: burning
		for (int i = 0; i < dataSize; i++) memWrite(i, data[i]);
	}
};

class RAM : virtual public BaseMemory {
public:
	RAM(int memSize, char data[] = nullptr, int dataSize = 0) : BaseMemory(memSize) {
		for (int i = 0; i < dataSize; i++) write(i, data[i]);
	}
	void write(int address, char data) { memWrite(address, data); }
};

int main() {
	char x[5] = { 'h', 'e', 'l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	return 0;
}


/* Solution 과의 비교
	1. 나 Index - 답 Address
	2. 메모리쓰기의 방식(load write): 나 단일쓰기 - 답 배열쓰기
*/