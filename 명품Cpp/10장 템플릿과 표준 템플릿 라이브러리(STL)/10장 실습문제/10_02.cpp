/* 2. �� ���� �迭�� ���Ͽ� ��� ������ true�� �ƴϸ� false�� �����ϴ� ���׸��Լ�*/
#include <iostream>
using namespace std;

template <class T> bool equalArrays(T a, T b, int size) {
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			return false;
	return true;
}
int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	int z[] = { 97, 97, 97, 97, 97 };

	char a[] = { 'z', 'y', 'x', 'a', 'b', 'c' };
	char b[] = { 'z', 'y', 'x', 'a', 'b', 'c' };
	char c[] = { 'a', 'a', 'a', 'a', 'a', 'a' };

	if (equalArrays(x, y, 5)) cout << "����\n";			// ����
	else cout << "�ٸ���\n";

	if (equalArrays(y, z, 5)) cout << "����\n";			// �ٸ���
	else cout << "�ٸ���\n";

	if (equalArrays(a, b, 5)) cout << "����\n";			// ����
	else cout << "�ٸ���\n";

	if (equalArrays(b, c, 5)) cout << "����\n";			// �ٸ���
	else cout << "�ٸ���\n";

	if (equalArrays(z, (int*)c, 5)) cout << "����\n";	// ���ٰ� �� ��..
	else cout << "�ٸ���\n";

	return 0;
}