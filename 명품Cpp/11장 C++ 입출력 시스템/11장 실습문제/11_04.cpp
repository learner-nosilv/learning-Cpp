/* 4. 3�� �������� ; ������ �Էµ� ���ڿ��� ����ϱ�
3. �����;�ѱ۹��� �������� �Էµ� ��, ; ���Ŀ� �Էµ� ���ڿ��� ���, ctrl+Z�� ^Z�� �Է����Ḧ ��Ÿ����.
cin.ignore()��, cin.get() ����ϱ� */
#include <iostream>
using namespace std;

int main() {
	int ch;
	while ((ch = cin.get()) != EOF) {
		if (ch == ';') {
			cin.ignore(100, '\n');
			cout << '\n'; 
			continue;
		}
		cout << (char)ch;
	}
}
