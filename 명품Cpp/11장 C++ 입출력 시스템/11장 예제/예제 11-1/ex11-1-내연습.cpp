#include<iostream>
using namespace std;

int main() {
	char ch = '\n';
	cout.put('H');	// ��� ���ͷ�
	cout.put('i');
	cout.put(33);	// ASCII �ڵ尪
	cout.put(ch);	// ����
	cout.flush();	// ��Ʈ�� ���ۿ� �����ִ� ���ڸ� ��������ϴ� flush (������ ��µǳ� �ñ��ѵ�)
	// flush�� ��µ� ���� ����. 542p�� ������ ���� ��ȣ�ϴ�.

	cout.put('C').put('+').put('+').put(' ');
	// put()�Լ��� ����Ÿ���� ostream& ��� ���������̱⶧���� �������� �����ϴ�.

	char str[] = "I love programming";
	cout.write(str, 6);	// 6���ڸ� ���
	cout.flush();

	return 0;
}