#include <iostream>
#include <string>
using namespace std;

class Date {
	int year, month, day;
public:
	// ������: 1. ���ڷ� �� ���缭 ���� 2. ���ڿ��� �����ؼ� ����
	Date(int year, int month, int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Date(string date);

	// (inline) ��������� �ܼ�����Լ�
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

	// (inline) ��Ŀ� �°� �ܼ�������ִ� �Լ�
	void show() {
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
};

Date::Date(string n) {
	year = stoi(n.substr(0, 4));			// year ����: ���� 4���� (INDEX:0~3)
	int start = 5;									// month ����: (INDEX 4���� /�� �ִ�)
	int finder = n.find('/', start);				// month�� 2���� Ȥ�� 1�����̱⶧���� finder���� 6�̳� 7�� �ִ�.
	month = stoi(n.substr(start, finder-start ));	// month�� start�κ��� 2 or 1���ڸ� �����Ͽ� int������ ��ȯ�� ���̴�.
	start = finder + 1;							// day ����: 7 or 8 ~
	finder = n.find('\0', start);				// �� ���� �ձ����� day
	day = stoi(n.substr(start, finder-start));	// day�� start�κ��� 2 or 1���ڸ� �����Ͽ� int������ ��ȯ�� ���̴�.
}

int main(void) {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	return 0;
}