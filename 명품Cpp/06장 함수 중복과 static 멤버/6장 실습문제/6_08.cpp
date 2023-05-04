/* 8. ����뿡 �ʿ��� ������ �����ϴ� Trace Ŭ���� �����
* ���ڴ�, ���� ���� ������ �����ϱ� ���� Trace Ŭ������ ����� ����Ͽ���.
* TraceŬ������ Ȱ���� ���� ���α׷��� ����� �����Ͽ�
* Trace Ŭ������ ��ü ���α׷��� �ϼ��϶�
* * ���� * ����� ������ 100���� ����
*
* Trace Ŭ����
* ���1. field�� (tag, content)�� 2���� �迭
* ���2. 2���� �迭�� �� index�� �����ϴ� int�� ����
*/

#include <iostream>
#include <string>
using namespace std;

class Trace {
	static string tag_content[100][2];	// FIELD (tag:content)�� 100���� �迭
	static int empty;
public:
	static void put(string tag, string content);
	static void printf(string tag);
};

// TraceŬ������ static ��� Definition
string Trace::tag_content[100][2];
int Trace::empty = 0;

void Trace::put(string tag, string content) {
	if (Trace::empty >= 100)	// ������ �� �� ���
		cout << "����� �������� 100���� �ʰ��Ͽ� �� �̻� ������ �� �����ϴ�." << endl;

	else {						// content �Ҵ�
		Trace::tag_content[Traace::empty][0] = tag;
		Trace::tag_content[Trace::empty][1] = content;
		Trace::empty++;
	}
}

void Trace::printf(string tag = "���") {
	if (tag == "���") {
		cout << "----- " << tag << " Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < empty; i++)
			cout << Trace::tag_content[i][0] << ':' << Trace::tag_content[i][1] << endl;
	}
	else {
		cout << "----- " << tag << "�±��� Trace ������ ����մϴ�. -----" << endl;
		for (int i = 0; i < empty; i++) {
			if (Trace::tag_content[i][0] == tag)
				cout << Trace::tag_content[i][0] << ':' << Trace::tag_content[i][1] << endl;
		}
	}
}

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");	// �±�, ����� ���� ����
	c = a + b;
	Trace::put("f()", "�� ���");			// �±�, ����� ���� ����
	cout << "���� " << c << endl;
}

int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::printf("f()");		// "f()"�±��� ����� ���� ��� ���
	Trace::printf();			// ��� ����� ���� ��� ���

	return 0;
}