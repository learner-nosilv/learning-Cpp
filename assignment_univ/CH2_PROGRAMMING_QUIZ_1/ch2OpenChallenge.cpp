#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cout << "���� ���� �� ������ �մϴ�. ����, ����, �� �߿��� �Է��ϼ���." << endl;

	// 1. �ι̿��� �ٸ����� ���� �Է¹޴´�.
	string s, t;
	cout << "�ι̿�>>";
	cin >> s;
	cout << "�ٸ���>>";
	cin >> t;

	// 2. ���� �̱�� ������ �Ǵ��ϰ� ����Ѵ�.
	if (s == t)
		cout << "�����ϴ�" << endl;
	else if ((s == "����" && t == "��") || (s == "����" && t == "����") || (s == "��" && t == "����"))
		cout <<"�ι̿��� �̰���ϴ�." << endl;
	else
		cout << "�ٸ����� �̰���ϴ�." << endl;

	return 0;
}
