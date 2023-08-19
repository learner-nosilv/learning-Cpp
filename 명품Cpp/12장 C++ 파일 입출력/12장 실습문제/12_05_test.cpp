#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("ShowNoComment.cpp");
	if(!fin) {
		cout <<"ShowNoComment.cpp ���� ����";
		return 0;
	}
	int ch;
	bool found=false;
	while((ch=fin.get()) != EOF) {
		if(ch == '/') {
			if(found == false) 
				found = true; 
			else { 
				fin.ignore(100,'\n'); 
				cout.put('\n');
				found = false; 
			}
		}
		else {
			if(found == true) { 
				cout << "/"; 
				found = false; 
			}
			cout.put(ch);
		}
	}

	fin.close();
}
