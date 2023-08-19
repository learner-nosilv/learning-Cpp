/* �������� 6. concat()�Լ� �ۼ��ϱ�
	�迭 a, b�� ������ ���ο� �迭�� �����Ͽ� �����ϴ� �Լ�
	����: �޸𸮺�����
	����: �� �迭 �� �ϳ��� NULL�� ���
	����: sizea, b�� ������ ���� ��� int Ÿ���� ���� �߻� */
#include <iostream>
using namespace std;

int* concat(int a[], int sizea, int b[], int sizeb) throw (int) {
	if (sizea <= 0 || sizeb <= 0) throw 1;
	if (a == NULL || b == NULL) throw 2;
	int* result = new int[sizea + sizeb];
	int idx = 0;
	for (; idx < sizea; idx++)
		result[idx] = a[idx];
	for (int i = 0; i < sizeb; i++, idx++)
		result[idx] = b[i];
	return result;
}

int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	int y[] = { 10, 20, 30, 40 };
	try {
		int* p = concat(x, 5, y, 4);
		for (int n = 0; n < 9; n++) cout << p[n] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (int failCode) {
		cout << "���� �ڵ� : " << failCode << endl;
	}
	return 0;
}