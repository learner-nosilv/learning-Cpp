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
	cout << "�ʺ� �Է��ϼ���>>";
	int width;
	cin >> width;	// �Է¹޾Ƽ� ���� width�� ����

	cout << "���̸� �Է��ϼ���>>";
	int height;
	cin >> height;	// �Է¹޾Ƽ� ���� height�� ����

	int area = width * height;
	cout << "������ " << area << endl;

	return 0;
}