// C���α׷� C++�� �����ϱ�
// ����N�� �Է¹޾Ƽ� 1~N������ �� ���

#include <iostream>		// <stdio.h>�� ���
using namespace std;	// namespace ���� ����

int main() {
	int k, n = 0;
	int sum = 0;

	cout << "�� ���� �Է��ϼ���>>";	// printf()
	cin >> n;						// scanf("%d", &n)
	for (k = 1; k <= n; k++) {		// k: 1 ~ n ����
		sum += k;					// 1 ~ n �ջ�
	}
	cout << "1���� " << n << "������ ���� " << sum << " �Դϴ�." << endl;
	return 0;
}

/* SOLUTION of BOOK
* #include <iostream>
using namespace std;

int main() {
	int n=0;
	cout << "�� ���� �Է��ϼ���>>";
	cin >> n;
	if(n <= 0) {
		cout << "����� �Է��ϼ���!" << endl;
		return 0;
	}
	int k, sum=0;
	for(k=1; k<=n; k++) {
		sum += k;
	}
	cout << "1���� " << n << "������ ���� " << sum << "�Դϴ�." << endl;
	return 0;
}
*/