#ifndef OVAL_H
#define OVAL_H

class Oval {
	int width, height;
public:
	// ������
	Oval() :width(1), height(1) {};
	Oval(int w, int h);
	// �Ҹ���: �Ҹ��� �˸��� + ������� ���(show()�Լ� ����)
	~Oval();
	// ������� ����
	int getWidth();
	int getHeight();
	// ������� ����
	void set(int w, int h);
	// ������� �ܼ����
	void show();
};
#endif
