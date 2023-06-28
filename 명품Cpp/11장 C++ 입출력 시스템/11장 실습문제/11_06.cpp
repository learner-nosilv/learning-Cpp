/* 6. �ʵ尣�� 15ĭ, ��ĭ_�� ä���, ��ȿ���� 3�ڸ�*/
#include <iostream>
#include <iomanip>			// �Ű������� �ִ� ������
#include <cmath>			// �������� ���ϴ� �Լ� sqrt
using namespace std;

int main() {
	cout.setf(ios::left);	// [flag] left-align
	cout << setw(15) << "Number" << setw(15) << "Square" << setw(15) << "Square Root" << endl;
	for (int i = 0; i < 50; i += 5) {
		cout << setw(15) << setfill('_') << i;									// Number
		cout << setw(15) << setfill('_') << i * i;								// Square
		cout << setw(15) << setfill('_') << setprecision(3) << sqrt(i) << '\n';	// Square Root
	}
	return 0;
}