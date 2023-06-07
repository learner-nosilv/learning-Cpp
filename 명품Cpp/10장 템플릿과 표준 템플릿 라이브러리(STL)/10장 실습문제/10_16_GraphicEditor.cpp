#include <iostream>
#include "GraphicEditor.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GE::~GE() {
	for (int i = 0; i < v.size(); i++)
		delete v[i];
}

int GE::getAnswer(std::string menu[], int size) {
	int answer;
	for (int i = 0; i < size; i++)
		std::cout << menu[i] << ':' << i + 1 << ", ";
	std::cout << "\b\b >> ";
	while (true) {
		std::cin >> answer;
		for (int i = 1; i <= size; i++)		// ����� �� �� �Է�
			if (answer == i) return answer;
		if (std::cin.fail()) {				// ���� �Է����� ���� ����ó��
			std::cin.clear();
			std::cin.ignore(50, '\n');
		}
		std::cout << "[�Է¿���!] ";
		for (int i = 1; i <= size; i++)
			std::cout << i << ", ";
		std::cout << "\b\b �߿� �ϳ��� �Է��ϼ��� >> ";
	}
}

void GE::drawAll() {
	if (v.size() <= 0) {
		std::cout << "����ֽ��ϴ�.\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		std::cout << i << ": ";
		v[i]->paint();
	}
	return;
}

void GE::insertShape() {
	std::string shapeMenu[] = { "��", "��", "�簢��" };
	int menu = getAnswer(shapeMenu, 3);
	switch (menu) {
		case 1:
			v.push_back(new Line);
			break;
		case 2:
			v.push_back(new Circle);
			break;
		case 3:
			v.push_back(new Rect);
			break;
	}
	return;
}

void GE::removeShape() {
	if (v.size() <= 0) {
		std::cout << "����ֽ��ϴ�.\n";
		return;
	}
	int idx;
	std::cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	std::cin >> idx;
	if (idx >= 0 && idx < v.size()) {
		Shape* pTemp = v[idx];
		v.erase(v.begin() + idx);	// ���һ���
		delete pTemp;				// �����Ҵ�����
		return;
	}
	else if (std::cin.fail()) {		// ���� �Է����� ���� ����ó��
		std::cin.clear();
		std::cin.ignore(50, '\n');
	}
	std::cout << "[�Է¿���!] 0���� " << v.size() - 1 << "������ ������ �Է��ϼ���.\n";
	return;
}

void GE::run() {
	std::string editMenu[] = { "����", "����", "��κ���", "����" };
	std::cout << "�׷��� �������Դϴ�.\n";
	while (true) {
		int menu = getAnswer(editMenu, 4);
		switch (menu) {
			case 1:
				insertShape();
				break;
			case 2:
				removeShape();
				break;
			case 3:
				drawAll();
				break;
			case 4:
				return;
		}
	}
}