/* 1-4. Book class�� ���� ���� ����
* ����1(1), 2(1), 3, 4
	+=, -=, ==, !, < ������ �Լ��� �ظ��ϸ� Ŭ�������/�Ұ��ϸ� �ܺ��Լ��� �����ϱ�
* ����1(2), 2(2)
	+=, -=, == �������� �Լ��� �ܺ��Լ��� �����ϱ�
*/
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	// ����1(1) +=, -= ������ �Լ��� Book Ŭ������ ����Լ��� ����
	Book& operator+=(int price) {
		this->price += price;
		return(*this);
	}
	Book& operator-=(int price) {
		this->price -= price;
		return(*this);
	}

	// ����2(1) == ������ �Լ� 3���� ���� Book Ŭ���� �ۼ�
	bool operator==(string title) { return this->title == title; }
	bool operator==(int price) { return this->price == price; }
	bool operator==(Book book) {
		return (this->title == book.title)
			&& (this->price == book.price)
			&& (this->pages == book.pages);
	}

	// ����3 ��¥å���� �Ǻ��ϴ� !�������Լ� �ۼ�
	bool operator!() { return this->price == 0; }

	// ����4 å ������ ���� ������ ���ϴ� <�������Լ� �ۼ� (ù��° �Ű������� stringŸ���̹Ƿ� ���������� �ۼ�)
	friend bool operator<(string title, Book book);
	
};

bool operator<(string title, Book book) { return title < book.title; }

int main() {
	cout << "-------����1(1)����-------" << endl;
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;	// price ����
	b == 500;	// price ����
	a.show();
	b.show();
	cout << endl;

	cout << "-------����2(1)����-------" << endl;
	Book c("��ǰ C++", 30000, 500), d("��ǰ C++", 30000, 500);
	if (c == 30000) cout << "���� 30000��" << endl;			// price ��
	if (c == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl;	// title ��
	if (c == d) cout << "�� å�� ���� å�Դϴ�." << endl;	// title, price, pages ��� ��
	cout << endl;

	cout << "-------����3����-------" << endl;
	Book book("�������", 0, 50);
	if (!book) cout << "��¥��" << endl;
	cout << endl;

	cout << "-------����4����-------" << endl;
	string e;
	cout << "å �̸��� �Է��ϼ���>>";
	getline(cin, e);	// string�Է�
	if (e < a)
		cout << a.getTitle() << "�� " << e << "���� �ڿ� �ֱ���!" << endl;
	cout << endl;

	return 0;
}