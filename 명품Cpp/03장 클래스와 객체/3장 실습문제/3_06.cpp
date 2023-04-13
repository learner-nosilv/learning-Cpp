/* ������ ��
* ����: Random Ŭ���������
* �������: ?
* ����Լ�:	������, next(), nextInRange(int, int)
*
* �ʿ��� ���
	1. <cstdlib> random ����(srand rand RAND_MAX, ...)
	2. <ctime> time()
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random {
public:
	int next();
	int nextInRange(int l, int h);
};

int Random::next() {
	return rand();
}

int Random::nextInRange(int l, int h) {
	if (l > h) {			// �Է¿���ó��1. �������� �˸��� ���α׷� ���� 
		cout << "!!�Է¿���!!" << endl;
		exit(1);
	}
	return l + (rand() % (h - l + 1));
}

// -----------------------------------------------

class EvenRandom {
public:
	int next();
	int nextInRange(int l, int h);
};

int EvenRandom::next() {
	int even_num = 0;
	while (1) {
		even_num = rand();
		if ((even_num % 2) == 0)
			return even_num;
	}
}

int EvenRandom::nextInRange(int l, int h) {
	if (l > h) {			// �Է¿���ó��2. �ڹٲٱ�
		int temp = l;
		l = h;
		h = l;
	}
	else if (l % 2 != 0) {
		l++;
	}
	int even_num = (h - l + 2) / 2;				// (��) l, h�� 2, 3�̸� 1 / 2, 4�̸� 2 / 2, 5�̸� 2
	even_num = l + (rand() % even_num) * 2;		// (��) num�� 1�̸� 2 + 0, 2�̸� 2 + (0, 2)

	return even_num;
}

int main() {
	srand((unsigned)time(NULL));

	Random r;
	EvenRandom er;

	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "10 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}