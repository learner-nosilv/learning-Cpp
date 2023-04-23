/* 11.
* Book Ŭ���� : å�� �̸��� ���� ����
*
* ***�ʹ��ϳפФ�***
*	main()�� java.set("��ǰ�ڹ�", 12000); �� �ִ�.
*
*	å�� void set(char* title, ...)�� �Ǿ��־, ������ ������ ����.
*	���� void set(const char* title, ...)�� ���ٽ�½ �ٲ������. ����
*/

#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
//	Book(const Book& book) {			// (2) �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�
//		this->title = book.title;		// ������ �����Ҵ���� this->title�� ���� ������鼭 �޸� �����߻� & ���� title ������ ����Ŵ = �� ��ü�� �Ҹ��ڰ� �ߺ�����Ǹ� ��Ÿ�ӿ����߻�
//		this->price = book.price;
//	}
	Book(const Book& book) {			// (3) ���� ���簡 ������ ����� ���� ���� ������ �ڵ�
		int null_idx;										// �Է¹��� book.title���ڿ��� ũ��-1
		for (null_idx = 0; *((book.title) + null_idx) != '\0'; null_idx++);
		this->title = new char[null_idx + 1];				// �Է¹��� title��ŭ ���ο� �����Ҵ�ޱ�

		for (int i = 0; i <= null_idx; i++)					// �����Ҵ���� title�� �Է¹��� title �����ϱ�
			*((this->title) + i) = *((book.title) + i);

		this->price = book.price;								// ����
	}

	~Book() { delete[] title; }							// (1) ������, �Ҹ���, set�Լ� �ۼ�
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "��" << endl; }

};

Book::Book(const char* title, int price) {				// (1) ������, �Ҹ���, set�Լ� �ۼ�
	int null_idx;										// �Է¹��� title���ڿ��� ũ��-1
	for (null_idx = 0; *(title + null_idx) != '\0'; null_idx++);

	this->title = new char[null_idx + 1];				// �Է¹��� title��ŭ �����Ҵ�ޱ�

	for (int i = 0; i <= null_idx; i++) {				// �����Ҵ���� title�� �Է¹��� title �����ϱ�
		*((this->title) + i) = *(title + i);
	}
	this->price = price;								// ����
}

void Book::set(char* title, int price) {				// (1) ������, �Ҹ���, set�Լ� �ۼ�
	delete[] this->title;								// �����ڿ� ���� �߻��� �����Ҵ� ����

	int null_idx;										// �Է¹��� title���ڿ��� ũ��-1
	for (null_idx = 0; *(title + null_idx) != '\0'; null_idx++);

	this->title = new char[null_idx + 1];				// �Է¹��� title��ŭ �����Ҵ�ޱ�

	for (int i = 0; i <= null_idx; i++) {				// �����Ҵ���� title�� �Է¹��� title �����ϱ�
		*((this->title) + i) = *(title + i);
	}
	this->price = price;								// ����
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	char name[9] = "��ǰ�ڹ�";
	java.set(name, 12000);							// cannot convert argument 1 from 'const char [9] to 'char *'
//	java.set("��ǰ�ڹ�", 12000);						// [����] const char* Ÿ���� �μ��� char* Ÿ���� �Ķ���ͷ� ȣȯ�� �� �����ϴ� 
	cpp.show();
	java.show();
	return 0;
}