

#ifndef SHAPE
#define SHAPE

class Shape {				// Abstract Class
	Shape* next;			// ���� Shape ��ü�� ����Ű�� ������
protected:
	virtual void draw()=0;	// Pure virtual function
public:
	Shape() { next = NULL;}
	virtual ~Shape() { }				// Base case�� �� Abstract class�� �Ҹ��ڸ� �����Լ��� �����ϴ°� ����
	void paint();						// �׸��� : �������̵��� �����ϰ� �ϱ����� �Լ�
	Shape* add(Shape* p);				// �����ϱ� : �Ķ���ͷ� ���� Shape��ü�� �� ��ü�� �����ϰ�, �ּҰ� ���� 
	Shape* getNext() { return next;}	// �� ��ü�� ���� ��ü �ּҰ� ����
};

#endif