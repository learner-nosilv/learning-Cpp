/* 3.
* string Ŭ������ �̿��Ͽ� ��ĭ�� �����ϴ� ���ڿ� �Է¹ޱ� getline(cin,����,������)
* a�� �� �� �ִ��� ����ϱ� - .find(���ڿ�, -����)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// 1. ������ ������ ���ڿ� �Է¹ޱ�, �����ڴ� '/n'����
	string sentence;
	cout << "���ڿ� �Է�>> ";
	getline(cin, sentence, '\n');

	// 2 (1). string Ŭ������ ��� at()�� []�� �̿��Ͽ� �ۼ��ϱ�
	int start_idx = 0;
	int counter = 0;
	int size = sentence.size();

	for (int i = 0; i < size; i++) {
		if (sentence[i] == 'a')
			counter++;
	}

	cout << "���� a�� " << counter << "�� �ֽ��ϴ�." << endl;

	// ------------------------------------
	// 2 (2). find() ��� �Լ��� �̿��Ͽ� �ۼ��ϱ�
	
	start_idx = sentence.find('a');
	counter = 0;

	while (start_idx != -1) {
		counter++;
		start_idx = sentence.find('a', start_idx + 1);
	}

	cout << "���� a�� " << counter << "�� �ֽ��ϴ�." << endl;

	return 0;
}