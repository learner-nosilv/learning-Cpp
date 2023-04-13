#include "3_11_Box.h"
#include <iostream>
using namespace std;

int main() {
	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();

	return 0;
}