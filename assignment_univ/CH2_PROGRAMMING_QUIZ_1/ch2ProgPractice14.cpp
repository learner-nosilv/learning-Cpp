#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;

	char coffee[100];	// 커피이름
	int num;			// 잔 수
	int order = 0;		// 주문금액
	int total = 0;		// 총 매출

	while (total < 20000) {	// 총 매출이 20000원 미만일 때만 반복
		// 1. 주문 받기
		cout << "주문>>";
		cin >> coffee >> num;	// 커피이름과 잔수를 입력받는다.

		// 2. 주문 금액 계산하고 출력하기
		if (strcmp(coffee, "에스프레소") == 0)
			order = 2000 * num;
		else if (strcmp(coffee, "아메리카노") == 0)
			order = 2300 * num;
		else if (strcmp(coffee, "카푸치노") == 0)
			order = 2500 * num;
		cout << order << "원입니다. 맛있게 드세요." << endl;

		// 3. 총 매출에 반영하기
		total += order;
	}

	// 4. 총 매출이 20000원 이상일 때 종료
	cout << "오늘 " << total << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
	return 0;
}
