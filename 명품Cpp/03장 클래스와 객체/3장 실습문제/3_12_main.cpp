/*
* �ֱ����ġ�� �𵨸��ϴ� Ŭ���� RAM
* �������: �����Ͱ� ��ϵ� �޸𸮰���(mem[100*1024])�� ũ������(size)
* ����Լ�:	������(�Ű�����X) �迭0, size=100*1024�ʱ�ȭ
*			�Ҹ��� "�޸����ŵ�" ���
*			char read(int address) �ش� address�� �޸𸮹���Ʈ ����
*			void write(�ּ�, ����) �ش� �ּҿ� ��������
* 
* * ���ڸ���� ���ڿ��� ���ڷ� �ν��ϴ°� ����������?
* * char�� �迭�� �� ĭ�� int���� ����ְ�
*	char�� �迭�� + �ϴµ� int������ ���ϱ����� �ǰ�
*	�� �׷��� �𸣰ڴ�!_!
*/
#include <iostream>
#include "3_12_Ram.h"

using namespace std;

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102 ������ �� = " << (int)ram.read(102) << endl;
	return 0;
}