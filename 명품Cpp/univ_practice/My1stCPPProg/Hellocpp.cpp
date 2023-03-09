/* 2023.03.09 객체지향프로그래밍 수업 - B111064 김혜민
	교재: 02. C++ 프로그래밍의 기본
			2.1 C++ 프로그램의 기본요소와 화면출력 (54p~)
*/ 

// 1. 주석COMMENT: //□□□... , /* □□□... */꼭 붙이자

#include<iostream>
// 2. 헤더파일 iostream:표준 입출력을 위한 클래스/객체/변수 선언됨(ios, istream, ostream, iostream 클래스, 
	/*
	내용
	#pragma once
	#ifndef _IOSTREAM_
	#define _IOSTREAM_
	#include <yvals_core.h>
	#if _STL_COMPILER_PREPROCESSOR
	#include <istream>
	..
	#pragma warning(pop)
	#pragma pack(pop)
	#endif // _STL_COMPILER_PREPROCESSOR
	#endif // _IOSTREAM_

	*/
int main(void) {			// 입력 Data Type void / 출력-int MAIN 함수의 리턴값은 OS가 받는다
	std::cout << "Hello";
	return 0;
}

//