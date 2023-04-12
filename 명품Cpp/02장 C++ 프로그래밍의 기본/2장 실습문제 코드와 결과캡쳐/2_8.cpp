/* 프로그램 설명
* 입력: ';'를 구분문자로 이름 5개를 한 번에 입력받는다.
* 기능: 5개의 이름을 각 다른 문자열 변수(크기100)에 저장하고, 가장 긴 이름을 판별한다.
* 출력: 모든 이름과 가장 긴 이름을 콘솔에 출력한다.
* 
* 입력을 위해 cin.getline( , , ';')가 필요하므로 문자열은 C-string 방식을 이용한다.
* 이름을 저장하기 위해서는 char name[100]형식의 문자열을 5개를 사용해야하고
* 한 번의 입력으로 5개를 모두 저장해야하므로,반복문을 사용해야한다. for(5번){cin>>...}
* 
* 5회의 저장과 4회의 비교를 위해서는
* 반복문의 요소(i)와 5개의 이름(char name[100])을 엮어야하므로, 5개의 이름에 index가 있으면 좋다.
* 따라서, 이름은 char name[5][100]이 적절하다.
* 
* 가장 긴 이름을 판별하기위해서는 strlen()함수가 필요하므로 cstring 라이브러리를 이용한다 <cstring>
* 
* 5 명을 N 명으로 일반화하면 더 유용하므로, 입력받을 이름의 갯수는 전역변수로 지정해놓는다. #define NUM 5
*/

#include <iostream>
#include <cstring>		// strlen() 이용

#define NUM 5			// 이름 갯수

using namespace std;

int main() {
	// 1. 각 이름이 99자 이내인 NUM 명의 이름을 저장할 2차원 배열 선언 
	char name[NUM][100];
	
	// 2. 한 번의 입력을 ';'를 구분문자로 하여 변수 NUM 개에 할당하기
	cout << NUM << " 명의 이름을 ';'으로 구분하여 입력하세요\n>>";
	for (int i = 0; i < NUM; i++) {			// 아래의 코드를 NUM 회 반복
		cin.getline(name[i], 100, ';');		// 최대 100자를 입력받아서 ';' 앞까지를 문자열처리하여, name[0]~name[NUM-1]에 저장
	}
	
	// 3. 반복문을 이용한 출력과 동시에 긴 이름 찾기
	int index_long = 0;					// 가장 긴 이름의 index를 저장하는 변수
	int length_long = 0;				// 가장 긴 이름의 길이를 저장하는 변수
	int length_now = 0;					// 현재 이름의 길이를 저장하는 변수

	for (int i = 0; i < NUM; i++) {					// 아래의 코드를 NUM 회 반복
		cout << i + 1 << " : " << name[i] << endl;	// 이름 출력하기
		length_now = (int) strlen(name[i]);			// length_now에 출력한 이름의 길이값 할당, size_t 형으로 리턴하므로 int형변환을 한다. 

		if (length_long < length_now) {				// 출력한 이름의 길이가 더 길다면
			length_long = length_now;				// 가장 긴 이름의 길이를 갱신하고
			index_long = i;				// 가장 긴 이름의 인덱스도 갱신한다.
		}
	}

	// 4. 가장 긴 이름 출력
	cout << "가장 긴 이름은 " << name[index_long] << endl;

	return 0;
}