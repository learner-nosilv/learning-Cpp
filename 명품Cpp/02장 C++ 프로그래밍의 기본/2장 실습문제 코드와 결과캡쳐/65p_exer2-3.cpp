/*
	In this program,
	the main() function
		1. prompts the user to enter two integer numbers,
		2. reads them from the keyboard using the cin object,
		3. stores them in variables width and height,
		4. stores multiplication result of variables width and height in variable area,
		5. Finally, prints the value of area using the cout object.
*/
#include <iostream>
using namespace std;

int main(void) {
	cout << "너비를 입력하세요>>";
	int width;
	cin >> width;	// 입력받아서 변수 width에 저장

	cout << "높이를 입력하세요>>";
	int height;
	cin >> height;	// 입력받아서 변수 height에 저장

	int area = width * height;
	cout << "면적은 " << area << endl;

	return 0;
}