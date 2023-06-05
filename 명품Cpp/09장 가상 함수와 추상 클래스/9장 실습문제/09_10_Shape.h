#ifndef SHAPE_H
#define SHAPE_H

class Shape {
	Shape* next;	// ����Shape�� ����Ʈ
protected:
	virtual void draw() = 0;	// [Pure Virtual Function] �׸���
public:
	Shape() { next = nullptr; }
	virtual ~Shape() {}			// �Ҹ���
	void paint() { draw(); }				// �׸���: ���������Լ� ���
	Shape* add(Shape* p) {					// �� ������ �ٸ� ���� ����
		this->next = p;						// ���(������) = ���� ������ ����Ű�� ������
		return p;							// �ش� ������ ����
	}
	Shape* getNext() { return this->next; }	// ���� ������ ����Ű�� ������(���) ����
};

#endif // ! SHAPE_H