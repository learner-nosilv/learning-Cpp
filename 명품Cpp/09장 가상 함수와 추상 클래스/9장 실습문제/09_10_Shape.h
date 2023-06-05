#ifndef SHAPE_H
#define SHAPE_H

class Shape {
	Shape* next;	// 다음Shape를 포인트
protected:
	virtual void draw() = 0;	// [Pure Virtual Function] 그리기
public:
	Shape() { next = nullptr; }
	virtual ~Shape() {}			// 소멸자
	void paint() { draw(); }				// 그리기: 순수가상함수 사용
	Shape* add(Shape* p) {					// 현 도형에 다른 도형 연결
		this->next = p;						// 멤버(포인터) = 다음 도형을 가리키는 포인터
		return p;							// 해당 포인터 리턴
	}
	Shape* getNext() { return this->next; }	// 다음 도형을 가리키는 포인터(멤버) 리턴
};

#endif // ! SHAPE_H