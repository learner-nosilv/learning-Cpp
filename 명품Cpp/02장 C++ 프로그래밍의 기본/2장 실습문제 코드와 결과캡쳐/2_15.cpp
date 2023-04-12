/*
* ����+, ����- ����* ������/ ������% ���� 5Ģ���� ����
* �䱸����1. �� ���� ���� ������ ���� �Է¹ޱ�
* �䱸����2. ���鹮�ڷ� �Է��� �����ϱ�: �Է½�Ʈ�����۴� �����̳� ����, �� ������ �Է°��� ó���Ѵ�
* �䱸����2. atoi(Ascii TO Integer)
* 
* 1. ũ�Ⱑ 4�� char�� �迭�� ���ڰ��� ����, ������, ���ڰ��� ���ڸ� �Է¹ް� ó��
	(���ڸ� ���ڷ� ����ؼ� ����ؾ��� �� atoi(), <cstdlib> �̿�?)
* 2. ����ó��: �Է¹��ۿ����� �� �� ������ ���, �������� �˸��� �ݺ��� continue
* 3. switch���� �̿��Ͽ� �ùٸ� ��������� �ٷ� �б�

* �ݺ����� ����ؼ� ��� ���

* ���:
* �ƹ��� �����ص�, int, char, int�� �޴°� ������ ��......
*/

#include <iostream>
using namespace std;

bool isError() {	// �Է½�Ʈ������ ����ó��
	if (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		return true;
	}
	else
		return false;
}

int main() {
	int a, b;	// ����
	char oper;	// ������

	// ���� �۵�����
	while (1) {
		// 1. �� ���� �Է¹ޱ�
		cout << "? ";
		//  (�Է½�Ʈ�����۴� �����̳� ����, �� ������ �Է°��� ó���Ѵ�.)
		cin >> a;
		cin >> oper;
		cin >> b;

		// 2. �Է¹��ۿ���ó��
		if (isError()) {
			cout << "!ERROR!" << endl;	// �������� �˸���
			return 0;					// ���� �۵�����
		}

		// 3. �����Է��� ���
		int result = 0;
		switch (oper) {
			case '+':
				result = a + b;
				break;
			case '*':
				result = a * b;
				break;
			case '-':
				result = a - b;
				break;
			case '/':
				result = a / b;
				break;
			case '%':
				result = a % b;
				break;
			default:
				cout << "!ERROR!" << endl;	// �������� �˸���
				return 0;					// ���� �۵�����
		}
		// 4. ��� ���
		cout << a << " " << oper << " " << b << " = " << result << endl;
	}
	return 0;
}

/* ����� ����
// x�� �Է¹ޱ� ������ ���� �����۵�
while (1) {
	char expression[3][4];	// ũ�Ⱑ 4�� ���ڿ��� 3��(������ ����, �����ȣ, ������ ����) �غ�

	// 1. �� �Է¹ޱ�
	cout << "? ";
	for (int i = 0; i < 3 && expression[3][0] != 'x'; i++) {	// �����Է��� �ޱ� �� ����
		cin >> expression[i];
	}

	// 2. �Է°� ó�� �� ���
	//	��Ȳ1. �Է¿���ó��
	if (isError) {					// �Է¹��� state�� �������
		cout << "!ERROR!" << endl;	// �������� �˸���
		expression[0][0] = '\0';	// �Է°��� ����� expression�� �ʱ�ȭ�ϰ�
		continue;					// �ٽ� ������ ó������ ���ư���
	}
	//	��Ȳ2. �������� ���� ���, ���� ����
	else if (expression[3][0] == 'x') {
		cout << "����� �����մϴ�" << endl;
		return 0;
	}

	// ��Ȳ3. �����Է��� ��� switch���� ���� �ùٸ� ��������� �б�
	switch (expression[1]) {
		case'+':
			int result = atoi(expression[0]) * atoi(expression[2]);
	}
	*/