// C���α׷� C++�� �����ϱ�
// ����N�� �Է¹޾Ƽ� 1~N������ �� ���

#include <iostream>		// <stdio.h>�� ���
using namespace std;	// namespace ���� ����

int sum(int, int);		// �Լ� ���� ����

int main() {
	int n = 0;
	cout << "�� ���� �Է��ϼ���>>";	// printf()
	cin >> n;						// scanf("%d", &n)
	cout << "1���� " << n << "������ ���� " << sum(1,n) << " �Դϴ�." << endl;

	return 0;
}

// �Լ�sum: a���� b������ �ջ갪�� ��ȯ�Ѵ�.
int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {		// k: a ~ b ����
		res += k;					// k ~ n �ջ�
	}
	return res;
}