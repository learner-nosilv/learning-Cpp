#include <iostream>
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

int main() {
	cout << "���� �︳�ϴ�" << beep << endl;
	cout << "C" << rightarraw << "C++" << rightarraw << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
	return 0;
}