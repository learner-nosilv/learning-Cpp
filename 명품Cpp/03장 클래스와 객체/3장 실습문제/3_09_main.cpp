/*
* Oval Ŭ������ �־��� �簢���� �����ϴ� Ÿ���� �߻�ȭ�� Ŭ�����̴�.
* Oval Ŭ������ ����ο� �����η� ������ �ۼ��϶�.
*
* �������:	int�� width, height;
* ����Լ�:	������(1. �Ű�����X: ���� 1�ʱ�ȭ)(2. �Ű�����2: ������� ä����)
*			�Ҹ���: ��������� ���
*			��������� ���� �Լ� 2��(getWidth, getHeight)
*			��������� �����ϴ� �Լ�(set(int w, int h))
*			show() ��������� ���
*/
#include <iostream>
#include "3_9_Oval.h"
using namespace std;

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
	return 0;
}