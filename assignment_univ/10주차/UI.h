#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

class UI {							// Ű�Է°� ȭ����� ���
public:
	static int getMainMenu();		// �������� �޴������� �Է¹޾Ƽ� ���� �� ����
	static int getShapeType();		// ������ ��缱���� �Է¹޾Ƽ� ���� �� ����
	static int getShapeIndex();		// ������ ������ ���ؽ��� �Է¹޾Ƽ� ���� �� ����
	static void println(string);	// ���ڿ� ��� �� ����	
	static void print(string);		// ���ڿ� ��¸�
	static void print(int);			// ���� ��¸�
};

#endif