/* ù��° �߻� : [0] ��°���� ����& �� �ڿ� ���� : 1. ���ڿ�.insert(���ڿ�.size(), ���ڿ�[0]), 2. ���ڿ�.erase(0, 1)
	1. ��Ʈ����ü.insert(�ε���, ��Ʈ��): ��Ʈ����ü�� Ư�� �ε����� ��Ʈ�� ����
	2. ��Ʈ����ü.erase(�ε���, ����): ��Ʈ����ü�� Ư�� �ε������� N���� ����
	
   �ι�° �߻�: insert��ſ� + ���, ���� ��ſ� ���ο� �迭substr()
   ��Ʈ����ü.substr(�ε���, ����): ��Ʈ����ü�� Ư�� �ε������� N���ڸ� �� ��ȯ
   ^^^^ 
   �� ��� ä��, ���� : ���� ����� ��½���� substr�� ��
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string str1;
	cout << "Type String" << endl;
	getline(cin, str1, '\n');		// ���� �������� ���ڿ��� ��Ʈ����ü str1�� ����
	int size = (str1).size();
	
	// ù��° �߻��� �����ϰ� - 
	for (int i = 0; i < size; i++) {
		str1 = str1 + str1[0];
		str1.erase(0, 1);
		cout << str1 << endl;
	}

	// �ι�° �߻�: å�� ������
	for (int i = 0; i < size; i++) {
		string first = str1.substr(1, size - 1);
		string sub = str1.substr(0, 1);
		str1 = first + sub;
		cout << str1 << endl;
	}

	return 0;
}