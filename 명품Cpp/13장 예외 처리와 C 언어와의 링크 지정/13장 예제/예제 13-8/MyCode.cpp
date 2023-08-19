/* 예제 13-8		예외 클래스 만들기 */
#include <iostream>
#include <string>
using namespace std;

// 예외정보들을 추상화한 클래스
class MyException {
	int lineNo;			// 예외를 throw 한 코드 위치
	string func, msg;	// 예외가 발생한 함수명, 예외메세지
public:
	MyException(int n, string f, string m) { this->lineNo = n; this->func = f; this->msg = m; } // 생성자
	void print() { cout << func << ':' << lineNo << ", " << msg << endl; }						// 오류정보 콘솔출력
};

// 0으로 나누는 예외정보를 추상화한 클래스 (예외정보클래스 상속)
class DivideByZeroException :public MyException {
public:
	DivideByZeroException(int n, string f, string m) : MyException(n, f, m) {}
};

// 잘못된 입력의 예외정보를 추상화한 클래스 (예외정보클래스 상속)
class InvalidInputException :public MyException {
public:
	InvalidInputException(int n, string f, string m) : MyException(n, f, m) {}
};

int main() {
	int x, y;
	while (true) {
		try {
			cout << "나눗셈을 합니다. 두 수를 입력하세요>>";
			cin >> x >> y;
			if (x < 0 || y < 0) throw InvalidInputException(32, "main()", "음수 입력 예외 발생");	// 예외정보에 관한 임시객체 생성 & throw
			else if (y == 0) throw DivideByZeroException(33, "main()", "0으로 나누는 예외 발생");	// 예외정보에 관한 임시객체 생성 & throw
			cout << (double)x / (double)y << endl;												// 정상입력시 계산값 출력
		}
		catch (InvalidInputException& iie) { iie.print(); }					// 객체의 멤버함수를 사용하기위하여 객체를 참조매개변수로 이용
		catch (DivideByZeroException& dbze) { dbze.print(); }				// 객체의 멤버함수를 사용하기위하여 객체를 참조매개변수로 이용
	}
	return 0;
}