/* ��������3. 0~9������ ������ Ű���忡�� �Է¹޾� �����ϴ� get() �Լ� 
	����: 0-9������ ���� �Է����� ���� ���
	main()�� while(true)
*/
#include <iostream>
using namespace std;

int get() throw(const char*) {
	int a;
	cout << "0~9 ������ ���� �Է� >> ";
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(99, '\n');
		throw "input(char) fault";
	}
	if (a < 0 || a > 9) throw "input(out of range) fault";
	return a;
}

int main() {
	int a, b;
	while (true) {
		try {
			a = get();
			b = get();
			cout << a << 'x' << b << '=' << a * b << endl;
		}
		catch (const char* msg) {
			cout << msg << ", ����� �� ����" << endl;
		}
	}
	return 0;
}