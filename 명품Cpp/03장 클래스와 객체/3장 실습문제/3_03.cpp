/*
* ����:
* Ŭ����: �������
* �������: string�����ָ� int���¹�ȣ int�ܾ�
* ����Լ�: ������(�⺯�����Է�) �����������(�����ָ�, �ܾ�) ���� ���
* 
* �ǹ�: getBalance�ϸ� �Ǵ� �� �� inquiry�� �ұ�(�϶�� ��� �ϰ�����)
*/

#include <iostream>
#include <string>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string name, int id, int balance) {
		this->name = name;
		this->id = id;
		this->balance = balance;
	}

	string getOwner() { return name; }
	int inquiry() { return balance; }

	// �Ա�
	void deposit(int money) {
		balance += money;
	}
	// ���
	int withdraw(int money);
};

int Account::withdraw(int money) {
	if (balance >= money) {
		balance -= money;
		return money;
	}
		
	else
		cout << "!!�ܾ׺���!!" << endl;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);			// ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// �ܾ׺����� �ƴ϶�� 20000�� ���
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;

	return 0;
}

// [BOOK SOLUTION]------------------------------------------------
/*
#include <iostream>
#include <string>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string n, int i, int bal);
	void deposit(int money);
	int withdraw(int money);
	int inquiry();
	string getOwner() { return name; }
};

Account::Account(string n, int i, int bal) {
	name = n;
	id = i;
	balance = bal;
}

void Account::deposit(int money) {
	balance += money;
}

int Account::withdraw(int money) {
	if (money > balance) { // ����� ���� ã�� �ݾ׺��� ���� ���
		money = balance;
		balance = 0;
	}
	else
		balance -= money;

	return money; // ���� ã�� �ݾ� ����
}

int Account::inquiry() {
	return balance;
}

int main() {
	Account a("kitae", 1, 5000); 	// id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000);				// 20000�� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// 20000�� ���. withdraw()�� ����� ���� �ݾ� ����
	cout << a.getOwner() << "�� �ܾ��� " << a.inquiry() << endl;
}
*/