/* 2.
* ���� 5�� �����Ҵ�
* �Է¹ޱ�
* ��ձ��ϰ� ����ϱ�
* �����Ҵ�-�Ҹ�
*/

#include <iostream>
using namespace std;

int main() {
	// 1. ũ�Ⱑ 5�� ������ �迭 �����Ҵ�
	int* p = new int[5];			

	// 2. ���� 5�� �Է¹ޱ�
	cout << "���� 5�� �Է�>> ";		// ����
	for (int i = 0; i < 5; i++)		// 5�� �Է¹ޱ�
		cin >> *(p + i);

	// 3. ��� ���Ͽ� ����ϱ�
	double average = *(p);
	for (int i = 1; i < 5; i++)
		average += *(p + i);
	average /= 5;
	cout << "��� " << average << endl;

	// 4. �����Ҵ� -> �Ҹ�
	delete[]p;

	return 0;
}