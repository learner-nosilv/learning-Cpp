#include <iostream>	// ǥ�� ����� ���̺귯��
#include <cstdlib>	// ���� ������ ���� srand(), rand(), RAND_MAX ���
#include <ctime>	// ���� ���� ������ �����ϴ� seed�� �ش� ���̺귯���� time() ���

using namespace std;

//3.5
// ������ ������ �����ϰ� �����ϴ� Ŭ����
class Random {
public:
	Random();							// ������
	int next();							// 0�̻� 32767������ ������ ������ ��ȯ�ϴ� �Լ�
	int nextInRange(int low, int high);	// low�̻� high������ ������ ������ ��ȯ�ϴ� �Լ�
};

// �����ڴ� �ƹ��� ���� ���� �ʴ´� (=�⺻������)
Random::Random() {
	// srand((unsigned)time(0)); �� ������ ��ȭ�ϴ� time(0)�� seed�� ��ü ������ �����������ϰ���
	// ���α׷��� �� ���� �̸����� ��ü�� �����ϹǷ� seed�� time(0)���� �������ʴ´�.
	// = ��� ��ü�� �������������� ����������.
	// ����, �����ڿ� �� �ڵ带 ����ϴ� �ͺ��ٴ� main���� �ѹ� ������ִ� ���� �����ϴٰ� �Ǵ�
}

// ����Լ� next�� 0�̻� 32767���� ������ ������ �����Ѵ�
int Random::next() {
	return rand();	// 0~32767 ������ ���� ����
}

// ����Լ� nextInRange�� low~high ������ ������ ������ �����Ѵ�
int Random::nextInRange(int low, int high) {
	// ����	1. 0~32767 ������ ������ N ���� ���� ������, �� 0 ~ (N-1) ������ ������ �����ϸ��Ѵ�.
	//		2. low�� ���Ѵ�
	//		3. N�� high-low+1�� �ϸ�, ���������� ������ ������ low~high ������ ������ �ȴ�.

	int gap = high - low + 1;

	if (gap <= 0) {						// ���� �Է��� �߸��� ���(low > high),
		cout << "!!�Է¿���!!" << endl;	//	 �������� �˸���
		exit(1);						//	 ���α׷��� �����Ѵ�. (1=����������)
	}

	int num = (rand() % gap) + low;		// 0 ~ (high-low) ������ ������ low�� ���Ͽ� ���ϴ� ����(low~high)�� ������ �����.
	return num;							// low~high ������ ������ �����Ѵ�
}
/* [�б� �ַ�ǰ� ����]
	int Random::nextInRange(int low, int high) {
		int range = (high - low) + 1;
		return low + (rand() % range); // low�� high ������ ���� ������ �����Ѵ�. 
*/


//3.6
// ������ ¦���� �����ϰ� �����ϴ� Ŭ���� (0�� ¦���� ó���Ѵ�)
class EvenRandom {
public:
	EvenRandom();
	int next();							// 0�̻� 32767������ ������ ¦���� ��ȯ�ϴ� �Լ�
	int nextInRange(int low, int high);	// low�̻� high������ ������ ¦���� ��ȯ�ϴ� �Լ�
};

// �����ڴ� �ƹ��� ���� ���� �ʴ´� (=�⺻������)
EvenRandom::EvenRandom() {
}

// ����Լ� next�� 0�̻� 32766���� ������ ¦���� �����Ѵ�
int EvenRandom::next() {
	int num = rand();	// num: 0�̻� 32767������ ������ ����
	num /= 2;			// num: 0�̻� 16383������ ������ ����
	num *= 2;			// num: 0�̻� 32766������ ������ "¦��" (num = (rand()/2)*2; �� ����)
	return num;			// 0�̻� 32766������ ������ ¦���� �����Ѵ�.
}
/* [�б� �ַ���� if(�������� ¦���϶� �����ϱ�)�� �ݺ��ϴ� ���]
* int EvenRandom::next() {
	while (true) {
		int n = rand();
		if (n % 2 == 0) return n;
	}
}
*/

// ����Լ� nextInRange�� low�̻� high���� ������ ¦���� �����Ѵ�
int EvenRandom::nextInRange(int low, int high) {
	int gap = high - low ;

	if (gap < 0) {						// ���� �Է��� �߸��� ���(low > high),
		cout << "!!�Է¿���!!" << endl;	//	 �������� �˸���
		exit(1);						//	 ���α׷��� �����Ѵ�. (1=����������)
	}

	gap++;	// gap = high-low+1

	int num = rand() % gap;	// num: 0�̻� high-low������ ������ ����
	num /= 2;				// num: 0�̻� high-low/2������ ������ ���� (high-low�� Ȧ���� ���, high-low-1/2)
	num *= 2;				// num: 0�̻� high-low������ ������ "¦��" (high-low�� Ȧ���� ���, high-low-1)
	num += low;				// num: low�̻� high������ ������ ¦�� (high-low�� Ȧ���� ���, high-1)
	return num;				// low�̻� high���� ������ ¦���� num�� �����Ѵ�
}
/* [�б� �ַ���� if(...���� ����]
int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	while (true) {
		int n = low + (rand() % range);
		if (n % 2 == 0) return n;
	}
}
*/


// main: 0~32767������ ��������, 2~4������ ��������, �� ������ ����¦���� �ֿܼ� ����Ѵ�
int main() {
	// 0. rand()�� seed ����: ���α׷��� ���� �� time(0)�� seed�� �Ͽ� ���������� �����ȴ�.
	srand((unsigned) time(0));	// 1970�� 1�� 1�� 0�� 0�� 0�� ~ ������ �ð��� time(0)�� ��������ȯ�Ͽ� rand()�� seed�� ����

	// 1. ������ ������ ������ �� �ִ� ��ü r ����
	Random r;

	// 2. range�� 0 ~ RAND_MAX�� ������ ���� 10ȸ �ܼ� ����ϱ�, ���� ����Լ� next ���
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;	// RAND_MAX�� rand()�� ��ȯ�� �� �ִ�(32767)
	for (int i = 0; i < 10; i++) {	// �Ʒ� �� ������ 10ȸ �ݺ�
		int n = r.next();			//	 0 ~ RAND_MAX�� ������ ������ n�� �Ҵ�
		cout << n << ' ';			//	 n �� ���鹮�� ���
	}

	// 3. range�� 2 ~ 4�� ������ ���� 10ȸ �ܼ� ����ϱ�, ���� ����Լ� nextInRange ���
	cout << endl<<endl<< "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {		// �Ʒ� �� ������ 10ȸ �ݺ�
		int n = r.nextInRange(2, 4);	//	 2 ~ 4�� ������ ������ n�� �Ҵ�
		cout << n << ' ';				//	 n �� ���鹮�� ���
	}
	cout << endl;						// ����

	cout << "-------------------------------------------------------" << endl;
	cout << endl;

	// 4. ������ ¦���� ������ �� �ִ� ��ü er ���� 
	EvenRandom er;

	// 5. range�� 0 ~ RAND_MAX�� ������ ¦�� 10ȸ �ܼ� ����ϱ�, ���� ����Լ� next ���
	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {	// �Ʒ� �� ������ 10ȸ �ݺ�
		int n = er.next();			//	 0 ~ RAND_MAX�� ������ ¦���� n�� �Ҵ�
		cout << n << ' ';			//	 n �� ���鹮�� ���
	}

	// 6. range�� 2 ~ 10�� ������ ¦�� 10ȸ �ܼ� ����ϱ�, ���� ����Լ� nextInRange ���
	cout << endl << endl << "-- 2���� " << "10 ������ ¦�� ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {		// �Ʒ� �� ������ 10ȸ �ݺ�
		int n = er.nextInRange(2, 10);	//	 2 ~ 10�� ������ ¦���� n�� �Ҵ�
		cout << n << ' ';				// 	 n �� ���鹮�� ���
	}
	cout << endl;

	return 0;
}



/* [�б� �ַ��]
#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

// ������ ������ �����ϰ� �����ϴ� Ŭ����
class Random {
public:
	Random(); // ������. ���� seed�� �����Ѵ�.
	int next(); // ���� ������ �����Ѵ�.
	int nextInRange(int low, int high); // low�� high ������ ���� ������ �����Ѵ�.
};

Random::Random() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int Random::next() {
	return rand(); // 0���� RAND_MAX ������ ������ ���� ����
}

int Random::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	return low + (rand() % range); // low�� high ������ ���� ������ �����Ѵ�. 
}

//5.7
// ¦���� �����ϰ� �߻���Ű�� Ŭ����
class EvenRandom {
public:
	EvenRandom(); // seed ����
	int next(); // ���� ¦�� ����
	int nextInRange(int low, int high); // low�� high ������ ���� ¦�� ����
};

EvenRandom::EvenRandom() {
	srand((unsigned)time(0)); // ������ seed�� �����Ͽ� �� ������ �ٸ� ���� ���� ������ �Ѵ�.
}

int EvenRandom::next() {
	while (true) {
		int n = rand();
		if (n % 2 == 0) return n;
	}
}

int EvenRandom::nextInRange(int low, int high) {
	int range = (high - low) + 1;
	while (true) {
		int n = low + (rand() % range);
		if (n % 2 == 0) return n;
	}
}



int main() {
	Random r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;

	EvenRandom er;
	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.next(); // 0���� RAND_MAX(32767) ������ ������ ¦������
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "10 ������ ¦�� ���� ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = er.nextInRange(2, 10); // 2���� 10 ������ ������ ¦������
		cout << n << ' ';
	}
	cout << endl;

}
*/