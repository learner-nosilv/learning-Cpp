#include <iostream>
#include <string>
using namespace std;

class Date {
	int year, month, day;
public:
	// 생성자: 1. 숫자로 딱 맞춰서 기입 2. 문자열로 나열해서 기입
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Date(string date);

	// (inline) 멤버변수값 단순출력함수
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

	// (inline) 양식에 맞게 콘솔출력해주는 함수
	void show() {
		cout << year << "년" << month << "월" << day << "일" << endl;
	}
};

Date::Date(string n) {
	year = stoi(n.substr(0, 4));			// year 추출: 앞의 4글자 (INDEX:0~3)
	int start = 5;									// month 추출: (INDEX 4에는 /가 있다)
	int finder = n.find('/', start);				// month가 2글자 혹은 1글자이기때문에 finder에는 6이나 7이 있다.
	month = stoi(n.substr(start, finder-start ));	// month는 start로부터 2 or 1글자만 추출하여 int형으로 변환한 값이다.
	start = finder + 1;							// day 추출: 7 or 8 ~
	finder = n.find('\0', start);				// 널 문자 앞까지가 day
	day = stoi(n.substr(start, finder-start));	// day는 start로부터 2 or 1글자만 추출하여 int형으로 변환한 값이다.
}

int main(void) {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	return 0;
}