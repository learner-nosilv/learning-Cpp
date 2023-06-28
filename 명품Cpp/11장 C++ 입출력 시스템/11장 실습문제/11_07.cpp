/* 7. 0-127까지 ASCII 코드와 해당 문자를 다음과 같이 출력, 출력불가한 ASCII코드는 '.'으로 출력 */
#include <iostream>
#include <iomanip>	// 매개변수가 있는 조작자
#include <cctype>	// 출력가능한 문자인지 알려주는 함수 bool isprint()
using namespace std;

int main() {
	cout.setf(ios::left);
	for (int i = 0; i < 4; i++)
		cout << "dec    hexa    char    ";
	cout << '\n';
	for (int i = 0; i < 4; i++)
		cout << "---    ----    ----    ";
	cout << '\n';
	for (int i = 0; i < 128;) {
		for (int j = 0; j < 4; j++) {
			cout << setw(7) << dec << i;
			cout << setw(8) << hex << i;
			if (isprint(i))
				cout << setw(8) << (char)i;
			else
				cout << setw(8) << '.';
			i++;
		}
		cout << '\n';
	}
	return 0;
}