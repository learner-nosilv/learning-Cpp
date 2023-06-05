/*
 -
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {	// Inline Constructor(Default Parameter) : ��ü�� ��� ������� �ʱ�ȭ
		this->title = title; this->price = price; 	this->pages = pages;
	}
	void show() {	// ��ü�� ��� �������value �ܼ����
		cout << title << ' ' << price << " Won " << pages << " Pages" << endl;
	}
	string getTitle() { return title; }		// ������� title�� value return
	Book& operator +=(int price);		//P5.1(1) �տ��� �� �Ҵ��ϴ� += operator overloading
	Book& operator -=(int price);		//P5.1(1) ������ �� �Ҵ��ϴ� -= operator overloading
	bool operator ==(string title) {	//P5.2(1) ���� ������ ���ϴ� == operator overloading : �� ��ü�� ������� title�� �Է°��� ������ �� (������ true����) [inline]
		return (this->title == title);
	}
	bool operator ==(int price) {		//P5.2(1) == : �� ��ü�� ������� price�� �Է°��� ������ �� (������ true����) [inline] & operator== function overloading
		return (this->price == price);
	}
	bool operator ==(Book book) {		//P5.2(1) == : �� ��ü�� �Է¹��� ��ü�� ����������� ���� ������ �� (������ true����) [inline] & operator== function overloading
		return (this->title == book.title) && (this->price == book.price) && (this->pages == book.pages);
	}
	bool operator !(){					//P5.3    ��NOT ! operator overloading : �� ��ü�� ������� price�� 0���� �� (0�̸� true����) [inline]
		return this->price == 0;
	}
	friend bool operator <(string title, Book book);	//P5.4    ũ��� < operator overloading : ù��° �Ķ���Ͱ� Book ��ü�� �ƴϹǷ� �����Լ��� ���� �� friend ����
};

Book& Book::operator +=(int price) {			//�� ��ü�� ������� price�� �Է°���ŭ ������Ŵ & ��ü�ڽ� ��������
	this->price += price;
	return *this;
}
a += b;		// �ڵ�
a. += (b);	// �����Ϸ� �ν�
a.func(b);	// ����


Book& Book::operator -=(int price) {			//�� ��ü�� ������� price�� �Է°���ŭ ���ҽ�Ŵ & ��ü�ڽ� ��������
	this->price -= price;
	return *this;
}

bool operator <(string title, Book book) {		// ��������: ù��° �Ķ������ ���ڿ��� �ι�° �Ķ������ ��ü�� title �� (���ڿ��� ���������� ���̸� true����)
	return title < book.title;
}

int main() {
	Book a("YOUTH", 20000, 300), b("FUTURE", 30000, 500);
	a += 500; // Increase the price of the book a by 500 Won
	b -= 500; // Decrease the price of the book b by 500 Won
	a.show();
	b.show();
	cout << "---P7.1(1)----------------------------------------------" << endl;

	Book mp("Masterpiece C++", 30000, 500), hq("High Quality C++", 30000, 500);
	if (mp == 30000) cout << "Price is 30000 Won" << endl;	// price comparison
	if (mp == "Masterpiece C++") cout << "This book is the Masterpiece C++." << endl; 	// Comparison of book title
	if (mp == hq) cout << "These are some books." << endl; 				// Comparison of title, price & pages 
	cout << "---P7.2(1)----------------------------------------------" << endl;

	Book book("Flee Market", 0, 50); // Price is 0.
	if (!book) cout << "It is free." << endl;
	cout << "---P7.3-------------------------------------------------" << endl;

	string c;
	cout << "Please enter the title of book >> ";
	getline(cin, c); // Get the title of book from keyboard
	if (c < a)
		cout << a.getTitle() << " is after " << c << "!" << endl;
	cout << "---P7.4-------------------------------------------------" << endl;
}
