/*
* & Ű�� �ԷµǱ� ������ ���� ���� ���� ���ڿ� �Է¹ޱ� : getline(cin, s, '&');
* ã�� ���ڿ��� ��ġ�� ���ڿ��� ���� �Է¹޾Ƽ� ���ڿ��� �����϶�
* ���ڿ� ã��: ��Ʈ����ü.find(���ڿ�) -> return ���ڿ� ������ġ or -1
* ���ڿ� ��ġ: ��Ʈ����ü.	replace(�����ε���, n����, ���ڿ�)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string essay;
	cout << "���� ���� ���ڿ��� �Է��ϼ���. �Է��� ���� &�����Դϴ�." << endl;
	getline(cin, essay, '&');
	cin.ignore();				// ���ۿ� ����ִ� & ������ ���ڴ� ������� �� ����

	string f, r;
	cout << "find: ";
	getline(cin, f, '\n');
	cout << "replace: ";
	getline(cin, r, '\n');

	int fsize = (int)f.size();	// ���߿� ��ü�� �� �ʿ���(replace)
	int rsize = (int)r.size();	// startIndex�� ������ų �� �ʿ���
	
	int startIndex = 0;		// �˻���ġ
	while (true) {
		startIndex = (int)essay.find(f, startIndex);	// startIndex���� ���ڿ�f ã��
		if (startIndex == -1)	// ���ٸ�, ��ġ ����
			break;
		else {
			essay.replace(startIndex, fsize, r);
			startIndex += rsize;
		}
			
	}

	cout << "������: " << endl;
	cout << essay << endl;

	return 0;
}