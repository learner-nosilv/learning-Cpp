#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

class Shape;										// ���漱��

class GraphicEditor {
	enum { LINE = 1, CIRCLE = 2, RECT = 3 };				// ������ ��缱�� : ����� ���� �ڷ��� �� ������
	enum { EDIT = 1, REMOVE = 2, PAINT = 3, EXIT = 4 };		// �������� �޴����� : ����� ���� �ڷ��� �� ������
	Shape* pStart;									// ���� ������ ����Ű�� ������
	Shape* pLast;									// ������ ������ ����Ű�� ������
	void add(Shape* p);								// �� ����Ʈ�� ���ο� ���� �߰�
protected:
	void paint();						// ���� ������ ��� ��ü�� �׸���.
	void edit();						// ���� ����
	void remove(int shapeIndex);		// ���� ����Ʈ���� �ش� �ε����� ���� ����
	void remove();						// ���� ����Ʈ���� �����ϰ� ���� ������ �ε����� �Է¹��� �� ����
public:
	GraphicEditor();	// ������
	~GraphicEditor();	// �Ҹ���
	void run();			// �׷��� ������ ����
};

#endif;