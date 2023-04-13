// #pragma once (��� �� Ȱ���ϱ�!)
#ifndef EXP_H
#define EXP_H

class Exp {
private:
	int base, exp;	// ��, ����

public:
	// �����ڿ� �Ҹ��ڴ� ���� INLINE & ���ӿ���
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