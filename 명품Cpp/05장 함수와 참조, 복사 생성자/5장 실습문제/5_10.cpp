/* 10.
* �������� �ڵ� �ۼ��ϱ�
* append() �Լ��� �ۼ��ϱ� : Buffer ��ü�� ���ڿ��� �߰��ϰ� �ش� ��ü�� ��������
*/

#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { this->text += next; }
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& buffer, string word) {
	buffer.add(word);
	return buffer;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");	// buf�� �����ϰ� temp��� alias ���� (temp�� �� buf : ���� ��ü)
	temp.print();
	buf.print();
	return 0;
}