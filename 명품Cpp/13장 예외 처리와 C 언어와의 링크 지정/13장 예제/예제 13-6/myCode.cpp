/* ���� 13-6		���ڿ��� ������ ��ȯ�ϴ� �Լ� �ۼ��ϱ� 
	* ������ ��ȯ�� �� ���� ���ڿ��� ����ó�� */
#include <iostream>
#include <string>
using namespace std;

int stringToInt(const char x[]) {
	int sum = 0;			// ���ڿ��� ��ȯ�� ����
	int len = strlen(x);	// ���ڿ� ����
	for (int i = 0; i < len; i++) {
		if (x[i] < '0' || x[i]>'9')
			throw x;
		else
			sum = (sum * 10) + (x[i] - '0');
	}
	return sum;
}

int main() {
	int n;
	const char* firstLine = "123";
	const char* secondLine = "1A3";

	try {
		n = stringToInt(firstLine);
		cout << '\"' << firstLine << "\" �� ���� " << n << " (��)�� ��ȯ��" << endl;
		n = stringToInt(secondLine);
		cout << '\"' << secondLine << "\" �� ���� " << n << " (��)�� ��ȯ��" << endl;
	}
	catch (const char* s) {
		cout << s << " �� ó������ ���� �߻�!!" << endl;
		return 0;
	}
	return 0;
}