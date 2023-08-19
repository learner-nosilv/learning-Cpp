/* 638p. �޸����� �̿��Ͽ� ������ �����ϰ�, ������ �о� ����ϴ� ���α׷� �ۼ� */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("test.txt", ios::out);
	if (!fout) {
		cout << "out: ���� ���� ����" << endl;
		return 0;
	}
	fout.write("0123456789\nInteger", 18);
	fout.close();

	ifstream fin("test.txt", ios::in);
	if (!fin) {
		cout << "in: ���� ���� ����" << endl;
		return 0;
	}
	
	char c;
	while ((c = fin.get()) != EOF)
		cout << c;		// cout.put(c);
	fin.close();
	return 0;
}