#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5];

	for (int i = 0; i < 5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}

	string letter = names[0];
	for (int i = 0; i < 5; i++) {
		if (letter < names[i]) {
			letter = names[i];
		}
	}
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << letter << endl;
	return 0;
}