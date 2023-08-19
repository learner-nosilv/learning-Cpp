/* CPU명령어 시뮬레이션 & HW예외 만들기
* 명령어처리과정: fetch decode execute
* 명령어: ADD SUB MUL DIV
* 피연산자: 정수
* 예외
	fetch 예외: 명령어가 없음
	decode 예외: 없는 명령어 입력, 정수형태가 아닌 형태의 피연산자 입력, 피연산자가 하나 혹은 없는 입력
	execute 예외: 0으로 나누는 경우 
*/
#include <iostream>
#include <string>
using namespace std;

class HardwareException {
	string step;	// 명령어 처리단계 중 에러가 발생한 단계
	string msg;		// 에러메세지
public:
	HardwareException(string step, string msg) { this->step = step; this->msg = msg; }	// 생성자
	void print() { cout << step << " 스텝, " << msg << endl; }
};

class CPU {
	string instruction;	// 사용자가 입력한 명령
	string command;		// 명령어
	int a, b;			// 피연산자
	void fetch() throw(HardwareException);			// 사용자의 명령을 읽어오기 : 예외처리(명령이 없는 경우)
	void decode() throw(HardwareException);			// 사용자의 명령을 분석하기 : 예외처리(없는 명령어를 입력한 경우, 피연산자가 하나 또는 없는 경우, 피연산자가 정수가 아닌 경우)
	void execute() throw(HardwareException);		// 사용자의 명령을 실행하기 : 예외처리(0으로 나누는 경우)
public:
	void run();
	static int stringToInt(string x) throw(string);
};

void CPU::run() {
	while (true) {
		try {
			fetch();
			decode();
			execute();
		}
		catch (HardwareException a) {
			a.print();		// 예외 정보출력
			return;			// 종료
		}
	}
}
// 문자열->정수변환
int CPU::stringToInt(string x) {
	int size = x.size();		// 자릿수
	int result = 0;				// 변환결과
	for (int i = 0; i < size; i++) {					// 루프 : 모든 자릿수 탐색
		if (x[i] >= '0' && x[i] <= '9') {				// 해당 자릿수가 숫자인 경우
			result = (result * 10) + (int)(x[i] - '0');	// 문자열->정수변환
		}
		else											// 해당 자릿수가 숫자가 아닌 경우
			throw x;									// 예외처리
	}
	return result;
}

void CPU::fetch() {
	getline(cin, this->instruction, '\n');				// 사용자의 명령 한 줄 읽어오기
	if (instruction == "") throw HardwareException("fetch", "명령 라인 없음");
}

void CPU::decode() {
	int instIdx = instruction.find(' ');				// 사용자 명령을 세 덩어리로 분해: 명령어`|`피연산자1|피연산자2
	int op1Idx = instruction.find(' ', instIdx + 1);	// 사용자 명령을 세 덩어리로 분해: 명령어|피연산자1`|`피연산자2

	if (instIdx == -1) {		// 경우1: 한 덩어리 : 명령어나, 피연산자1만 존재하는 경우: 예외처리 필요
		if (instruction == "ADD" || instruction == "SUB" || instruction == "MUL" || instruction == "DIV")	// 경우1-1: 명령어가 제대로 입력된 경우
			throw HardwareException("decode", "피연산자 예외");
		else																								// 경우1-2:명령어부터 제대로 입력되지 않은 경우
			throw HardwareException("decode", "invalid 명령어 예외");
	}
	// 두 덩어리 or 세 덩어리
	this->command = instruction.substr(0, instIdx);	// 첫 덩어리-> 명령어
	if (this->command != "ADD" && this->command != "SUB" && this->command != "MUL" && this->command != "DIV")
		throw HardwareException("decode", "invalid 명령어 예외");
	// 첫 덩어리가 정상적인 명령어인 상황 & (두 덩어리 or 세 덩어리)
	if (op1Idx == -1)			// 경우2: 두 덩어리 : 명령어 + 피연산자1만 존재하는 경우: 예외처리 필요
		throw HardwareException("decode", "피연산자 예외");
	// 첫 덩어리가 정상적인 명령어인 상황 & 세 덩어리
	string op1 = this->instruction.substr(instIdx + 1, (op1Idx - instIdx - 1));
	string op2 = this->instruction.substr(op1Idx + 1);
	try {														// 피연산자를 string->int 형으로 변환
		this->a = stringToInt(op1);
		this->b = stringToInt(op2);
	}
	catch (string op) {
		throw HardwareException("decode", "피연산자 타입 예외");	// int로 변환불가한 경우
	}
	// 명령어 | 피연산자1 | 피연산자2 로 해석완료
}

void CPU::execute() {
	if (this->command == "DIV") {
		if (this->b == 0)
			throw HardwareException("execute", "0으로 나누는 예외");
		else
			cout << '\t' << this->instruction << ":\t" << (this->a / this->b) << endl;
	}
	cout << '\t' << this->instruction << ":\t";
	if (this->command == "ADD")
		cout << (this->a + this->b) << endl;
	else if (this->command == "SUB")
		cout << (this->a - this->b) << endl;
	else if (this->command == "MUL")
		cout << (this->a * this->b) << endl;
}

int main() {
	CPU myCpu;
	myCpu.run();

	return 0;
}