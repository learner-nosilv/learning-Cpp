#include "09_10_GE.h"

GraphicEditor::~GraphicEditor(){
	Shape* past = pStart;
	while (past != nullptr) {
		Shape* now = past->getNext();
		delete past;
		past = now;
	}
}

void GraphicEditor::insert() {							// 1. ����
	int shape = UI::getShape();						//	1) �����Է�
	switch (shape) {								//  2) ��������
		case 1: addShape(new Line()); break;
		case 2: addShape(new Circle()); break;
		case 3: addShape(new Rect()); break;
	}
}
void GraphicEditor::remove() {
	int idx = UI::getIdx();
	rmvShape(idx);
}

void GraphicEditor::paint() {		// 3. ���� �׸���
	Shape* now = pStart;			// ������ ����� ������ ������
	int i = 0;
	while ( now != nullptr) {		// ����� ������ ��������,
		std::cout << i << ": ";
		now->paint();
		now = now->getNext();
		i++;
	}
}
bool GraphicEditor::addShape(Shape* a, int idx) {	// [idx] �ڸ��� �տ� �ְ�, ���� ��ü�� �ڷ�
	if (idx == -1) {			// ���1. [default] �� �ڿ� �߰�
		if (pLast == nullptr)	//	�� ����Ʈ
			pStart = pLast = a;
		else {					//	���� ���� ����Ʈ
			pLast->add(a);
			pLast = a;
		}
		return true;
	}
	if (idx == 0) {				// ���2. �� ��(0��° ���)�� �߰�
		if (pStart = nullptr)	//	�� ����Ʈ
			pStart = pLast = a;
		else {					//	�������� ����Ʈ
			a->add(pStart);		//		a ��忡 �� ����Ʈ ����
			pStart = a;			//		���۳�带 a ���� �缳��
		}
		return true;
	}
	if (pStart == nullptr && idx != 0) {	// ���3. �� ����Ʈ�� �� ��/�ڰ� �ƴ� �� �߰��� �䱸
		std::cout << "[����] �� ����Ʈ�̹Ƿ� " << idx << "��° ���� �����ϴ�." << std::endl;
		return false;
	}

	// ���� ����� �� : �������� ����Ʈ + �߰� or �� �� or �ʰ�
	Shape* pNow = pStart;
	Shape* pPast = nullptr;
	for (int i = 0; i < idx; i++) {
		if ((pNow) == nullptr) {			// ���4. �Է��� �ε����� ����Ʈ�� �ʰ��ϴ� ���
			std::cout << "[����] �ش� ����Ʈ�� �� ��� ������ " << idx << "������ �����ϴ�." << std::endl;
			return false;
		}
		else {
			pPast = pNow;
			pNow = pNow->getNext();
		}
	}
	// �� ���� : �������� ��� + �߰�(pNow!=nullptr) or �� ��(pNow==nullptr)
	if (pNow == nullptr) {		// ���5. �����µ� �� �ڿ� �߰� [default]�� ����
		pLast->add(a);
		pLast = a;
	}
	else {						// ���6. [���� �Ϲ���] �������� ����Ʈ�� �� ��/�ڰ� �ƴ� �߰��� �߰�
		pPast->add(a);			// �� ����Ʈ�� a ��� ����
		a->add(pNow);			// a ��忡 �� ����Ʈ ����
	}
	return true;
}
bool GraphicEditor::rmvShape(int idx) {					// idx[0-]° ������
	if (pStart == nullptr) {							// ���1. �� ����Ʈ
		std::cout << "[����] �� ����Ʈ�̹Ƿ� ������ �� �����ϴ�." << std::endl;
		return false;
	}
	if (pStart == pLast && (idx == -1 || idx == 0)) {	// ���2. ��尡 �� ���� ����Ʈ���� �� �ϳ��� ����
		delete pStart;
		pStart = pLast = nullptr;
		return true;
	}
	if (idx == 0) {								// ���2. ���� ���� ����Ʈ + �� �� ��� ����
		Shape* pNext = pStart->getNext();		//	������ ����� ���� ���(��尡 �� ���� ����Ʈ�̸� nullptr)
		delete pStart;							//	��� ����
		pStart = pNext;							//	�� ���� ���� ��带 ���۳��� ����
		if (pStart == nullptr) pLast = nullptr;	//	�� ����Ʈ���, ����嵵 nullptr�� ����
		return true;
	}
	// ���� ����� �� : ���� ���� ����Ʈ + �߰� or �� ��(idx�����Է� or -1�Է�) or �ʰ�
	Shape* pPast = nullptr;		// ���� ����� �� ���
	Shape* pNow = pStart;		// ���� ���
	for (int i = 0; i < idx; i++) {				//	������� ���� �� �� ��� ã��
		if (pNow == pLast) {					// ���3. ���� ���� ����Ʈ + idx�� �ʰ��Է�
			std::cout << "[����] �ش� ����Ʈ�� �� ��� ������ " << (idx + 1) << "������ �����ϴ�." << std::endl;
			return false;
		}
		pPast = pNow;
		pNow = pNow->getNext();
		if (pNow==pLast && idx == -1)	break;	// (�� �� ��带 �߰��߰�, [default] �� �� ��带 ������ �ϴ� ���)
	}
	// ���� ����� �� : ���� ���� ����Ʈ + �߰� or �� ��
	Shape* pNext = pNow->getNext();	// �������ϴ� ��尡 �������̶�� nullptr
	if (pStart == pLast) {			// ��� 4. ��尡 �� ���� ����Ʈ���� ���� ��带 ������ �ϴ� ���	
		delete pNow;
		pStart = pLast = nullptr;
		return true;
	}
	// ���� ����� �� : ��尡 2�� �̻��� ���� ���� ����Ʈ�� �߰� or �� �� ����
	delete pNow;					// ��� ����
	pPast->add(pNext);				// �� ��� - �� ����Ʈ ����
	if (pNext == nullptr)			// ��尡 (�˰���) �� �� ���
		pLast = pPast;				// ������ ���� ����
	return true;
}

void GraphicEditor::start() {
	std::cout << "�׷��� �������Դϴ�." << std::endl;
	while (true) {
		int menu = UI::getMenu();
		switch (menu) {
			case 1:							// 1. ����
				insert();	break;
			case 2:							// 2. [n]���� ����
				remove();	break;
			case 3:							// 3. ��κ���
				paint();	break;
			case 4:							// 4. ����
				return;
		}
	}
}