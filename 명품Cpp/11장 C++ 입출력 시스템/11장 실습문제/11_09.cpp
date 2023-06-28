/* 9. Phone Ŭ������ ��ü�� ������ϴ� <<, >> ������ �ۼ��ϱ�*/
#include <iostream>
using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend ostream& operator << (ostream& outs, Phone a);
	friend istream& operator >> (istream& ins, Phone& a);
};

ostream& operator << (ostream& outs, Phone a) {
	outs << '(' << a.name << ',' << a.telnum << ',' << a.address << ')';
	return outs;
}

istream& operator >> (istream& ins, Phone& a) {
	cout << "�̸�:";
	cin >> a.name;
	cout << "��ȭ��ȣ:";
	cin >> a.telnum;
	cout << "�ּ�:";
	cin >> a.address;
	return ins;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
	return 0;
}