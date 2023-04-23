/* 6.
* 문자열 a에서 문자 c를 찾아 해당 a[] 에 대한 참조를 리턴
* 찾을 수 없다면 success 참조 매개변수에 false를 설정, 찾으면 true
*/

#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success);

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);	// 참조리턴된 공간을 alias = s[0]
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}
	loc = 'm';						// 실제 변경 s[0] = 'm'
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
