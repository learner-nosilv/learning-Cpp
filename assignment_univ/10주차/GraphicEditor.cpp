#include <iostream>
using namespace std;

#include "GraphicEditor.h"
#include "Shape.h"
#include "UI.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GraphicEditor::GraphicEditor() {	// ������
	pStart = NULL;
	pLast = NULL;
}

GraphicEditor::~GraphicEditor() { // �Ҹ���
	// ���� ������ ��� ��ü�� �����Ѵ�.
	Shape* p = pStart;				// ���� ������ -> ���۵���
	while(p != NULL) {				// ���� ������ �����Ѵٸ�,
		Shape* q = p->getNext();	// ���� ������ -> ���� ��ü��ġ�� �����Ѵ�.
		delete p;					// ���� �������� ��ü�� �����Ѵ�.
		p = q;						// ���� ������ -> ���� ��ü
	}
}

void GraphicEditor::paint() {
	// ���� ������ ��� ��ü�� �׸���.
	Shape* p = pStart;
	if(p == NULL) {									// ������ ���� ���
		UI::println("�׷��� ������ �����ϴ�.");		// ���ڿ� ��� �� ����
		return;
	}
	int i=0;
	// ó������ ������ ������ ���� �׷��� ������ �׸���.
	while(p != NULL) {								// �ݺ�: ������ �ִ� ���
		UI::print(i);		// �ε��� ���
		UI::print(": ");
		p->paint();			// ���� ���� �׸���
		p = p->getNext();	// ���� ����<-���� ����
		i++;
	}
}

void GraphicEditor::run() { // �׷��� �������� ���� �Լ�
	UI::println("�׷��� �������Դϴ�.");
	while(true) {
		int menu = UI::getMainMenu();
		switch(menu) {
			case EDIT: // ����
				edit(); break;
			case REMOVE: // ����
				remove(); break;
			case PAINT: // �ٽ� �׸���
				paint(); break;
			case EXIT: // ������
				return;
			default:
				UI::println("��� ���� ����"); // break;
		}
	}
}

void GraphicEditor::edit() {
	int shapeType = UI::getShapeType();
	switch (shapeType) {
		case 1:
			add(new Line());	break;
		case 2:
			add(new Circle());	break;
		case 3:
			add(new Rect());	break;
		default:
			UI::println("���� ���� ����");	break;
	}
}

void GraphicEditor::remove(int shapeIndex) {
	// shapeIndex�� ���Ҹ� �����Ѵ�.
	if(pLast == NULL) {			// ������ ���� ���
		UI::println("�׷��� ������ �����ϴ�.");
		return;
	}
	int i=0;
	Shape* p = pStart;			// ������ p -> ���� ��ü
	Shape* beforeP = pStart;	// ������ p���� -> ���� ��ü
	while(i<shapeIndex) {		// ��������ϴ� index�� i���� ���������� �ݺ�
		i++;					// i 1����
		beforeP = p;			// ������ p���� -> ������ p�� �� ��ü
		p = p->getNext();		// ������ p -> ���� ��ü
		if(p == NULL) {			// ���� ���� ��ü�� �����Ѿ� �� �����Ͱ� null�� ��� = shapeIndex�� ������ �������� ŭ
			UI::println("������ �ε����� �������� Ů�ϴ�.");
			return;
		}
	}

	// p�� ������ ������ ���� ������
	Shape* pNext = beforeP->add(p->getNext());		// ������ ���� ���� ������, ������ ���� ���� �̾��� �� �ش� 
	delete p;
	if(p == pStart) // ������ ������ ù ������ ���
		pStart = pNext;

	if(p == pLast) { // ������ ������ ������ ������ ���
		if(pStart == NULL) // ������ ������ ó������ �������� ���
			pLast = NULL;
		else
			pLast = beforeP;	
	}
}

void GraphicEditor::remove() {
	int shapeIndex = UI::getShapeIndex();
	remove(shapeIndex);
}

void GraphicEditor::add(Shape* p) {
	if(pStart == NULL) { // ó������ ���� ��ü�� �����Ͽ��� ��
		pStart = p;
		pLast = p;
		return;
	}
	else {
		pLast->add(p); // ���� p�� �������� �ܴ�.
		pLast = p; // pLast�� ������ �������� �����Ѵ�.
	}
}