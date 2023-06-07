/*4. 배열에서 원소를 검색하는 search() 제네릭 함수 작성하기
	첫번째 매개 변수: 검색하고자 하는 값
	두번째 매개 변수: 배열
	세번째 매개 변수: 배열의 갯수
	리턴: 있으면 true, 없으면 false
*/
#include <iostream>
using namespace std;

template <class T> bool search(T value, T arr[], int size) {
	if (size <= 0) return false;
	for (int i = 0; i < size; i++)
		if (arr[i] == value) return true;
	return false;
}

int main() {
	char x[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'b', 'u', 'd', 'd', 'y', '?' };
	cout << "o 이 배열 x에 포함되어 ";
	if (search<char>('o', x, 13)) cout << "있다\n";
	else cout << "있지 않다\n";
	cout << "1 이 배열 x에 포함되어 ";
	if (search<char>('1', x, 13)) cout << "있다\n";
	else cout << "있지 않다\n";

	double y[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
	cout << "11 이 배열 y에 포함되어 ";
	if (search<double>(11, y, 6)) cout << "있다\n";
	else cout << "있지 않다\n";
	cout << "6.6 이 배열 y에 포함되어 ";
	if (search<double>(6.6, y, 6)) cout << "있다\n";
	else cout << "있지 않다\n";

	return 0;
}