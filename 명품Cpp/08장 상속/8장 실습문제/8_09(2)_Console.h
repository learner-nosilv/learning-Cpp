#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
using namespace std;

class Console {						// �Է�����
public:
	static int chooseMenu();		// �޴� �Է¹ޱ�
	static int chooseTime();		// ����� �Է¹ޱ�
	static int chooseSeat();		// �ڸ� �Է¹ޱ�
	static string chooseName();		// �̸� �Է¹ޱ� 
};

#endif // !CONSOLE_H

