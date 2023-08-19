/* CPU��ɾ� �ùķ��̼� & HW���� �����
* ��ɾ�ó������: fetch decode execute
* ��ɾ�: ADD SUB MUL DIV
* �ǿ�����: ����
* ����
	fetch ����: ��ɾ ����
	decode ����: ���� ��ɾ� �Է�, �������°� �ƴ� ������ �ǿ����� �Է�, �ǿ����ڰ� �ϳ� Ȥ�� ���� �Է�
	execute ����: 0���� ������ ��� 
*/
#include <iostream>
#include <string>
using namespace std;

class HardwareException {
	string step;	// ��ɾ� ó���ܰ� �� ������ �߻��� �ܰ�
	string msg;		// �����޼���
public:
	HardwareException(string step, string msg) { this->step = step; this->msg = msg; }	// ������
	void print() { cout << step << " ����, " << msg << endl; }
};

class CPU {
	string instruction;	// ����ڰ� �Է��� ���
	string command;		// ��ɾ�
	int a, b;			// �ǿ�����
	void fetch() throw(HardwareException);			// ������� ����� �о���� : ����ó��(����� ���� ���)
	void decode() throw(HardwareException);			// ������� ����� �м��ϱ� : ����ó��(���� ��ɾ �Է��� ���, �ǿ����ڰ� �ϳ� �Ǵ� ���� ���, �ǿ����ڰ� ������ �ƴ� ���)
	void execute() throw(HardwareException);		// ������� ����� �����ϱ� : ����ó��(0���� ������ ���)
public:
	void run();
	static int stringToInt(string x) throw(string);
};

void CPU::run() {
	while (true) {
		try {
			fetch();
			decode();
			execute();
		}
		catch (HardwareException a) {
			a.print();		// ���� �������
			return;			// ����
		}
	}
}
// ���ڿ�->������ȯ
int CPU::stringToInt(string x) {
	int size = x.size();		// �ڸ���
	int result = 0;				// ��ȯ���
	for (int i = 0; i < size; i++) {					// ���� : ��� �ڸ��� Ž��
		if (x[i] >= '0' && x[i] <= '9') {				// �ش� �ڸ����� ������ ���
			result = (result * 10) + (int)(x[i] - '0');	// ���ڿ�->������ȯ
		}
		else											// �ش� �ڸ����� ���ڰ� �ƴ� ���
			throw x;									// ����ó��
	}
	return result;
}

void CPU::fetch() {
	getline(cin, this->instruction, '\n');				// ������� ��� �� �� �о����
	if (instruction == "") throw HardwareException("fetch", "��� ���� ����");
}

void CPU::decode() {
	int instIdx = instruction.find(' ');				// ����� ����� �� ����� ����: ��ɾ�`|`�ǿ�����1|�ǿ�����2
	int op1Idx = instruction.find(' ', instIdx + 1);	// ����� ����� �� ����� ����: ��ɾ�|�ǿ�����1`|`�ǿ�����2

	if (instIdx == -1) {		// ���1: �� ��� : ��ɾ, �ǿ�����1�� �����ϴ� ���: ����ó�� �ʿ�
		if (instruction == "ADD" || instruction == "SUB" || instruction == "MUL" || instruction == "DIV")	// ���1-1: ��ɾ ����� �Էµ� ���
			throw HardwareException("decode", "�ǿ����� ����");
		else																								// ���1-2:��ɾ���� ����� �Էµ��� ���� ���
			throw HardwareException("decode", "invalid ��ɾ� ����");
	}
	// �� ��� or �� ���
	this->command = instruction.substr(0, instIdx);	// ù ���-> ��ɾ�
	if (this->command != "ADD" && this->command != "SUB" && this->command != "MUL" && this->command != "DIV")
		throw HardwareException("decode", "invalid ��ɾ� ����");
	// ù ����� �������� ��ɾ��� ��Ȳ & (�� ��� or �� ���)
	if (op1Idx == -1)			// ���2: �� ��� : ��ɾ� + �ǿ�����1�� �����ϴ� ���: ����ó�� �ʿ�
		throw HardwareException("decode", "�ǿ����� ����");
	// ù ����� �������� ��ɾ��� ��Ȳ & �� ���
	string op1 = this->instruction.substr(instIdx + 1, (op1Idx - instIdx - 1));
	string op2 = this->instruction.substr(op1Idx + 1);
	try {														// �ǿ����ڸ� string->int ������ ��ȯ
		this->a = stringToInt(op1);
		this->b = stringToInt(op2);
	}
	catch (string op) {
		throw HardwareException("decode", "�ǿ����� Ÿ�� ����");	// int�� ��ȯ�Ұ��� ���
	}
	// ��ɾ� | �ǿ�����1 | �ǿ�����2 �� �ؼ��Ϸ�
}

void CPU::execute() {
	if (this->command == "DIV") {
		if (this->b == 0)
			throw HardwareException("execute", "0���� ������ ����");
		else
			cout << '\t' << this->instruction << ":\t" << (this->a / this->b) << endl;
	}
	cout << '\t' << this->instruction << ":\t";
	if (this->command == "ADD")
		cout << (this->a + this->b) << endl;
	else if (this->command == "SUB")
		cout << (this->a - this->b) << endl;
	else if (this->command == "MUL")
		cout << (this->a * this->b) << endl;
}

int main() {
	CPU myCpu;
	myCpu.run();

	return 0;
}