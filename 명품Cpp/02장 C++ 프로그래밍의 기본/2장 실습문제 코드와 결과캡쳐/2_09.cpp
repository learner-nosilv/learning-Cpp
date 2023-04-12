/*
* 이름, 주소, 나이를 입력받아 출력하는 프로그램
* 계속 c-string 을 사용했으니,
* 이번엔 문자열의 입출력에 string객체와 getline(cin,문자열)을 이용할 것
* 따라서, <string> 필요
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string name, address, age;

	//1. 공백을 표함하는 문자열 입력받기 (길이초과는 고려하지 않음)
	cout << "이름은?";
	getline(cin, name);

	cout << "주소는?";
	getline(cin, address);

	cout << "나이는?";
	getline(cin, age);

	//2. 다시 출력하기
	cout << name << ", " << address << ", " << age << "세" << endl;

	return 0;
}