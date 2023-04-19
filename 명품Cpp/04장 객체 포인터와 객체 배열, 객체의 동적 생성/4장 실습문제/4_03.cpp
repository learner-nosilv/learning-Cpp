/* 3.
* string 클래스를 이용하여 빈칸을 포함하는 문자열 입력받기 getline(cin,변수,구분자)
* a가 몇 개 있는지 출력하기 - .find(문자열, -부터)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// 1. 공백을 포함한 문자열 입력받기, 구분자는 '/n'개행
	string sentence;
	cout << "문자열 입력>> ";
	getline(cin, sentence, '\n');

	// 2 (1). string 클래스의 멤버 at()나 []를 이용하여 작성하기
	int start_idx = 0;
	int counter = 0;
	int size = sentence.size();

	for (int i = 0; i < size; i++) {
		if (sentence[i] == 'a')
			counter++;
	}

	cout << "문자 a는 " << counter << "개 있습니다." << endl;

	// ------------------------------------
	// 2 (2). find() 멤버 함수를 이용하여 작성하기
	
	start_idx = sentence.find('a');
	counter = 0;

	while (start_idx != -1) {
		counter++;
		start_idx = sentence.find('a', start_idx + 1);
	}

	cout << "문자 a는 " << counter << "개 있습니다." << endl;

	return 0;
}