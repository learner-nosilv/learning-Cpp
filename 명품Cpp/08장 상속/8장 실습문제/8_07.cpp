/* 7 BaseMemory Ŭ������ ��ӹ޴� ROM, RAM Ŭ������ �ۼ��϶�
* ROM: �б�����޸�, �ʱ�ȭ=����(burn)
* 1. ROM�� 0-4�������� �б�
* 2. RAM�޸��� 0-4������ ����
* 3. RAM�޸��� ���� ȭ�鿡 ����ϱ�
*/

#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;		// data�� ������ �迭 ������
	int capacity;	// Memory �뷮 
protected:
	BaseMemory(int size) { mem = new char[size]; this->capacity = size; }
	~BaseMemory() { delete[] mem; }
	void memWrite(int address, char data) { mem[address] = data; }
public:
	char read(int address) { return mem[address]; }
};

class ROM : virtual public BaseMemory {
public:
	ROM(int memSize, char data[], int dataSize) : BaseMemory(memSize) {		// ������: burning
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


/* Solution ���� ��
	1. �� Index - �� Address
	2. �޸𸮾����� ���(load write): �� ���Ͼ��� - �� �迭����
*/