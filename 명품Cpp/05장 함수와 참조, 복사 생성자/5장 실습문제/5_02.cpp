/* 2.
* main() �Լ��� �������� �����Ͽ� half() �Լ� �ۼ��ϱ�
* ȣ�⹮ half(n) : n�� �ݰ��� ���ؼ� n���� �ٲٱ�
*	n���� ȣ���ϹǷ� call by address �Ұ��� -> reference ���
*/

#include <iostream>
using namespace std;

void half(double& num) {
	num /= 2.0;
}

int main() {
	double n = 20;
	half(n);
	cout << n;
	return 0;
}
// [book solution]�� �ٽ��� ����