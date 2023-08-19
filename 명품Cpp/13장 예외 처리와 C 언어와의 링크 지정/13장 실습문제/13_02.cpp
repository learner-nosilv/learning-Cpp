/* 연습문제 2. 점수 -> 학점 출력 프로그램
	예외: 0~100점을 벗어나는 점수는 예외처리 */
#include <iostream>
using namespace std;

int main() {
	int score;
	while (true) {
		cout << "0-100점 사이의 점수를 입력하세요 >> ";
		cin >> score;
		try {
			if (cin.fail()) throw "정수가 아닌 문자입력오류";
			if (score < 0 || score>100) throw "0-100점 외의 점수입력오류";
			cout << "학점 >> ";
			if (score < 60) cout << 'F' << endl;
			else if (score < 70) cout << 'D' << endl;
			else if (score < 80) cout << 'C' << endl;
			else if (score < 90) cout << 'B' << endl;
			else cout << 'A' << endl;
		}
		catch (const char* msg) {
			if (msg == "정수가 아닌 문자입력오류") {
				cin.clear();
				cin.ignore(99, '\n');
			}
			cout << msg << endl;
		}
	}
	

	return 0;
}