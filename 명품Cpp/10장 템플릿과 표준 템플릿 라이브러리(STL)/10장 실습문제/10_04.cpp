/*4. �迭���� ���Ҹ� �˻��ϴ� search() ���׸� �Լ� �ۼ��ϱ�
	ù��° �Ű� ����: �˻��ϰ��� �ϴ� ��
	�ι�° �Ű� ����: �迭
	����° �Ű� ����: �迭�� ����
	����: ������ true, ������ false
*/
#include <iostream>
using namespace std;

template <class T> bool search(T value, T arr[], int size) {
	if (size <= 0) return false;
	for (int i = 0; i < size; i++)
		if (arr[i] == value) return true;
	return false;
}

int main() {
	char x[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'b', 'u', 'd', 'd', 'y', '?' };
	cout << "o �� �迭 x�� ���ԵǾ� ";
	if (search<char>('o', x, 13)) cout << "�ִ�\n";
	else cout << "���� �ʴ�\n";
	cout << "1 �� �迭 x�� ���ԵǾ� ";
	if (search<char>('1', x, 13)) cout << "�ִ�\n";
	else cout << "���� �ʴ�\n";

	double y[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	cout << "11 �� �迭 y�� ���ԵǾ� ";
	if (search<double>(11, y, 6)) cout << "�ִ�\n";
	else cout << "���� �ʴ�\n";
	cout << "6.6 �� �迭 y�� ���ԵǾ� ";
	if (search<double>(6.6, y, 6)) cout << "�ִ�\n";
	else cout << "���� �ʴ�\n";

	return 0;
}