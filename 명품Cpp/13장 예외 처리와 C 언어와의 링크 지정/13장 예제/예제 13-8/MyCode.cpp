/* ���� 13-8		���� Ŭ���� ����� */
#include <iostream>
#include <string>
using namespace std;

// ������������ �߻�ȭ�� Ŭ����
class MyException {
	int lineNo;			// ���ܸ� throw �� �ڵ� ��ġ
	string func, msg;	// ���ܰ� �߻��� �Լ���, ���ܸ޼���
public:
	MyException(int n, string f, string m) { this->lineNo = n; this->func = f; this->msg = m; } // ������
	void print() { cout << func << ':' << lineNo << ", " << msg << endl; }						// �������� �ܼ����
};

// 0���� ������ ���������� �߻�ȭ�� Ŭ���� (��������Ŭ���� ���)
class DivideByZeroException :public MyException {
public:
	DivideByZeroException(int n, string f, string m) : MyException(n, f, m) {}
};

// �߸��� �Է��� ���������� �߻�ȭ�� Ŭ���� (��������Ŭ���� ���)
class InvalidInputException :public MyException {
public:
	InvalidInputException(int n, string f, string m) : MyException(n, f, m) {}
};

int main() {
	int x, y;
	while (true) {
		try {
			cout << "�������� �մϴ�. �� ���� �Է��ϼ���>>";
			cin >> x >> y;
			if (x < 0 || y < 0) throw InvalidInputException(32, "main()", "���� �Է� ���� �߻�");	// ���������� ���� �ӽð�ü ���� & throw
			else if (y == 0) throw DivideByZeroException(33, "main()", "0���� ������ ���� �߻�");	// ���������� ���� �ӽð�ü ���� & throw
			cout << (double)x / (double)y << endl;												// �����Է½� ��갪 ���
		}
		catch (InvalidInputException& iie) { iie.print(); }					// ��ü�� ����Լ��� ����ϱ����Ͽ� ��ü�� �����Ű������� �̿�
		catch (DivideByZeroException& dbze) { dbze.print(); }				// ��ü�� ����Լ��� ����ϱ����Ͽ� ��ü�� �����Ű������� �̿�
	}
	return 0;
}