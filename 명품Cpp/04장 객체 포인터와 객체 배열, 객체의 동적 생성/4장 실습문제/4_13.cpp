/* 13.
* �����ڷ� ������ �ؽ�Ʈ�� ���� �� ���ĺ��� �ش��ϴ� ���ڰ� �� ������ ����ϴ� ������׷� Ŭ����
* �빮��, �ҹ��� ���о��� ī��Ʈ
* 
* �����Լ��� �������� ���� Ŭ������ �ۼ�����
*/

#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string sentence;
	int size = 0;
	int count[27] = { 0, };				// [0-25]���� a(65 97)~z(90 122)�� ����, [26] total
	void counter(string s);
	void counter(char c);
	
public:
	Histogram(string s) {
		sentence = s;
		size = s.size();
		counter(s);
	}
	void put(string s);
	void putc(char c);
	void print();
};

void Histogram::counter(string s) {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			count[(s[i] - 'a')]++;	// a�̸� counter[0]++
			count[26]++;					// �� ���ĺ� ��
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			count[(s[i] - 'A')]++;	// A�̸� counter[0]++
			count[26]++;					// �� ���ĺ� ��
		}
	}
}

void Histogram::counter(char c) {
	if (c >= 'a' && c <= 'z') {
		count[(c - 'a')]++;				// a�̸� counter[0]++
		count[26]++;					// �� ���ĺ� ��
	}
	else if (c >= 'A' && c <= 'Z') {
		count[(c - 'A')]++;				// A�̸� counter[0]++
		count[26]++;					// �� ���ĺ� ��
	}
}

void Histogram::put(string s) {
	sentence.append(s);
	size += s.size();
	counter(s);
}

void Histogram::putc(char c) {
	sentence = sentence + c;	// [�ַ��] char buf[] = {c, '\0'}; this->text.append(buf);
	size++;
	counter(c);
}

void Histogram::print() {
	cout << sentence << endl << endl;
	cout << "�� ���ĺ� �� " << count[26] << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 65) << " (" << count[i] << ") \t: ";
		for (int star = 0; star < count[i]; star++) {
			cout << '*';
		}
		cout << endl;
	}
}


int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

	return 0;
}