#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
using namespace std;

class Console {						// 입력전담
public:
	static int chooseMenu();		// 메뉴 입력받기
	static int chooseTime();		// 비행기 입력받기
	static int chooseSeat();		// 자리 입력받기
	static string chooseName();		// 이름 입력받기 
};

#endif // !CONSOLE_H

