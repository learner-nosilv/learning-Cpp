/* 커피메뉴와 잔 수를 주문받고 20000원 이상이 되면 종료하는 프로그램
* 반복조건: 총 매출이 20000미만 (루프탈출조건: 현 매출 20000이상)	// while문, 총 매출을 저장할 int형 변수
*	입력cin 한 번에 문자열과 숫자를 입력받음						// cin>>메뉴명>>잔 수	(char형 문자열, int형 변수)
*	예외처리: 버퍼에 오류가 생긴 경우 오류를 처리하고 다시 입력받음	//에러처리함수도입, continue이용
*	정상입력: 현 주문금액 출력	// int형 변수
* 교수님 요구사항: HINT내용에 따를 것 1. 변수명 따르기(메뉴명=coffee) 2. strcmp 이용하기 → <cstring> 라이브러리 사용
*/

#include <iostream>
#include <cstring>

using namespace std;

bool isError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		return true;
	}
	else
		return false;
}

int main() {
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	int total = 0;
	char coffee[100];
	int result = 0;

	// 총 매출이 20000 미만일 때까지 반복
	while (total < 20000) {
		// 1. 주문받기
		cout << "주문>> ";
		cin >> coffee >> result;	// 커피이름과 잔 수를 입력받는다.

		if (isError()||result<=0) {			// 상황1. 입력오류(버퍼오류 혹은 0이하정수입력) 발생
			coffee[0] = '\0';				// 잘못된 입력받은 변수(메뉴명, 잔 수) 재초기화
			result = 0;
			cout << "!입력오류!" << endl;		// 오류임을 알리고 다시 루프시작
			continue;
		}
		else if (!strcmp(coffee, "에스프레소"))	// 상황2. 에스프레소
			result = 2000 * result;	// 잔 수를 담았던 변수에 현 주문금액을 저장
		else if (!strcmp(coffee, "아메리카노"))	// 상황3. 아메리카노
			result = 2300 * result;	// 잔 수를 담았던 변수에 현 주문금액을 저장
		else if (!strcmp(coffee, "카푸치노"))		// 상황4. 카푸치노
			result = 2500 * result;	// 잔 수를 담았던 변수에 현 주문금액을 저장

		else {								// 상황5. 그 외 제대로 된 입력을 못 받은 상황
			coffee[0] = '\0';				// 잘못된 입력받은 변수(메뉴명, 잔 수) 재초기화
			result = 0;
			cout << "!입력오류!" << endl;		// 오류임을 알리고 다시 루프시작
			continue;
		}
		// 2. 제대로 된 입력을 받은 경우 (상황2, 3, 4), 총 매출액에 합산하고 현 주문금액 출력하기
		total += result;	// 현 주문액을 총 매출액에 반영
		cout << result << "원입니다. 맛있게 드세요" << endl;
	}

	// 3. 총 매출이 20000 이상이 된 경우, 총 매출을 출력하고 판매종료
	cout << "오늘 " << total << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
	return 0;
}