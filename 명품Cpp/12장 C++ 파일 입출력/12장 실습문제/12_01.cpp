/* 638p. 메모장을 이용하여 파일을 편집하고, 파일을 읽어 출력하는 프로그램 작성 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("test.txt", ios::out);
	if (!fout) {
		cout << "out: 파일 열기 실패" << endl;
		return 0;
	}
	fout.write("0123456789\nInteger", 18);
	fout.close();

	ifstream fin("test.txt", ios::in);
	if (!fin) {
		cout << "in: 파일 열기 실패" << endl;
		return 0;
	}
	
	char c;
	while ((c = fin.get()) != EOF)
		cout << c;		// cout.put(c);
	fin.close();
	return 0;
}