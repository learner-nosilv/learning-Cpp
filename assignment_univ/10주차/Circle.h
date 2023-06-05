/*
   FILE NAME : Circle.h
   AUTHOR : -
   YYYYMMDD : 2023.05.21
   PURPOSE :
	�����ð��� ����� �Ͱ� ����,
		2. 9�� ���ǽ� ������ 1 & 2 ( ���� ���� ), 10 ���� ��
			�� �� ���α׷��� ������ ��Ʈ���� �����ϴ� ��ó�� [�׸�9-13]�� �̿��Ͽ� ������ ���� ���ϵ��� �ۼ��Ͻÿ�
				: Shape.h, Shape.cpp, Circle.h, Circle.cpp, Line.h, Line.cpp, Rect.h, Rect.cpp
			�� �׸��� ������ ��Ʈ���� �����ϴ� �ַ���� �ۼ��ϴ� �� �ʿ��� ���� ���ϵ��� ÷�ε� ���ϵ��� ����Ͻÿ�.
				�̵� ���ϵ���, ���� �Ⱓ�� ��������� ������� ���� �� �ֱ� ������, �ַ�� ���α׷��� ���ص��� ���̱� ���� �����Ǵ� ���̴�
				�� ������ ������ �м��Ͽ� �ַ�� ���α׷��� ��� �۵��ϴ� ���� �����ϵ��� �н��Ͻÿ�
				: GraphicEditor.h, GraphicEditor.cpp, UI.h, UI.cpp, Main.cpp
			�� ���� ��� ���ϵ��� ������ ������Ʈ ���Ͼȿ��� ������ ��, �������� ������ ��°���� ���� ����� �������� �����Ͻÿ�
				: ShapeGraphicEditorUI
*/

#ifndef CIRCLE
#define CIRCLE

class Circle : public Shape {
protected:
	virtual void draw();
};

#endif