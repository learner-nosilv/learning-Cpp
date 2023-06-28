#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

ostream& fivestar(ostream& outs) {
	return outs << "*****";
}

ostream& rightarraw(ostream& outs) {
	return outs << "---->";
}

ostream& beep(ostream& outs) {
	return outs << '\a';
}

ostream& answer(ostream& outs, string name) {
	outs << "세상에서 제일 예쁜 사람은 \"" << name << "\" 입니다.";
	return outs;
}

istream& question(istream& ins) {
	cout << "거울아 거울아 누가 제일 예쁘니?";	// 질문하고
	return ins;								// 답을 ins에 받음
}

int main() {
	cout << "벨이 울립니다" << beep << endl;
	cout << "C" << rightarraw << "C++" << rightarraw << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;

	string user;
	cin >> question >> user;
	answer(cout, user) << endl;				// 이게 되네
	return 0;
}