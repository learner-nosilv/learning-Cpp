/* openchallenge.
* 4�� �ǽ����� 13���� Histogram Ŭ���� �ַ���ڵ带
* �� ������ main()�� ȣȯ�ǵ��� �����ϱ�
* 
*  * �� �ڵ���ϸ� �̹� �ڵ带 �ʹ� �� �˰������ϱ�,
*	�Ϻη� ������ �ַ�� �ڵ带 �����غ���� ��
*/

#include <iostream>
#include <string>
using namespace std;

// class Declaration
class Histogram {
	string text;
	int histo[26] = { 0, }; // [26���� ���ĺ�]�� ���� �� ���ڴ� ���� ����
public:
	Histogram(string text);				// ������: ������׷����� �м��� ���ڿ� ����
	Histogram& operator<<(string text);	// ���ڸ� ���text�� concat�� ��ü ��������
	Histogram& operator<<(char c);		// ���ڸ� ���text�� concat�� ��ü ��������
	void operator!();					// ��ü�� ���text �ܼ����
	~Histogram() {}						// 
};

// class Implementation
Histogram::Histogram(string text = "") {
	this->text = text;
}

Histogram& Histogram::operator<<(string text) {	// ��ü.<<(����)
	this->text.append(text);		// this->text += text; �� ����
	return *(this);					// ��ü�ڽ� ��������
}
Histogram& Histogram::operator<<(char c) {
	char buf[] = { c, '\0' };		// ����c�� c-string ��Ÿ���� ���ڿ��� ��ȯ
	this->text.append(buf);			// this->text += text; �� ����
	return *(this);					// ��ü�ڽ� ��������
}

void Histogram::operator!(){

	cout << this->text << endl << endl;	// text ���� ���

	for (int i = 0; i < (this->text).length(); i++) {
		if (isalpha((this->text)[i])) {			// ���ĺ��� ���ؼ��� ó��
			char c = tolower((this->text)[i]);	// ���ĺ��� �ҹ������� ascii�ڵ尪 �ľ�
			this->histo[c - 'a']++;			// n��° ���ĺ��̸� n��° ���Ұ� 1����
		}
	}

	int n = 0;
	for (int i = 0; i < 26; i++) n += this->histo[i]; // ��ü ���ĺ� �� ���ϱ�
	cout << "�� ���ĺ� �� " << n << endl;
	cout << endl;

	for (int i = 0; i < 26; i++) {				// �� ���ĺ��� ��* ���
		cout << char('a' + i) << " (" << this->histo[i] << ")" << '\t' << ": ";
		for (int j = 0; j < this->histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}

int main() {
	Histogram song("Wise men say, only fools rush in But I can't help, \n");	// ������
	song << "falling" << " in love with you" << " - by ";	// <<������ �����ε�: bit shift -> add (���ڿ�)
	song << 'k' << 'i' << 't';								// <<������ �����ε�: bit shift -> add (���� = �Լ� �����ε�)
	!song;													// !������ �����ε�: ��not-> ������׷� �ܼ����
}