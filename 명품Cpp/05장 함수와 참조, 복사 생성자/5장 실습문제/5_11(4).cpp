/* 11. (4) ��Ʈ�� Ŭ������ ����ϱ�
* Book Ŭ���� : å�� �̸��� ���� ���� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price) { this->set(title, price); }	// (1) ������ �ۼ�
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
};

void Book::set(string title, int price) {		// (1) ������, �Ҹ���, set�Լ� �ۼ�
	this->title = title;
	this->price = price;				// ����
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000); 
	cpp.show();
	java.show();
	return 0;
}