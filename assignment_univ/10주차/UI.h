#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

class UI {							// 키입력과 화면출력 담당
public:
	static int getMainMenu();		// 편집기의 메뉴선택을 입력받아서 검증 후 리턴
	static int getShapeType();		// 도형의 모양선택을 입력받아서 검증 후 리턴
	static int getShapeIndex();		// 삭제할 도형의 인텍스를 입력받아서 검증 후 리턴
	static void println(string);	// 문자열 출력 후 개행	
	static void print(string);		// 문자열 출력만
	static void print(int);			// 정수 출력만
};

#endif