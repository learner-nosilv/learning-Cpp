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

class SelectableRandom {
	int table;
public:
	// ������: ��ü�� ������ ��, ¦������(t=0)���� Ȧ������(t=1)���� �����ϵ��� ��
	SelectableRandom(int t) {
		table = t;
	}
	int next();
	int nextInRange(int l, int h);
};

int SelectableRandom::next() {
	int even_num = (rand() / 2) * 2;	// 0~32767������ ¦������
	switch (table) {	// ¦��/Ȧ�� ������ü üũ
	case 0:				// ¦��������ü���,
		return even_num;		// �״�� ����
	case 1:				// Ȧ��������ü���,
		return even_num + 1;	// 1�� ���ؼ� ����
	}
}

int SelectableRandom::nextInRange(int l, int h) {
	if (l > h) {
		int temp = l;
		l = h;
		h = temp;
	}

	switch (table) {
		case 0:
			if (l % 2 == 1) {
				l++;
			}
				
		case 1:
			if (l % 2 == 0) {
				l++;
			}
		return l + 2 * (rand() % ((h - l + 2) / 2));
	}
}

int main() {
	srand((unsigned)time(NULL));

	SelectableRandom even_rand(0);	// ¦�� ���� ��ü
	SelectableRandom odd_rand(1);	// Ȧ�� ���� ��ü

	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = even_rand.next();
		cout << n << ' ';
	}

	cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = odd_rand.nextInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}