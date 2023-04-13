#include <iostream>
using namespace std;

class Tower {
	int height;
public:
	Tower() :Tower(1) {};
	Tower(int h) { height = h; }
	int getHeight() { return height; }
};

int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
	return 0;
}