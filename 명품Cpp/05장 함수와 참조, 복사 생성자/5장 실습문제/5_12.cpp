/* 12.
* �а��� ��Ÿ���� Dept Ŭ����
* main()�� �������� ������ ���� �ǵ��� Dept Ŭ������ ������� ��� �����ϰ�
* ��ü ���α׷��� �ϼ��ϱ�
* 
* 60�� �̻�� �ʰ��� ȥ��Ǿ��ִµ�, (1)�� �������� ���� 60�� �̻��� �ƴ϶�, <<�ʰ�>>�� �´�.
*/

#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;				// ������ �����ϴ� �迭 �����Ҵ�)
public:
	Dept(int size) {			// �迭 �����Ҵ�
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept);
	~Dept() { delete[] scores; }
	int getSize() { return size; }
	void read();				// �а��Ҽ� ��� �л����� ������ �о����
	bool isOver60(int index) {	// Ư�� index�� �л������� 60 �ʰ��Ͻ� true
		if (scores[index] > 60)
			return true;
		else
			return false;
	}
};
 
Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int [(this->size)];
	for (int i = 0; i < (this->size); i++)
		this->scores[i] = dept.scores[i];
}

void Dept::read() {
	cout << this->size << "�� ���� �Է�>> ";
	for (int i = 0; i < this->size; i++)
		cin >> this->scores[i];
}

// (2) ���� �����ڰ� ���� ���, com.score�� dept.score�� ������ ���� ���´�.
// �� ��, �Լ� countPass()�� ����Ǹ�, �Ķ���� dept�� �Ҹ�Ǹ� dept.score�� ����Ű�� �ִ� �����Ҵ������ �����ȴ�.
// �� ��, �Լ� main()�� ����Ǿ� com��ü�� �Ҹ��� �� com.score�� �⸮Ű�� �ִ� �����Ҵ���� ��������� ����Ǹ� ��Ÿ�ӿ��� �߻�
int countPass(Dept dept) {		// (2) ��������� ȣ����ġ : [call by value] Dept dept(com);
								//		���� com�� �Ķ���� dept�� �����ϸ� ��������� ���� 
	int count = 0;				// (3) (2) Dept & dept [call by reference] �� �������ָ� ��Ÿ�� ������ �߻����� ����
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i))
			count++;
	}
	return count;
}

int main(){
	Dept com(10);	// com �а� : �л� 10��
	com.read();		// ���� �о���̱�
	int n = countPass(com);
	cout << "60�� �ʰ��� " << n << "��" << endl;

	return 0;					 
}