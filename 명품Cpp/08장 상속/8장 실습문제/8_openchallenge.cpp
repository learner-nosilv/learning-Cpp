/* 411p OpenChallenge
* ����1: main()���� �� ������ �ٸ� Ŭ���� ��ü���� ��� �ѹ��� ��������?
*	product������ �迭�� �ϸ� ��ĳ������ �ǰ����� ��� �������� �Ұ�����
* 
* ����2: switch �� switch �� ���۵� -> �ذ�
* https://stackoverflow.com/questions/42297348/transfer-of-control-bypasses-initialization-of
* 
* ����3: ���๮�ڸ� �Է¹��ۿ� ���ܵδ� cin -> ���๮��(delimiter)������ �ް� delimiter�������� �Ҵ��ϴ� getline
* https://namwhis.tistory.com/entry/cin%EA%B3%BC-getline%EC%9D%84-%EA%B0%99%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-cinignore%EC%9D%B4-%ED%95%84%EC%9A%94%ED%95%9C-%EC%9D%B4%EC%9C%A0-%EA%B8%B0%EB%A1%9D
* cin.ignore �Լ��� ������ istream& ignore (streamsize n = 1, int delim = EOF); �̴�.
n�� ����ŭ�� ���ڸ� �о���� �� ������ �ǰ� �Ǵ� delim�� �ش��ϴ� ���ڸ� ������ �ش� ���ڱ����� �о���� �� ������ �ȴ�.(�� �߿� ���� �����ϴ� ������ ������ �ȴ�.)
https://dntworry-behappy.tistory.com/2

* ����4:
* ������ ���� ���� ȸȭ�� �Է��� ��
Conversation Book�� �Է����°� Book�� �Է����¶� ���׹��׵Ǿ��ִ�.
setProduct, setBook �̷� �� ������� ���� �� ����.
����?
*/
#include <iostream>
#include <string>
using namespace std;

// ���ڰ� �ƴ� ���ڿ� �Է½� �߻��ϴ� �Է¿��� ó��
bool isError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(999, '\n');
		return true;
	}
	else return false;
}

class Product {
	static int productTotal;	// �� ��ǰ ����
	int kind;					// ��ǰ���� 0Product 1Book 2CD 3ConversationBook
	int id;						// �ĺ���
	string description;			// ����
	string madeIn;				// ������
	int price;					// ����
public:
	Product(int kind = 0) {
		this->kind = kind;
		this->id = productTotal;	// �ĺ��� �ڵ�����
		productTotal++;
	}
	void setProduct() {
		cout << "��ǰ���� : ";
		getline(cin, this->description,'\n');
		cout << "������ : ";
		getline(cin, this->madeIn,'\n');
		do {
			cout << "���� : ";
			cin >> this->price;
			cin.ignore(1, '\n');		// �Է¹��ۿ� �����ִ� ���๮�� ����
		} while (isError());
	}
	void showProduct() {
		cout << "--- ��ǰID : " << this->id << '\n'
			<< "��ǰ���� : " << this->description << '\n'
			<< "������ : " << this->madeIn << '\n'
			<< "���� : " << this->price << endl;
	}
	int whatKind() { return kind; }
};
int Product::productTotal = 0;	// �� ��ǰ ����

class Book : public Product {
	int isbn;				// ISBN��ȣ
	string title;			// ����
	string author;			// ����
public:
	Book(int kind = 1) : Product(kind) { }
	void setBook() {
		setProduct();
		do {
			cout << "ISBN : ";
			cin >> isbn;
			cin.ignore(1, '\n');		// �Է¹��ۿ� �����ִ� ���๮�� ����
		} while (isError());
		cout << "å���� : ";
		getline(cin, title);
		cout << "���� : ";
		getline(cin, author);
	}
	void showBook() {
		showProduct();
		cout << "ISBN : " << isbn << '\n'
			<< "å���� : " << title << '\n'
			<< "���� : " << author << endl;
	}
};

class CompactDisc : public Product {
	string title;			// ����
	string artist;			// ����
public:
	CompactDisc(int kind = 2) : Product(kind) { }
	void setCD() {
		setProduct();
		cout << "�ٹ����� : ";
		getline(cin, title);
		cout << "���� : ";
		getline(cin, artist);
	}
	void showCD() {
		showProduct();
		cout << "�ٹ����� : " << title << '\n'
			<< "���� : " << artist << endl;
	}
};

class ConversationBook : public Book {
	string language;	// ���
public:
	ConversationBook(int kind = 3) :Book(kind) { }
	void setCB() {
		setBook();
		cout << "��� : ";
		getline(cin, language);
	}
	void showCB() {
		showBook();
		cout << "��� : " << language << endl;
	}
};

int main() {
	int total = 0;				// 0:total, 1:book, 2:cd, 3:conversation book
	Product* management[100];
	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
	int menu = 0;					// �����޴�
	while(menu!=3 && total<100) {				// ����Ż������: 3 (������)
		do {
			cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? ";
			cin >> menu;
			cin.ignore(1,'\n');		// �Է¹��ۿ� �����ִ� ���๮�� ����
		} while (isError());
		
		switch (menu) {		// ��ǰ�����޴�
			case 1: {		// ��ǰ�����޴� [1. ��ǰ�߰�]
				int kind;				//	��ǰ ���� �Է¹޾Ƽ�, ��ǰ ������ �´� ��ü �����ϱ�
				do {
					cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ? ";
					cin >> kind;
					cin.ignore(1, '\n');		// �Է¹��ۿ� �����ִ� ���๮�� ����
				} while (isError() && (kind == 1 || kind == 2 || kind == 3));

				switch (kind) {			//	��ǰ ���� �Է¹޾Ƽ�, ��ǰ ������ �´� ��ü �����ϱ�
					case 1: {			//	1. Book
						management[total] = new Book;						// upcasting
						((Book*)management[total])->setBook();
						total++;
						break;
					}
					case 2: {			//	2. CD
						management[total] = new CompactDisc;				// upcasting
						((CompactDisc*)management[total])->setCD();
						total++;
						break;
					}
					case 3: {			//	3. Conversation Book
						management[total] = new ConversationBook;			// upcasting
						((ConversationBook*)management[total])->setCB();
						total++;
						break;
					}
				}
				break;					//	��ǰ ���� �Է¹ޱ� break
			}
			case 2: {		// ��ǰ�����޴� [2. ����ǰ��ȸ]
				for (int i = 0; i < total; i++) {
					switch (management[i]->whatKind()) {	// ��ǰ���� 0Product 1Book 2CD 3ConversationBook
						case 1: {		// Book
							((Book*)management[i])->showBook();				// Downcasting
							break;
						}

						case 2: {		// CD
							((CompactDisc*)management[i])->showCD();		// Downcasting
							break;
						}

						case 3: {		// Conversation Book
							((ConversationBook*)management[i])->showCB();	// Downcasting
							break;
						}
					}
				}
				break;					//	2. ����ǰ��ȸ break
			}
		}	// ��ǰ�����޴� Switch
	}	// ��ǰ���� Loop Ż��

	for (int i = 0; i < total; i++)		// delete[] management; �� ����
		delete management[i];

	return 0;
}