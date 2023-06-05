/*
   FILE NAME : UI.cpp
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


#include <iostream>
using namespace std;

#include "UI.h"

int UI::getMainMenu() {
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";

	int menu;
	cin >> menu;

	return menu;
}

int UI::getShapeType() {
	cout << "��:1, ��:2, �簢��:3 >> ";

	int shapeType;
	cin >> shapeType;

	return shapeType;
}

int UI::getShapeIndex() {
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";

	int shapeIndex;
	cin >> shapeIndex;

	return shapeIndex;
}

void UI::println(string msg) {
	cout << msg << endl;		// ���ڿ� ��� �� ����
}

void UI::print(string msg) {
	cout << msg;				// ���ڿ� ��¸�
}

void UI::print(int msg) {
	cout << msg;				// ���� ��¸�
}