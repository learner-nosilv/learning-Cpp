/* �������� 10. ���� printline(int count) �Լ��� �� �ٿ� count ���� '*'�� ����ϴ� �Լ��̴�. 
* �� �Լ��� ����Ͽ� ȭ�鿡 ����ϴ� ���α׷��� pr.cpp ���Ϸ� �ۼ��ϰ�
* print.c�� pr.cpp ���Ϸ� �����Ǵ� ������Ʈ�� �����Ͽ� �����϶�.
*/
#include <iostream>
using namespace std;

extern "C" void printline(int count);

int main() {
	for (int i = 1; i < 4; i++)
		printline(i);
	return 0;
}