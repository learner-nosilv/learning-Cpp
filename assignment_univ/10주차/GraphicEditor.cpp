#include <iostream>
using namespace std;

#include "GraphicEditor.h"
#include "Shape.h"
#include "UI.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GraphicEditor::GraphicEditor() {	// 생성자
	pStart = NULL;
	pLast = NULL;
}

GraphicEditor::~GraphicEditor() { // 소멸자
	// 현재 생성된 모든 객체를 삭제한다.
	Shape* p = pStart;				// 현재 포인터 -> 시작도형
	while(p != NULL) {				// 시작 도형이 존재한다면,
		Shape* q = p->getNext();	// 다음 포인터 -> 다음 객체위치를 저장한다.
		delete p;					// 현재 포인터의 객체를 삭제한다.
		p = q;						// 현재 포인터 -> 다음 객체
	}
}

void GraphicEditor::paint() {
	// 현재 생성된 모든 객체를 그린다.
	Shape* p = pStart;
	if(p == NULL) {									// 도형이 없는 경우
		UI::println("그려진 도형이 없습니다.");		// 문자열 출력 후 개행
		return;
	}
	int i=0;
	// 처음부터 끝까지 루프를 따라 그려진 도형을 그린다.
	while(p != NULL) {								// 반복: 도형이 있는 경우
		UI::print(i);		// 인덱스 출력
		UI::print(": ");
		p->paint();			// 현재 도형 그리기
		p = p->getNext();	// 현재 도형<-다음 도형
		i++;
	}
}

void GraphicEditor::run() { // 그래픽 에디터의 메인 함수
	UI::println("그래픽 에디터입니다.");
	while(true) {
		int menu = UI::getMainMenu();
		switch(menu) {
			case EDIT: // 삽입
				edit(); break;
			case REMOVE: // 삭제
				remove(); break;
			case PAINT: // 다시 그리기
				paint(); break;
			case EXIT: // 끝내기
				return;
			default:
				UI::println("명령 선택 오류"); // break;
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
			UI::println("도형 선택 오류");	break;
	}
}

void GraphicEditor::remove(int shapeIndex) {
	// shapeIndex의 원소를 삭제한다.
	if(pLast == NULL) {			// 도형이 없는 경우
		UI::println("그려진 도형이 없습니다.");
		return;
	}
	int i=0;
	Shape* p = pStart;			// 포인터 p -> 시작 객체
	Shape* beforeP = pStart;	// 포인터 p이전 -> 시작 객체
	while(i<shapeIndex) {		// 지우고자하는 index가 i보다 작을때까지 반복
		i++;					// i 1증가
		beforeP = p;			// 포이터 p이전 -> 포인터 p의 현 객체
		p = p->getNext();		// 포인터 p -> 다음 객체
		if(p == NULL) {			// 만일 현재 객체를 가리켜야 할 포인터가 null인 경우 = shapeIndex가 도형의 개수보다 큼
			UI::println("도형의 인덱스가 개수보다 큽니다.");
			return;
		}
	}

	// p는 삭제할 도형에 대한 포인터
	Shape* pNext = beforeP->add(p->getNext());		// 삭제할 도형 다음 도형을, 삭제할 도형 전과 이어준 후 해당 
	delete p;
	if(p == pStart) // 삭제한 도형이 첫 도형인 경우
		pStart = pNext;

	if(p == pLast) { // 삭제한 도형이 마지막 도형인 경우
		if(pStart == NULL) // 삭제한 도형이 처음이자 마지막인 경우
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
	if(pStart == NULL) { // 처음으로 도형 객체를 생성하였을 때
		pStart = p;
		pLast = p;
		return;
	}
	else {
		pLast->add(p); // 도형 p를 마지막에 단다.
		pLast = p; // pLast가 마지막 도형으로 조정한다.
	}
}