/* 11.
* Book Ŭ���� : å�� �̸��� ���� ���� 
* 
* ***�ʹ��ϳפФ�***
*	main()�� java.set("��ǰ�ڹ�", 12000); �� �ִ�.
* 
*	å�� void set(char* title, ...)�� �Ǿ��־, ������ ������ ����.
*	���� void set(const char* title, ...)�� ���ٽ�½ �ٲ������. ����33
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price) { this->set(title, price); }	// (1) ������ �ۼ�70
//	Book(const Book& book) {			// (2) �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�8
//		this->title = book.title;		// ������ �����Ҵ���� this->title�� ���� ������鼭 �޸� �����߻� & ���� title ������ ����Ŵ = �� ��ü�� �Ҹ��ڰ� �ߺ�����Ǹ� ��Ÿ�ӿ����߻�
//		this->price = book.price;
//	}
	Book(const Book& book);			// (3) ���� ���簡 ������ ����� ���� ���� ������ �ڵ�
	~Book() { delete[] title; }							// (1) ������, �Ҹ���, set�Լ� �ۼ�
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }
};

Book::Book(const Book& book) {			// (3) ���� ���簡 ������ ����� ���� ���� ������ �ڵ�
	int len = strlen(book.title);			// �Է¹��� ���ڿ��� ũ��
	this->title = new char[len + 1];		// NULL���ڱ��� �����ؼ�, title�� �����Ҵ�ޱ�
	strcpy(this->title, book.title);		// ���ڵ� �����ϱ�
	this->price = book.price;				// ����
}

void Book::set(const char* title, int price) {		// (1) ������, �Ҹ���, set�Լ� �ۼ�
	if (this->title)								// �̹� �����ϴ� �����Ҵ��� �ִٸ� ����
		delete[] this->title;						

	int len = strlen(title);			// �Է¹��� ���ڿ��� ���ڰ���
	this->title = new char[len + 1];	// �Է¹��� title + \0 ��ŭ �����Ҵ�ޱ�
	strcpy(this->title, title);			// ���ڿ� ���� ����
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