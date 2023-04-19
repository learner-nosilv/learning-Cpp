/* 1. 
*  색을 R G B (값: int 0~255)로 추상화한 Color 클래스 선언 및 활용 빈칸 채우기 
*/

#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() {								// 생성자: 기본 생성자
		red = green = blue = 0;
	}
	Color(int r, int g, int b) {			// 생성자: 매개변수 3개
		red = r;
		green = g;
		blue = b;
	}
	void setColor(int r, int g, int b) {	// 멤버변수 R G B 값을 할당하는 함수
		red = r;
		green = g;
		blue = b;
	}	// 생성자에서 이 함수를 사용해도 될 듯
	void show() {							// 멤버변수 R G B 값을 콘솔출력하는 함수
		cout << red << ' ' << green << ' ' << blue << endl;
	}
};

int main() {
	Color screenColor(255, 0, 0);	// 빨간 Color 객체 생성
	Color* p;						// Color 객체 포인터변수 p 선언
	p = &screenColor;				// (1) p가 screenColor의 주소를 가지도록 코드작성
	p->show();						// (2) p와 show()를 이용하여 screenColor 색 출력
	Color colors[3];				// (3) Color의 일차원 배열 colors 선언, 원소는 3개
	p = colors;						// (4) p가 colors 배열을 가리키도록 코드 작성

	// (5) p와 setColor()를 이용하여 colors의 원소가 각각 빨, 초, 파랑색을 가지도록 코드작성
	(p + 0)->setColor(255, 0, 0);	// [0] 빨강
	(p + 1)->setColor(0, 255, 0);	// [1] 초록
	(p + 2)->setColor(0, 0, 255);	// [2] 파랑

	// (6) for문, p, show()를 이용하여 colors 배열의 모든 객체의 색 출력
	for (int i = 0; i < 3; i++) {
		(p + i)->show();
	}
}


/* [book solution]
* 차이점: 나는 모두 pointer -> 로 멤버에 접근했고, 솔루션은 *(pointer). 도 사용함
#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0;	}
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' '<< green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);	// 빨간색의 screenColor 객체 생성
	Color *p;						// Color 타입의 포인터 변수 p 선언
	p = &screenColor;				// (1) p가 screenColor의 주소를 가지도록 코드 작성
	p->show();						// (2) p와 show()를 이용하여 screenColor 색 출력
	Color colors[3];				// (3) Color의 일차원 배열 colors 선언. 원소는 3개
	p = colors;						// (4) p가 colors 배열을 가리키도록 코드 작성

	// (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
	// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);

	// (6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
	for(int i=0; i<3; i++) {
		p[i].show();
	}

	// (6)은 다음과 같이 할 수도 있다.
	//for(int i=0; i<3; i++) {
	//	(p+i)->show();
	//}
}
*/