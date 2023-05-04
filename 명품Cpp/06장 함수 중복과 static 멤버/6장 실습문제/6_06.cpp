/* 6. ������ ũ��� �迭�� ��ȯ�ϴ� ���� 2���� static ����Լ��� ���� ArrayUtility2 Ŭ���� �ۼ��ϱ�
* �ְܼ���� ���� ������ main() �ۼ��ϱ�
*/
#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	// s1, s2�� ������ �迭 �������� & �������� ����
	static int* concat(int s1[], int s2[], int size);
	// s1-s2�� �迭 �������� & �������� ���� , �ش� �迭�� ũ��� �����Ķ���ͷ� �������� 
	static int* remove(int s1[], int s2[], int size, int& retSize);	
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* add = new int[2 * size];
	int j = 0;
	for (int i = 0; i < size; i++, j++)
		add[j] = s1[i];
	for (int i = 0; i < size; i++, j++)
		add[j] = s2[i];
	return add;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* temp = new int[size];	// �ӽð���迭
	retSize = 0;				// ����迭�� ũ��

	// �迭 s1���� s2�� �� ��� ���ϱ�
	for (int i = 0; i < size; i++) {	// s1[0~]

		// s1[i] s2[0~] ��
		int match_idx = 0;
		while (match_idx < size) {
			if (s1[i] == s2[match_idx]) break;
			match_idx++;
		}	
		// ��Ȳ1. if(s1[i] == s2[match_idx])�� ���� or ��Ȳ2. while(match_idx < size)�� ����
		if(match_idx>=size){		// ��Ȳ2. s1[i]�� s2�迭�� ���� ���
			temp[retSize] = s1[i];	// �ӽð���迭�� ����
			retSize++;				// ����迭�� ũ������
		}
	}

	// �ӽð���迭�� ũ�Ⱑ size�̹Ƿ�, ũ�Ⱑ retSize�� ����迭 �����޸� �Ҵ�
	int* sub = new int[retSize];
	for (int i = 0; i < retSize; i++)
		sub[i] = temp[i];

	// �ӽ� ����迭 �����޸� ��ȯ
	delete[] temp;

	return sub;
}

int main() {
	const int size = 5;
	int x[size] = { 0, };
	int y[size] = { 0, };

	cout << "������ " << size << " �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < size; i++)
		cin >> x[i];

	cout << "������ " << size << " �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < size; i++)
		cin >> y[i];

	cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
	int* add_result = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < 2*size; i++)
		cout << add_result[i] << ' ';
	cout << endl;

	int subsize;
	int* sub_result = ArrayUtility2::remove(x, y, size, subsize);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << subsize << endl;
	for (int i = 0; i < subsize; i++)
		cout << sub_result[i] << ' ';
	cout << endl;

	delete[] add_result;
	delete[] sub_result;

	return 0;
}