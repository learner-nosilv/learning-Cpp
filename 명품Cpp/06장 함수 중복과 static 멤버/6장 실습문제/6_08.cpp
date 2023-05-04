/* 8. 디버깅에 필요한 정보를 저장하는 Trace 클래스 만들기
* 저자는, 실행 도중 정보를 저장하기 위해 Trace 클래스를 만들어 사용하였다.
* Trace클래스를 활용한 다음 프로그램과 결과를 참고하여
* Trace 클래스와 전체 프로그램을 완성하라
* * 유의 * 디버깅 정보는 100개로 제한
*
* Trace 클래스
* 멤버1. field가 (tag, content)인 2차원 배열
* 멤버2. 2차원 배열의 빈 index를 저장하는 int형 변수
*/

#include <iostream>
#include <string>
using namespace std;

class Trace {
	static string tag_content[100][2];	// FIELD (tag:content)인 100행의 배열
	static int empty;
public:
	static void put(string tag, string content);
	static void printf(string tag);
};

// Trace클래스의 static 멤버 Definition
string Trace::tag_content[100][2];
int Trace::empty = 0;

void Trace::put(string tag, string content) {
	if (Trace::empty >= 100)	// 정보가 다 찬 경우
		cout << "디버깅 정보제한 100개를 초과하여 더 이상 저장할 수 없습니다." << endl;

	else {						// content 할당
		Trace::tag_content[Traace::empty][0] = tag;
		Trace::tag_content[Trace::empty][1] = content;
		Trace::empty++;
	}
}

void Trace::printf(string tag = "모든") {
	if (tag == "모든") {
		cout << "----- " << tag << " Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < empty; i++)
			cout << Trace::tag_content[i][0] << ':' << Trace::tag_content[i][1] << endl;
	}
	else {
		cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl;
		for (int i = 0; i < empty; i++) {
			if (Trace::tag_content[i][0] == tag)
				cout << Trace::tag_content[i][0] << ':' << Trace::tag_content[i][1] << endl;
		}
	}
}

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");	// 태그, 디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산");			// 태그, 디버깅 정보 저장
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::printf("f()");		// "f()"태그의 디버깅 정보 모두 출력
	Trace::printf();			// 모든 디버깅 정보 모두 출력

	return 0;
}