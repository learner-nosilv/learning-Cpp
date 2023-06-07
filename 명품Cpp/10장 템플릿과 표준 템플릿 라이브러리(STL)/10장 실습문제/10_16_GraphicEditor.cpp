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
		for (int i = 1; i <= size; i++)		// 제대로 된 답 입력
			if (answer == i) return answer;
		if (std::cin.fail()) {				// 문자 입력으로 인한 오류처리
			std::cin.clear();
			std::cin.ignore(50, '\n');
		}
		std::cout << "[입력오류!] ";
		for (int i = 1; i <= size; i++)
			std::cout << i << ", ";
		std::cout << "\b\b 중에 하나를 입력하세요 >> ";
	}
}

void GE::drawAll() {
	if (v.size() <= 0) {
		std::cout << "비어있습니다.\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		std::cout << i << ": ";
		v[i]->paint();
	}
	return;
}

void GE::insertShape() {
	std::string shapeMenu[] = { "선", "원", "사각형" };
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
		std::cout << "비어있습니다.\n";
		return;
	}
	int idx;
	std::cout << "삭제하고자 하는 도형의 인덱스 >> ";
	std::cin >> idx;
	if (idx >= 0 && idx < v.size()) {
		Shape* pTemp = v[idx];
		v.erase(v.begin() + idx);	// 원소삭제
		delete pTemp;				// 동적할당해제
		return;
	}
	else if (std::cin.fail()) {		// 문자 입력으로 인한 오류처리
		std::cin.clear();
		std::cin.ignore(50, '\n');
	}
	std::cout << "[입력오류!] 0부터 " << v.size() - 1 << "까지의 정수를 입력하세요.\n";
	return;
}

void GE::run() {
	std::string editMenu[] = { "삽입", "삭제", "모두보기", "종료" };
	std::cout << "그래픽 에디터입니다.\n";
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