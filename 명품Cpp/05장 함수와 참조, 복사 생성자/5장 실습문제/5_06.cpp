/* 6.
* ���ڿ� a���� ���� c�� ã�� �ش� a[] �� ���� ������ ����
* ã�� �� ���ٸ� success ���� �Ű������� false�� ����, ã���� true
*/

#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success);

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);	// �������ϵ� ������ alias = s[0]
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'm';						// ���� ���� s[0] = 'm'
	cout << s << endl;
}

char& find(char a[], char c, bool& success) {
	int i = 0;
	while (a[i] != '\0') {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
		i++;
	}
	success = false;
}
