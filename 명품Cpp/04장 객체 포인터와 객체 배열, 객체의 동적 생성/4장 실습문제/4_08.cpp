/* 8. 7�� ������ �����ϱ�
* ���� �߻�ȭ�� Ŭ���� Circle
* �������: ������ radius
* ����Լ�: ���������� setRadius, �������� getArea
* 
* �����Լ�
* 1. ���� ������ �Է¹ް� circle ��ü�迭 �����Ҵ� (����: 3���� circle ��ü �迭����)
* 2. ��ü�� ������ �� �Է¹޾Ƽ� �����ϱ�
* 3. ������ 100���� ū ���� ���� ���
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int r) {
		radius = r;
	}
	double getArea() {
		return 3.24 * radius * radius;
	}
};

int main() {
	// 1. ���� ���� �Է¹ް� N���� Circle ��ü �迭 �����Ҵ�
	int n;
	cout << "���� ���� >> ";
	cin >> n;
	Circle* p = new Circle[n];
	int wider = 0;

	// 2. ������ �� �Է¹޾Ƽ� �����ϱ� + 100���� ū ���� ���� ����
	for (int i = 0; i < n; i++) {
		int r;
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r;
		(p+i)->setRadius(r);

		if ((p + i)->getArea() > 100)
			wider++;
	}
	
	// 3. ������ 100���� ū ���� ���� ���
	cout << "������ 100���� ū ���� " << wider << "�� �Դϴ�" << endl;

	// 4. �����Ҵ� ��ȯ
	delete[] p;
	return 0;
}
