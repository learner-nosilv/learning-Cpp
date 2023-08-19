/* 10. �� ������ ������ ���ϴ� FileCompare ���α׷� �����
	* ���̳ʸ� I/O �̿�
*/
#include <iostream>
#include <fstream>
using namespace std;

// �� ������ ������ ���ϴ� �Լ�
bool fileCompare(const char* img1, const char* img2) {
	ifstream fin1(img1, ios::in | ios::binary);		// ù��° ���� ���̳ʸ�I/O��, �б�������� ���α׷��� ����
	ifstream fin2(img2, ios::in | ios::binary);		// �ι�° ���� ���̳ʸ�I/O��, �б�������� ���α׷��� ����
	if (!fin1 || !fin2) {							// if �������
		cout << "[Error] �����б����\n";
		return false;								// ������п� ���� false ����
	}

	char buf1[32], buf2[32];						// ���� ����: 32byte
	int count1 = 0, count2 = 0;						// ������ ���� ����Ʈ ��

	while (!fin1.eof() && !fin2.eof()) {
		// 32byte������ ���� �б�
		fin1.read(buf1, 32);
		fin2.read(buf2, 32);

		count1 = fin1.gcount();
		count2 = fin2.gcount();

		if (count1 == count2) {						// ���1. ���� ���ڼ��� ���� ��
			for (int i = 0; i < count1; i++)
				if (buf1[i] != buf2[i])				//	1-1. �� ���ڶ� �ٸ��� false ����
					return false;
		}
		else										// ���2. ���� ���ڼ��� �ٸ� ��
			return false;							//	false ����
		// ���1-2. ���� ���� ���� ���� ���������� ���� ��� = ������� true
	}
	// ��� byte�� ���� ��츸 ����
	return true;
}

int main() {
	// ����� �̹��� 
	const char* img[3] = { "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_10_solution_a.jpg",
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_10_solution_b.jpg",
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_10_solution_c.jpg" };
	
	cout << "FileCompare--------------------\n";
	cout << "1. IMG1 VS IMG2 ������ ";
	if (fileCompare(img[0], img[1])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	cout << "2. IMG2 VS IMG3 ������ ";
	if (fileCompare(img[1], img[2])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	cout << "1. IMG3 VS IMG1 ������ ";
	if (fileCompare(img[2], img[0])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	return 0;
}
// �ַ���� class�� �̿��Ͽ���, ���Ϻ񱳵� 1byte�� ����