#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::paint() {			// 그리기 : 오버라이딩을 가능하게 하기위한 함수
	draw();						// Pure virtual function
}

Shape* Shape::add(Shape *p) {	// linked-list: 현 Shape객체가 가리키는 다음 Shape객체 설정 & 다음 Shape객체의 주소값 리턴
	this->next = p;				// Shape객체의 멤버변수인 포인터(next)가 가리키는 객체를 해당 함수의 파라미터인 Shape객체로 설정 
	return p;					// 파라미터인 Shape객체 주소 리턴
}