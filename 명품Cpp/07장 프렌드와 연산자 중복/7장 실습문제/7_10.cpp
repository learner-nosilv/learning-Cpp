/* 10. ��踦 ���� Statistics Ŭ����
�����ʹ� int �迭 �����Ҵ�
! >> << ~ ������ �Լ� �ۼ��ϱ�
*/
#include <iostream>
using namespace std;

class Statistics {
	int size;
	int* arr;
	int empty;
public:
	Statistics() {
		this->size = 7;
		this->arr = new int[this->size];
		this->empty = 0;
	}
	~Statistics() { delete[] arr; }

	// ! : �����Ͱ� ������� ������
	bool operator!() { return this->empty == 0; }

	// << : Push the data
	Statistics& operator<<(int i) {
		if (empty < size) {
			*((this->arr) + empty) = i;
			empty++;
		}
		else cout << "!!�뷮 �ʰ�!!" << endl;
		return *(this);
	}

	// >> ��� ���
	int& operator>>(int& avg);

	// ~ Data�������
	void operator~();
};

int& Statistics::operator>>(int& avg) {
	avg = 0;
	if (!(*this)==false) {
		for (int i = 0; i < this->empty; i++)
			avg += *(this->arr + i);
		avg /= this->empty;
	}
	return avg;
}

void Statistics::operator~() {
	for (int i = 0; i < empty; i++)
		cout << this->arr[i] << ' ';
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat) cout << "���� ��� ����Ÿ�� �����ϴ�." << endl;

	int x[5];
	cout << "5 ���� ������ �Է��϶�>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	
	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
	return 0;
}