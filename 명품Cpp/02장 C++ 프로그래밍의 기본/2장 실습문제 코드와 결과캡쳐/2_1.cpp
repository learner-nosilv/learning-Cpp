#include <iostream>		// cout, cin ��ü�� �ʿ��Ͽ�, C++ ǥ������¶��̺귯�� ��������� ����Ѵ�
using namespace std;	// std �̸������� ����� ��� �̸��� ���� std::�� �����Ѵ� (��� C++ ǥ�ض��̺귯���� std �̸������� ��������ִ�)

int main() {
	for (int num = 1; num <= 100; num++) {
		cout << num;	// 1~100���� �� ��� + ��
		if (!(num % 10)) {
			cout << endl;		// ���� 10���� �������� �����ϱ�
		}
		else
			cout << '\t';		// �� �������� ������ �и��ϱ�
	}
	return 0;
}

/* BOOK SOLUTION
int main() {
	for(int i=1; i<=100; i++) {
		cout << i;
		if(i%10 == 0) // 10�� ����� ���
			cout << endl;
		else
			cout << '\t';
	}
}
*/
