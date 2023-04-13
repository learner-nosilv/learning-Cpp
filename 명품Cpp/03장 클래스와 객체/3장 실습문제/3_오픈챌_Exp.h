// #pragma once (배운 것 활용하기!)
#ifndef EXP_H
#define EXP_H

class Exp {
private:
	int base, exp;	// 밑, 지수

public:
	// 생성자와 소멸자는 전부 INLINE & 위임연산
	Exp(int b, int e) :base(b), exp(e) {};
	Exp(int b) :Exp(b, 1) {};
	Exp() :Exp(1, 1) {};
	~Exp() {};

	int getBase() { return base; }	// Inline
	int getExp() { return exp; }	// Inline
	int getValue();					// Implementation -> .cpp
	bool equals(Exp n);				// Implementation -> .cpp
};

#endif