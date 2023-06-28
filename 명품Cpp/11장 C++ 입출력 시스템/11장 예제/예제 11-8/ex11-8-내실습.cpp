#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout.setf(ios::showbase);	// 진수 명시화

	cout.width(8); cout << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa\n";

	for (int i = 0; i <= 50; i += 5) {
		cout.width(8); cout.fill('.'); cout.setf(ios::dec); cout << i;	// 조작자를 사용하지 않음
		cout << setw(10) << setfill(' ') << oct << i;
		cout << setw(10) << setfill(' ') << hex << i << '\n';			// 사용하는게 편하긴 하네요
	}
	return 0;
}