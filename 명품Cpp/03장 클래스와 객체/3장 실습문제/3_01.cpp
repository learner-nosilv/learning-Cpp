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
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
	return 0;
}