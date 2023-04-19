/*
* 문자열로 덧셈식을 입력받아서 실제로 계산하는 프로그램
* 1. getline(cin, , )으로 식 입력받기: 완전 엉터리로 입력되는 경우는 제외
* 2. find 이용하여 + 찾기 : if + 위치가 -1 : 숫자만 있다는 것 string 전부 -> int 그게 답
							if + 위치가 [I] : 0-[I-1]까지 숫자로 만들고 result에 집어넣기
	 find 이용하여 I+1부터 + 찾기
* 
*/
#include <iostream>
#include <string>
using namespace std;

bool isInputError() {
	if (cin.fail()) {	// 버퍼에 오류가 났다면,
		cin.clear();	//  상태를 정상으로 초기화하고
		cin.ignore(100, '\n');	// 개행문자까지 최대 100글자를 비우기
		return true;	// 오류였음을 알리기
	}
	else
		return false;
}

int main() {
	// 1. 식 입력받기
	string exp;			// 식

	do {
		cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
		cin >> exp;			// getline(cin, exp, '\n');
	} while (isInputError());

	int size = exp.size();	// 식에서, 총 문자 개수
	int result = 0;			// 식을 계산한 결과값
	int startIndex = 0;		// 숫자가 시작되는 인덱스 
	int count;				// 숫자의 갯수
	int exp_idx = -1;		// 식에서, +의 위치를 저장할 인덱스
	
	// 2. 식에서 숫자값만 빼어 연산하기
	while (startIndex<size) {	// 인식이 다 되기 전까지 반복
		exp_idx = exp.find('+', (exp_idx + 1));		// 아직 인식되지 않은 곳부터 + 찾기

		if (exp_idx == -1) {						// 1) 더 이상 +가 없다면: num_idx ~ 끝까지 숫자라면 [마지막이라는 의미]
			count = size - startIndex;				// 그 숫자형태의 문자열에서 문자의 갯수
			int operand = stoi(exp.substr(startIndex, count));	// 문자 -> 숫자로 변환
			cout << operand << endl;							// 해당 숫자 출력
			result += operand;						// 합 연산
			break;									// 루프 탈출
		}
		else {					// 2) 마지막의 +가 아니면서도 인식되지 않은 +가 존재한다면
			count = exp_idx - startIndex;			// + 전까지, 문자의 갯수 (substr에 필요)
			int operand = stoi(exp.substr(startIndex, count));	// 문자 -> 숫자로 변환
			cout << operand << endl;							// 해당 숫자 출력
			result += operand;						// 합 연산
			startIndex = exp_idx + 1;					// 다음 숫자 시작 인덱스는 + 다음으로 설정
		}
	}

	// 3. 결과값 출력하기
	cout << "숫자들의 합은 " << result << endl;

	return 0;
}

/*	[book solution]
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n'); // 문자열 입력
	int sum = 0;
	int startIndex = 0; // 문자열 내에 검색할 시작 인덱스

	// 완전 무한루프
	while(true) {
		int fIndex = s.find('+', startIndex);			// 검사해야하는 인덱스부터 + 찾기
		if(fIndex == -1) { // '+' 문자 발견할 수 없음		// 만일 +가 이제 없다면
			string part = s.substr(startIndex);			// 검사해야하는 인덱스부터 끝까지 추출 (= 전부 숫자 or 공백)
			if(part == "") break; // "2+3+", 즉 +로 끝나는 경우	// 만일 공백이라면, 아무 것도 하지 않기
			cout << part << endl;								// 공백이 아니라면, 숫자 출력
			sum += stoi(part); // 문자열을 수로 변환하여 더하기		// 실제로 숫자화하여 더하기
			break;												// 연산종료
		}
		// +가 있는 경우
		int count = fIndex - startIndex;				// 숫자갯수 (서브스트링으로 자를 문자 개수)
		string part = s.substr(startIndex, count);		// startIndex부터 count 개의 문자로 서브스트링 만들기
		cout << part << endl;
		sum += stoi(part);								// 문자열을 수로 변환하여 더하기
		startIndex = fIndex+1;							// 검색을 시작할 인덱스 전진시킴
	}
*/