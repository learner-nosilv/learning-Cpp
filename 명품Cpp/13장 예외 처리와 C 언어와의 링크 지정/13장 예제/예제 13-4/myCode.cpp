/* 예제 13-4. 합과 인원수를 입력받아 평균을 내는 무한루프 프로그램 작성하기 */
#include <iostream>
using namespace std;

int main() {
	int n, sum, average;
	while (true) {
		cout << "합을 입력하세요>>";
		cin >> sum;					// 합 입력받기
		if (cin.fail()) {			// 문자를 입력한 경우
			cin.clear();
			cin.ignore(99, '\n');
			cout << "[ERROR] '숫자'를 입력하세요.\n";
			continue;
		}
		cout << "인원수를 입력하세요>>";
		cin >> n;					// 인원수 입력받기
		try {
			if (n <= 0)				// 예외발생 값 입력: 0이하를 입력한 경우
				throw n;			// 예외처리
			else					// 정상적 입력
				average = sum / n;	// 정상처리: 합/인원수
		}
		catch (int x) {
			cout << "예외 발생!! " << x << "(으)로 나눌 수 없음\n" << endl;
			continue;
		}
		cout << "평균 = " << average << '\n' << endl;
	}
	return 0;
}