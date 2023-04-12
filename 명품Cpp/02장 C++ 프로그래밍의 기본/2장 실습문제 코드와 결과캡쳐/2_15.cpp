/*
* 덧셈+, 뺄셈- 곱셈* 나눗셈/ 나머지% 정수 5칙연산 계산기
* 요구사항1. 한 번에 숫자 연산자 숫자 입력받기
* 요구사항2. 공백문자로 입력을 구분하기: 입력스트림버퍼는 공백이나 개행, 탭 단위로 입력값을 처리한다
* 요구사항2. atoi(Ascii TO Integer)
* 
* 1. 크기가 4인 char형 배열에 숫자같은 문자, 연산자, 숫자같은 문자를 입력받고 처리
	(문자를 숫자로 취급해서 계산해야할 땐 atoi(), <cstdlib> 이용?)
* 2. 예외처리: 입력버퍼오류나 그 외 오류의 경우, 오류임을 알리고 반복문 continue
* 3. switch문을 이용하여 올바른 연산식으로 바로 분기

* 반복문을 사용해서 계속 계산

* 비고:
* 아무리 생각해도, int, char, int로 받는게 현명한 듯......
*/

#include <iostream>
using namespace std;

bool isError() {	// 입력스트림버퍼 오류처리
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		return true;
	}
	else
		return false;
}

int main() {
	int a, b;	// 숫자
	char oper;	// 연산자

	// 계산기 작동시작
	while (1) {
		// 1. 한 번에 입력받기
		cout << "? ";
		//  (입력스트림버퍼는 공백이나 개행, 탭 단위로 입력값을 처리한다.)
		cin >> a;
		cin >> oper;
		cin >> b;

		// 2. 입력버퍼오류처리
		if (isError()) {
			cout << "!ERROR!" << endl;	// 오류임을 알리고
			return 0;					// 계산기 작동종료
		}

		// 3. 정상입력의 경우
		int result = 0;
		switch (oper) {
			case '+':
				result = a + b;
				break;
			case '*':
				result = a * b;
				break;
			case '-':
				result = a - b;
				break;
			case '/':
				result = a / b;
				break;
			case '%':
				result = a % b;
				break;
			default:
				cout << "!ERROR!" << endl;	// 오류임을 알리고
				return 0;					// 계산기 작동종료
		}
		// 4. 결과 출력
		cout << a << " " << oper << " " << b << " = " << result << endl;
	}
	return 0;
}

/* 고뇌의 흔적
// x를 입력받기 전까지 계산기 무한작동
while (1) {
	char expression[3][4];	// 크기가 4인 문자열을 3개(숫자형 문자, 연산기호, 숫자형 문자) 준비

	// 1. 식 입력받기
	cout << "? ";
	for (int i = 0; i < 3 && expression[3][0] != 'x'; i++) {	// 종료입력을 받기 전 까지
		cin >> expression[i];
	}

	// 2. 입력값 처리 및 계산
	//	상황1. 입력오류처리
	if (isError) {					// 입력버퍼 state가 오류라면
		cout << "!ERROR!" << endl;	// 오류임을 알리고
		expression[0][0] = '\0';	// 입력값이 저장된 expression을 초기화하고
		continue;					// 다시 루프의 처음으로 돌아간다
	}
	//	상황2. 종료명령을 받은 경우, 계산기 종료
	else if (expression[3][0] == 'x') {
		cout << "계산을 종료합니다" << endl;
		return 0;
	}

	// 상황3. 정상입력의 경우 switch문을 통해 올바른 연산식으로 분기
	switch (expression[1]) {
		case'+':
			int result = atoi(expression[0]) * atoi(expression[2]);
	}
	*/