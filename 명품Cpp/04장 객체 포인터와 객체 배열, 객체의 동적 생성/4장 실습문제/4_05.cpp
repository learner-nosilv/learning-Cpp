/* 5.
* string Ŭ������ �̿��Ͽ� ���� �� �� �Է¹ޱ� : getline(cin, ����, ������)
* ���� �ϳ��� �����ϰ� �����Ͽ� ���
* 
* �������� : <cstdlib> �� srand, rand, <ctime>�� time ���
* 
* ascii �ڵ�ǥ�� ����, 33 ~ 126������ ���ڵ��̰�,
* 65~90������ ���ĺ� �빮��, 97~122������ ���ĺ� �ҹ����̴�.* 
*/

#include <iostream>		// c++ ǥ�� �����
#include <string>		// string Ŭ�������
#include <cstdlib>		// srand, rand �� ���
#include <ctime>		// time ���
using namespace std;	// ��� std namespace �ӿ� ����

int main() {
	string sentence;
	while (1) {								// ����
		// 1. ���� �� �� �Է¹ް�, ���ڰ��� �ľ�
		cout << ">>";
		getline(cin, sentence, '\n');
		if (sentence == "exit") break;		// ����Ż������: exit �Է�
		int size = sentence.size();

		// 2. ��ü�� ������ index�� �����ϰ� ����
		srand((unsigned)time(NULL));	// seed ����
		int index = rand() % size;

		// 3. ��ü�� ������ ascii�ڵ尪 �����ϰ� ���� (65~90, 97~122)
		int ascii = 91;						// '['
		while (ascii >= 91 && ascii <= 96) {	// ��ü�� ���ڰ� ���ĺ��� �ƴ϶�� �ݺ� 
			ascii = (rand() % 58) + 65;		// 65 ~ 122 ������ ���� ����
		}

		// 4. ���� �� �ٿ��� ���� �ϳ��� �����ϰ� �����Ͽ� ���
		sentence[index] = (char)ascii;
		cout << sentence << endl;
	}
	
	return 0;
}