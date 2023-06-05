#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

class Shape;										// 전방선언

class GraphicEditor {
	enum { LINE = 1, CIRCLE = 2, RECT = 3 };				// 도형의 모양선택 : 사용자 정의 자료형 중 열거형
	enum { EDIT = 1, REMOVE = 2, PAINT = 3, EXIT = 4 };		// 편집기의 메뉴선택 : 사용자 정의 자료형 중 열거형
	Shape* pStart;									// 시작 도형을 가리키는 포인터
	Shape* pLast;									// 마지막 도형을 가리키는 포인터
	void add(Shape* p);								// 현 리스트에 새로운 도형 추가
protected:
	void paint();						// 현재 생성된 모든 객체를 그린다.
	void edit();						// 도형 선택
	void remove(int shapeIndex);		// 도형 리스트에서 해당 인덱스의 원소 삭제
	void remove();						// 도형 리스트에서 삭제하고 싶은 도형의 인덱스를 입력받은 후 삭제
public:
	GraphicEditor();	// 생성자
	~GraphicEditor();	// 소멸자
	void run();			// 그래픽 에디터 실행
};

#endif;