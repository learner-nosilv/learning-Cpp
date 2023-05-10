#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string sentence;
public:
	Histogram(string n) { sentence = n; }
	Histogram& operator<<(string n) { 
		this->sentence += n;
		return *this;
	}
	Histogram& operator<<(char n) {
		this->sentence += n;
		return *this;
	}
	void operator!();
};

void Histogram::operator!() {
	cout << this->sentence << endl << endl;			// sentence ÇÑ ¹ø Ãâ·Â

	int size = this->sentence.size();
	int* alpha = new int[27]{ 0, };		// alpha[0]: aÀÇ °¹¼ö, alpha[25]: zÀÇ °¹¼ö, alpha[26]: ÃÑ °¹¼ö

	for (int i = 0; i < size; i++) {
		if (sentence[i] >= 'a' && sentence[i] <= 'z') {
			alpha[sentence[i] - 'a']++;
			alpha[26]++;
		}
		else if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			alpha[sentence[i] - 'A']++;
			alpha[26]++;
		}
	}

	cout << "ÃÑ ¾ËÆÄºª ¼ö " << alpha[26] << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 'a') << ':';
		for (int star = 0; star < alpha[i]; star++)
			cout << '*';
		cout << endl;
	}
}

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by ";
	song << 'k' << 'i' << 't';
	!song;

	return 0;
}