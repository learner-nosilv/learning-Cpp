/* 7. ������ ���� static ����� ���� Ramdom Ŭ���� �ϼ��ϱ�
* Random Ŭ������ �̿��Ͽ� ������ ���� ������ ���� ����ϴ� main()�Լ��� �ۼ��ϱ�
* seed()�� main()���� Ȱ���ϱ�
* 
* 1. ��������: rand(max-min+1) + min
* 2. ��������: 'a'-'z', 'A'-'Z'
*/
#include <iostream>	// ǥ������� ����
#include <cstdlib>	// random ����
using namespace std;

class Random {
public:
	// �׻� �ٸ� �������� �߻���Ű�� ���� seed�� �����ϴ� �Լ�
	static void seed() { srand((unsigned)time(NULL)); }	// ���������� �����ϴ� seed����
	static int nextInt(int min = 0, int max = 32767);	// min - max ����(�� ����)�� ������������
	static char nextAlphabet();							// �������ĺ� ����
	static double nextDouble();							// 0�̻� 1�̸��� 0.- ������ �����Ǽ�����
};

int Random::nextInt(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

char Random::nextAlphabet() {
	if (rand() % 2)	// 0 or 1
		return ((rand() % ('z' - 'a' + 1)) + 'a');
	else
		return ((rand() % ('Z' - 'A' + 1)) + 'A');
}

double Random::nextDouble() {
	double result= (double)rand() / RAND_MAX;
	return (result != 1 ? result : nextDouble()); // (RAND_MIN~RAND_MAX) / RAND_MAX = [0~1]
}

int main() {
//	Random a;					// ���� ����/�Ǽ��� �߻���ų �� �ִ� Ŭ���� ��ü �� ���� �ǳ�

	int size = 10;				// ���� ����, ����, �Ǽ� ����
	int min = 1, max = 100;		// ���� ���� ����

	Random::seed();

	cout << min << "���� " << max << "���� ������ ���� " << size << "���� ����մϴ�" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextInt(min, max)<< ' ';
	cout << endl;

	cout << "���ĺ��� �����ϰ� " << size << "���� ����մϴ�" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "������ �Ǽ� " << size << "���� ����մϴ�" << endl;
	for (int i = 0; i < size; i++)
		cout << Random::nextDouble() << ' ';
	cout << endl;

	return 0;
}