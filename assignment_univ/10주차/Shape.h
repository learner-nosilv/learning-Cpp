

#ifndef SHAPE
#define SHAPE

class Shape {				// Abstract Class
	Shape* next;			// 다음 Shape 객체를 가리키는 포인터
protected:
	virtual void draw()=0;	// Pure virtual function
public:
	Shape() { next = NULL;}
	virtual ~Shape() { }				// Base case가 될 Abstract class는 소멸자를 가상함수로 구현하는게 좋다
	void paint();						// 그리기 : 오버라이딩을 가능하게 하기위한 함수
	Shape* add(Shape* p);				// 연결하기 : 파라미터로 들어온 Shape객체를 현 객체와 연결하고, 주소값 리턴 
	Shape* getNext() { return next;}	// 현 객체의 다음 객체 주소값 리턴
};

#endif