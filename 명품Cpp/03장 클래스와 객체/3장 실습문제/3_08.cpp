/*
* int 타입의 정수를 객체화한 Integer 클래스를 작성하라
* 모든 멤버함수는 자동 인라인으로 작성하라(inline 키워드를 사용하지 않은)
* 멤버변수: int integer;
* 멤버함수: int get(), set(), int isEven()
*/

#include <iostream>
#include <string>
using namespace std;

class Integer {
	int integer;
public:
	// 생성자: (자동인라인) 받은 값을 integer타입으로 저장 1. 숫자로 읽을 수 있는 문자를 입력받은 경우
	Integer(string num) { integer = stoi(num); }
	// 생성자: (자동인라인) 받은 값을 integer타입으로 저장 2. integer형으로 입력받은 경우
	Integer(int num) { integer = num; }

	// integer 값 출력
	int get() { return integer; }
	
	// integer 값 변경
	void set(int num) { integer = num; }

	// integer 값이 짝수이면 1, 짝수가 아니면 0출력
	int isEven() {
		return (integer + 1) % 2;
	}
};

int main() {
	Integer n(30);
	cout << n.get() << ' ';	// get() return 30
	n.set(50);
	cout << n.get() << ' ';	// get() return 50

	Integer m("300");		// string type(stoi필요)
	cout << m.get() << ' ';	// get() return 300
	cout << m.isEven();		// return 0 or 1
}