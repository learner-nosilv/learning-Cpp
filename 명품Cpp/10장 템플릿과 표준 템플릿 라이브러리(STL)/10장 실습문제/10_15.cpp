/* 15. vector�� �̿��Ͽ� Circle Ŭ������ ��ü�� �����ϰ� �����ϴ� ���α׷� �ۼ��ϱ�.
 ���� ��, �̸��� ���� ��� ���� �����Ѵ�. */

#include <iostream>
#include <vector>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14 * this->radius * this->radius; }
	string getName() { return this->name; }
};

class managementCircle {
	vector<Circle*> v;
	void insertCircle();
	void removeCircle();
	void showAll();
	int getMenu();
public:
	managementCircle() {}
	~managementCircle(){
		for (int i = 0; i < v.size(); i++)
			delete v[i];
	}
	void run();
};

void managementCircle::insertCircle() {
	int circleRadius; 
	string circleName;
	while (true) {
		cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
		cin >> circleRadius >> circleName;
		if (cin.fail()) {
			cout << "�˸´� ����:(���������� ������)+(����)+(�̸�) ���� �Է��ϼ���.'\n'";
			cin.clear();
			cin.ignore(50, '\n');
		}
		else {
			v.push_back(new Circle(circleRadius, circleName));	// �����Ҵ�
			return;
		}
	}
}

void managementCircle::removeCircle() {
	string circleName;
	cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
	cin >> circleName;
	vector<Circle*>::iterator it = v.begin();
	while (it != v.end()) {
		Circle* pTemp = *it;	// it�� ����Ű�� ���� Circle* ���̹Ƿ�
		if ((*it)->getName() == circleName) {
			it = v.erase(it);	// ���� �� ���� ����� ������ ����
			delete pTemp;
		}
		else it++;
	}
	// for (int i = 0; i < v.size(); i++) �� �̿��ص� ������ ��Ʈ�̿�
	// erase�ϸ� ���� ���� �Ѿ�⶧���� for���� ����ϴ°� ��ٷο���
	// �׸���, erase�Ѵٰ� �����Ҵ��� �����Ǵ� ���� �ƴϾ���....
}

void managementCircle::showAll() {
	for (int i = 0; i < v.size(); i++)
		cout << v[i]->getName() << '\n';
	cout << endl;
}

int managementCircle::getMenu() {
	int menu;
	while (true) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> menu;

		if (cin.fail()) {
			cout << "1, 2, 3, 4 �߿� �ϳ��� �Է��ϼ���.'\n'";
			cin.clear();
			cin.ignore(50, '\n');
		}
		else if (menu != 1 && menu != 2 && menu != 3 && menu != 4)
			cout << "1, 2, 3, 4 �߿� �ϳ��� �Է��ϼ���.'\n'";
		else return menu;
	}
}
void managementCircle::run() {
	cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�.\n";
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1:
				insertCircle(); break;
			case 2:
				removeCircle(); break;
			case 3:
				showAll(); break;
			case 4:
				return;
		}
	}
}

int main() {
	managementCircle mark1;
	mark1.run();
	return 0;
}