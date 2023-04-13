#ifndef OVAL_H
#define OVAL_H

class Oval {
	int width, height;
public:
	// 생성자
	Oval() :width(1), height(1) {};
	Oval(int w, int h);
	// 소멸자: 소멸을 알리고 + 멤버변수 출력(show()함수 재사용)
	~Oval();
	// 멤버변수 리턴
	int getWidth();
	int getHeight();
	// 멤버변수 변경
	void set(int w, int h);
	// 멤버변수 콘솔출력
	void show();
};
#endif
