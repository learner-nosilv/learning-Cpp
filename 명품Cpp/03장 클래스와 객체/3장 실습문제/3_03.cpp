/*
* 구상:
* 클래스: 은행계좌
* 멤버변수: string계좌주명 int계좌번호 int잔액
* 멤버함수: 생성자(멤변전부입력) 멤버변수리턴(계좌주명, 잔액) 저금 출금
* 
* 의문: getBalance하면 되는 걸 왜 inquiry로 할까(하라는 대로 하겠지만)
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

	// 입금
	void deposit(int money) {
		balance += money;
	}
	// 출금
	int withdraw(int money);
};

int Account::withdraw(int money) {
	if (balance >= money) {
		balance -= money;
		return money;
	}
		
	else
		cout << "!!잔액부족!!" << endl;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);			// 저금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// 잔액부족이 아니라면 20000원 출금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;

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
	if (money > balance) { // 저축된 돈이 찾는 금액보자 작은 경우
		money = balance;
		balance = 0;
	}
	else
		balance -= money;

	return money; // 실제 찾은 금액 리턴
}

int Account::inquiry() {
	return balance;
}

int main() {
	Account a("kitae", 1, 5000); 	// id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000);				// 20000원 저금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);	// 20000원 출금. withdraw()는 출금한 실제 금액 리턴
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}
*/