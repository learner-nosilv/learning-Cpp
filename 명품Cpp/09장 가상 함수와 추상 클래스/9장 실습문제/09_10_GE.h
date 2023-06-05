#ifndef GE_H
#define GE_H
#include <iostream>
#include "09_10_Shape.h"
#include "09_10_Circle.h"
#include "09_10_Line.h"
#include "09_10_Rect.h"
#include "09_10_UI.h"

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;

	void insert();		// 1. �� �ڿ� ��� ����
	void remove();		// 2. ������ idx�� ��� ����
	void paint();		// 3. ���� �׸���

	bool addShape(Shape* a, int idx = -1);
	bool rmvShape(int idx = -1);

public:
	GraphicEditor() { pStart = pLast = nullptr; }
	~GraphicEditor();
	void start();
};
#endif // !GE_H