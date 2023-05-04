/* 3. big() �� ȣ���ϴ� main�Լ��� ���� (1) function overloading ���� (2) default parameter ����
	big(int a, int b, int ���Ѽ�): a�� b�� ū ���� ���ϰ�, �� ���� ���Ѽ��� ���������� ����, ������ ������ ���Ѽ�����
*/
#include <iostream>
using namespace std;

int big(int a, int b, int max=100) {
	int bigger = (a > b ? a : b);
	bigger = (bigger > max ? max : bigger);
	return bigger;
}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;

	return 0;
}