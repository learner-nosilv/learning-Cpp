/* 8. 7의 문제를 수정하기
* 원을 추상화한 클래스 Circle
* 멤버변수: 반지름 radius
* 멤버함수: 반지름설정 setRadius, 면적리턴 getArea
* 
* 메인함수
* 1. 원의 개수를 입력받고 circle 객체배열 동적할당 (기존: 3개의 circle 객체 배열선언)
* 2. 객체의 반지름 값 입력받아서 설정하기
* 3. 면적이 100보다 큰 원의 개수 출력
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int r) {
		radius = r;
	}
	double getArea() {
		return 3.24 * radius * radius;
	}
};

int main() {
	// 1. 원의 개수 입력받고 N개의 Circle 객체 배열 동적할당
	int n;
	cout << "원의 개수 >> ";
	cin >> n;
	Circle* p = new Circle[n];
	int wider = 0;

	// 2. 반지름 값 입력받아서 설정하기 + 100보다 큰 원의 갯수 세기
	for (int i = 0; i < n; i++) {
		int r;
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		(p+i)->setRadius(r);

		if ((p + i)->getArea() > 100)
			wider++;
	}
	
	// 3. 면적이 100보다 큰 원의 개수 출력
	cout << "면적이 100보다 큰 원은 " << wider << "개 입니다" << endl;

	// 4. 동적할당 반환
	delete[] p;
	return 0;
}
