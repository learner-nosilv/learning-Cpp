/* 12. ���� �迭�� �׻� ���� ������ �����ϴ� SortedArray Ŭ������ �ۼ��Ϸ��� �Ѵ�.
* �Ʒ��� main() �Լ��� �۵��� ��ŭ�� SortedArray Ŭ������ �ۼ��ϰ� +�� =�����ڵ� �ۼ��϶�
*/

#include <iostream>
using namespace std;

class SortedArray {
	int size;		// �迭ũ��
	int* p;			// �迭
	void sort();	// �������� ����
public:
	SortedArray() { this->p = NULL; this->size = 0; }	// 1. �⺻������
	SortedArray(int p[], int size);						// 2. ������: ���� �� �� �迭
	SortedArray(const SortedArray& src);				// 3. ���������
	~SortedArray() { delete[] p; }						// �Ҹ���

	void show();										// ��ü �� �迭 ���
	SortedArray operator+(SortedArray& op2);			// �� ��ü�� ��ģ ��ü ��return
	SortedArray& operator=(const SortedArray& op2);		// ����ȭ & �� ��ü ����return
	
};

// Private : �������� ����
void SortedArray::sort() {
	if (this->size <= 1) return;

	for (int i = 0; i < (this->size)-1; i++) {
		for (int j = i + 1; j < (this->size); j++) {
			if ((this->p[i]) > (this->p[j])) {
				int temp = this->p[i];
				this->p[i] = this->p[j];
				this->p[j] = temp;
			}
		}
	}
}

// 2. ������: ���� �� �� �迭
SortedArray::SortedArray(int p[], int size) {
	this->size = size;				// �ܼ� ���� ��,
	this->p = new int[this->size];
	for (int i = 0; i < size; i++) this->p[i] = p[i];
	this->sort();					// ����
}

// 3. ���� ������
SortedArray::SortedArray(const SortedArray& src) {
	this->size = src.size;
	this->p = new int[this->size];
	for (int i = 0; i < (this->size); i++) this->p[i] = src.p[i];
}

// ��ü �� �迭 ���
void SortedArray::show() {
	cout << "�迭 ��� :";
	for (int i = 0; i<(this->size); i++)
		cout << ' ' << this->p[i];
	cout << endl;
}

// �� ��ü�� ��ģ ��ü ��return
SortedArray SortedArray::operator+(SortedArray& op2) {	// �� ��ü�� ��ģ ��ü return
	SortedArray temp;
	temp.size = (this->size + op2.size);
	temp.p = new int[temp.size];

	int idx = 0;

	for (int i = 0; i < this->size; i++) {
		temp.p[idx] = this->p[i];
		idx++;
	}
	for (int i = 0; i < op2.size; i++) {
		temp.p[idx] = op2.p[i];
		idx++;
	}
	temp.sort();
	return temp;
}

// ����ȭ & �� ��ü ����return
SortedArray& SortedArray::operator=(const SortedArray& op2) {
	delete[] this->p;				// ���� �迭�� �����Ҵ� ����
	this->size = op2.size;
	this->p = new int[this->size];	// ���Ҵ�
	for (int i = 0; i < this->size; i++) this->p[i] = op2.p[i];
	return *this;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();

	return 0;
}