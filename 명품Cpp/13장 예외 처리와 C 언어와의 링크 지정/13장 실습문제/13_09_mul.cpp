/* �������� 9. get.c�� mul.cpp ���Ϸ� �����Ǵ� ������Ʈ �ۼ��ϱ� */
#include <iostream>
using namespace std;

extern "C" int get();
int main() {
	while (true) {
		int a = get();
		int b = get();
		cout << "���� " << a * b << "�Դϴ�." << endl;
	}
}