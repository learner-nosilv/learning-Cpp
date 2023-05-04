/* 9.
* �Խ��� Ŭ����
*  �Խ��� ����: static
* main() �Լ��� �������� �����Ͽ� Board Ŭ��������� ���α׷� �ϼ��ϱ�
*/

#include <iostream>
#include <string>
using namespace std;

class Board {
	static string content[10];		// 10���� ������ ���� �� �ִ� �Խ���
	static int empty;
public:
	void static add(string content);
	void static print();
};

// static��� Definition
string Board::content[10];
int Board::empty = 0;
void Board::add(string content) {
	if (empty < 10) {
		Board::content[Board::empty] = content;
		Board::empty++;
	}
	else
		cout << "!�Խ��� ��������!" << endl;
}

void Board::print() {
	for (int star = 0; star < 13; star++) cout << '*';
	cout << " �Խ����Դϴ�. ";
	for (int star = 0; star < 13; star++) cout << '*';
	cout << endl;

	for (int i = 0; i < empty; i++)
		cout << i << ": " << Board::content[i] << endl;
	cout << endl;
}

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();

	return 0;
}