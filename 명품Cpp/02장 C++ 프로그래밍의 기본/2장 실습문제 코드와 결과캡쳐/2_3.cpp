#include <iostream>
using namespace std;

// IN: �� ���� �Է¹޾Ƽ�
// COMPUTE: ũ�⸦ ���Ͽ�
// OUT: ū ���� ����Ѵ�

int main() {
	int max, num;				// �� �� ����
	cout << "�� ���� �Է��϶�>>";
	cin >> max >> num;			// �� �� �Է¹ޱ�
	
	if (max < num) max = num;	// ū ���� max�� �Ҵ�

	cout << "ū �� = " << max;	// ū �� ���

	return 0;
}