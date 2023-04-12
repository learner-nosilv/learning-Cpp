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
	if (!strcmp(s, t))
		cout << "�����ϴ�" << endl;
	else if ((s == "����" && t == "��") || (s == "����" && t == "����") || (s == "��" && t == "����"))
		cout <<"�ι̿��� �̰���ϴ�." << endl;
	else
		cout << "�ٸ����� �̰���ϴ�." << endl;

	return 0;
}

/* Solution
// ch2OpenChallenge

#include <iostream>
using namespace std;

int main() {
	cout << "���� ���� �� ������ �մϴ�. ����, ����, �� �߿��� �Է��ϼ���." << endl;

	// �Է� �ޱ�
	char s[10];
	cout << "�ι̿�>>";
	cin >> s;

	char t[10];
	cout << "�ٸ���>>";
	cin >> t;

	// Ʋ�� �Է� ��󳻱�
	if(strcmp(s, "����") != 0 && strcmp(s, "����") != 0 && strcmp(s, "��") != 0) {
		cout << "�ι̿��� �Է��� Ʋ�Ƚ��ϴ�." << endl;
		return 0;
	}
	if(strcmp(t, "����") != 0 && strcmp(t, "����") != 0 && strcmp(t, "��") != 0) {
		cout << "�ٸ����� �Է��� Ʋ�Ƚ��ϴ�." << endl;
			return 0;
	}

	// ���� ����
	if(strcmp(s, "����") == 0 && strcmp(t, "��") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "��") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else if(strcmp(s, "��") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "��") == 0 && strcmp(t, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else
		cout << "�����ϴ�." << endl;
}
*/