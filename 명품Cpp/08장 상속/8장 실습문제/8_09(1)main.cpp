/* 9. ����� ���� ���α׷� :
	1. 3������ ����ð����� ����ⱸ�� -> ����� ��ü
	2. ����� �� �¼� 8�� ���� : �¼���ȣ, �̸� ����
	3. ���� / ��� / ���� / ������
	����� Ŭ���� : ��� �¼�(string �迭)
	���� Ŭ���� : ����� 3 �迭
	*/
#include <iostream>
#include <string>
#include "8_09(1)Reservation.h"
using namespace std;

int main() {
	Reservation hansung("�Ѽ��װ�", 3);			// �Ѽ��װ�, ����� 3��
	hansung.setPlain(0, "07��", 8);				// �����[0]: �ð�, �¼���
	hansung.setPlain(1, "12��", 8);				// �����[1]: �ð�, �¼���
	hansung.setPlain(2, "17��", 8);				// �����[2]: �ð�, �¼���
	hansung.start();

	return 0;
}