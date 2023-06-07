/* 2. 두 개의 배열을 비교하여 모두 같으면 true를 아니면 false를 리턴하는 제네릭함수*/
#include <iostream>
using namespace std;

template <class T> bool equalArrays(T a, T b, int size) {
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			return false;
	return true;
}
int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	int z[] = { 97, 97, 97, 97, 97 };

	char a[] = { 'z', 'y', 'x', 'a', 'b', 'c' };
	char b[] = { 'z', 'y', 'x', 'a', 'b', 'c' };
	char c[] = { 'a', 'a', 'a', 'a', 'a', 'a' };

	if (equalArrays(x, y, 5)) cout << "같다\n";			// 같다
	else cout << "다르다\n";

	if (equalArrays(y, z, 5)) cout << "같다\n";			// 다르다
	else cout << "다르다\n";

	if (equalArrays(a, b, 5)) cout << "같다\n";			// 같다
	else cout << "다르다\n";

	if (equalArrays(b, c, 5)) cout << "같다\n";			// 다르다
	else cout << "다르다\n";

	if (equalArrays(z, (int*)c, 5)) cout << "같다\n";	// 같다고 할 줄..
	else cout << "다르다\n";

	return 0;
}