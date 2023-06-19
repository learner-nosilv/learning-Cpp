/* 9.	STL�� vector Ŭ������ �̿��Ͽ� �����Է��� �ް�, �Է��� ������� ����� ����ϴ� ���α׷� �ۼ��ϱ�
*		���α׷� ����: 0
*/
#include <iostream>
#include <vector>		// Standard Template Library
using namespace std;

bool cinNcheck(int& a) {
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10, '\n');
		return false;
	}
	else
		return true;
}

int main() {
	vector<int> arr;
	int answer = 0, size = 0, result = 0;
	while (true) {
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		if (cinNcheck(answer) == false) {	// ���1. ������ ����Ű�� ��
			cout << "����� �� ���� �Է��ϼ���." << endl;
			continue;
		}
		else if (answer == 0)				// ���2. ���� 0 (����)
			break;
		else {								// ���3. �����Է�
			arr.push_back(answer);			//	�����迭�� ����
			result += answer;				//	���� �� ��
			size++;							//	arr.size() �ص� ������..
			for (int i = 0; i < size; i++)	//	���� ���� ���
				cout << arr[i] << ' ';
			cout << '\n';
			cout << "��� = " << (double)result / size << endl;
		}
	}
	return 0;
}