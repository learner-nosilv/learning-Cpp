#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout.setf(ios::showbase);	// ���� ���ȭ

	cout.width(8); cout << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa\n";

	for (int i = 0; i <= 50; i += 5) {
		cout.width(8); cout.fill('.'); cout.setf(ios::dec); cout << i;	// �����ڸ� ������� ����
		cout << setw(10) << setfill(' ') << oct << i;
		cout << setw(10) << setfill(' ') << hex << i << '\n';			// ����ϴ°� ���ϱ� �ϳ׿�
	}
	return 0;
}