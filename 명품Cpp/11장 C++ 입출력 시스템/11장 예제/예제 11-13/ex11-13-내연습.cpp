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
	outs << "���󿡼� ���� ���� ����� \"" << name << "\" �Դϴ�.";
	return outs;
}

istream& question(istream& ins) {
	cout << "�ſ�� �ſ�� ���� ���� ���ڴ�?";	// �����ϰ�
	return ins;								// ���� ins�� ����
}

int main() {
	cout << "���� �︳�ϴ�" << beep << endl;
	cout << "C" << rightarraw << "C++" << rightarraw << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;

	string user;
	cin >> question >> user;
	answer(cout, user) << endl;				// �̰� �ǳ�
	return 0;
}