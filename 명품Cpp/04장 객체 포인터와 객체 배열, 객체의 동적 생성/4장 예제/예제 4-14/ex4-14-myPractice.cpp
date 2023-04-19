/*
* ���ڿ��� �������� �Է¹޾Ƽ� ������ ����ϴ� ���α׷�
* 1. getline(cin, , )���� �� �Է¹ޱ�: ���� ���͸��� �ԷµǴ� ���� ����
* 2. find �̿��Ͽ� + ã�� : if + ��ġ�� -1 : ���ڸ� �ִٴ� �� string ���� -> int �װ� ��
							if + ��ġ�� [I] : 0-[I-1]���� ���ڷ� ����� result�� ����ֱ�
	 find �̿��Ͽ� I+1���� + ã��
* 
*/
#include <iostream>
#include <string>
using namespace std;

bool isInputError() {
	if (cin.fail()) {	// ���ۿ� ������ ���ٸ�,
		cin.clear();	//  ���¸� �������� �ʱ�ȭ�ϰ�
		cin.ignore(100, '\n');	// ���๮�ڱ��� �ִ� 100���ڸ� ����
		return true;	// ���������� �˸���
	}
	else
		return false;
}

int main() {
	// 1. �� �Է¹ޱ�
	string exp;			// ��

	do {
		cout << "7+23+5+100+25�� ���� ���� ���ڿ��� �Է��ϼ���." << endl;
		cin >> exp;			// getline(cin, exp, '\n');
	} while (isInputError());

	int size = exp.size();	// �Ŀ���, �� ���� ����
	int result = 0;			// ���� ����� �����
	int startIndex = 0;		// ���ڰ� ���۵Ǵ� �ε��� 
	int count;				// ������ ����
	int exp_idx = -1;		// �Ŀ���, +�� ��ġ�� ������ �ε���
	
	// 2. �Ŀ��� ���ڰ��� ���� �����ϱ�
	while (startIndex<size) {	// �ν��� �� �Ǳ� ������ �ݺ�
		exp_idx = exp.find('+', (exp_idx + 1));		// ���� �νĵ��� ���� ������ + ã��

		if (exp_idx == -1) {						// 1) �� �̻� +�� ���ٸ�: num_idx ~ ������ ���ڶ�� [�������̶�� �ǹ�]
			count = size - startIndex;				// �� ���������� ���ڿ����� ������ ����
			int operand = stoi(exp.substr(startIndex, count));	// ���� -> ���ڷ� ��ȯ
			cout << operand << endl;							// �ش� ���� ���
			result += operand;						// �� ����
			break;									// ���� Ż��
		}
		else {					// 2) �������� +�� �ƴϸ鼭�� �νĵ��� ���� +�� �����Ѵٸ�
			count = exp_idx - startIndex;			// + ������, ������ ���� (substr�� �ʿ�)
			int operand = stoi(exp.substr(startIndex, count));	// ���� -> ���ڷ� ��ȯ
			cout << operand << endl;							// �ش� ���� ���
			result += operand;						// �� ����
			startIndex = exp_idx + 1;					// ���� ���� ���� �ε����� + �������� ����
		}
	}

	// 3. ����� ����ϱ�
	cout << "���ڵ��� ���� " << result << endl;

	return 0;
}

/*	[book solution]
	string s;
	cout << "7+23+5+100+25�� ���� ���� ���ڿ��� �Է��ϼ���." << endl;
	getline(cin, s, '\n'); // ���ڿ� �Է�
	int sum = 0;
	int startIndex = 0; // ���ڿ� ���� �˻��� ���� �ε���

	// ���� ���ѷ���
	while(true) {
		int fIndex = s.find('+', startIndex);			// �˻��ؾ��ϴ� �ε������� + ã��
		if(fIndex == -1) { // '+' ���� �߰��� �� ����		// ���� +�� ���� ���ٸ�
			string part = s.substr(startIndex);			// �˻��ؾ��ϴ� �ε������� ������ ���� (= ���� ���� or ����)
			if(part == "") break; // "2+3+", �� +�� ������ ���	// ���� �����̶��, �ƹ� �͵� ���� �ʱ�
			cout << part << endl;								// ������ �ƴ϶��, ���� ���
			sum += stoi(part); // ���ڿ��� ���� ��ȯ�Ͽ� ���ϱ�		// ������ ����ȭ�Ͽ� ���ϱ�
			break;												// ��������
		}
		// +�� �ִ� ���
		int count = fIndex - startIndex;				// ���ڰ��� (���꽺Ʈ������ �ڸ� ���� ����)
		string part = s.substr(startIndex, count);		// startIndex���� count ���� ���ڷ� ���꽺Ʈ�� �����
		cout << part << endl;
		sum += stoi(part);								// ���ڿ��� ���� ��ȯ�Ͽ� ���ϱ�
		startIndex = fIndex+1;							// �˻��� ������ �ε��� ������Ŵ
	}
*/