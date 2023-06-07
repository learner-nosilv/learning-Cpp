/* 525p. 1. �迭�� �޾� ���� ū ���� �����ϴ� ���׸� �Լ� biggest() �ۼ��ϱ� & ���
*/
#include <iostream>
using namespace std;

template <class T> T biggest(T arr[], int size) {	// �迭���� ���� ���� ū ������ value ����
	int biggest = 0;				// ���� ū ������ index ����
	for (int i = 1; i < size; i++)	// �˻�
		if (arr[biggest] < arr[i])		// �� ū ���Ұ� �߰ߵǸ�
			biggest = i;			// �ش� �ε����� ���Ҵ�
	return arr[biggest];				// ���� ū ������ �� ����
}

int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	double y[] = { 1.1, 2.2, 5.5, 100, 2, 13.8, 12.5 };
	char z[] = { 'a', 'd', 'e', 'w', 'l' };

	cout << "1, 2, 3, 4, 5 -> " << biggest<int>(x, 5) << '\n'
		<< "1.1, 2.2, 5.5, 100, 2, 13.8, 12.5 -> " << biggest(y, 7) << '\n'
		<< "a, d, e, w, l -> " << biggest(z, 5) << endl;
	return 0;
}
/*
   solution���� ������:
	1. solution�� size�� 0������ ���� ���� ��쵵 ����Ͽ��� ���� �� �ߴ�.
		-> solution�� �� ������
	2. solution�� biggest�� ���� ū ���� �Ҵ��߰�, ���� �ε����� �Ҵ��ߴ�.
		-> solution�� �� ������
	3. solution�� biggest()�� ���� biggest<int>()�� ȣ��
*/