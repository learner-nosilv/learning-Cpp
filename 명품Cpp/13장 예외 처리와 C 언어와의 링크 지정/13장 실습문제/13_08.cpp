/* �������� 8. copy()�� int�� �迭�� �����Ͽ�, ���纻�� �����͸� �����Ѵ�.
	���簡 ����ġ �ʴ� ���, ���� �Ű������� failCode�� ������ �����ڵ带 �����ϰ� NULL�� �����Ѵ�.
	�� �Լ��� ������ ��ġ�� try-catch ����� ����Ͽ� �����϶�.
	�ڵ尡 ưư�ϰ� �ܼ�������.
*/
#include <iostream>
using namespace std;

int* copy(int* src, int size) throw(int) {
	if (size < 0) throw (-1);			// too small
	else if (size > 100) throw(-2);		// too big
	else if (src == NULL) throw(-4);	// NULL source
	int* p = new int[size];
	if (p == NULL) throw(-3);			// memory short
	for (int n = 0; n < size; n++) p[n] = src[n];
	return p;
}

int main() {
	int x[] = { 1, 2, 3 };
	try {
		int* p = copy(x, 3);
		for (int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (int failCode) {
		cout << "�����ڵ� : " << failCode << endl;
	}
	return 0;
}