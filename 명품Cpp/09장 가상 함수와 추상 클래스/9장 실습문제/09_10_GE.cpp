#include "09_10_GE.h"

GraphicEditor::~GraphicEditor(){
	Shape* past = pStart;
	while (past != nullptr) {
		Shape* now = past->getNext();
		delete past;
		past = now;
	}
}

void GraphicEditor::insert() {							// 1. 삽입
	int shape = UI::getShape();						//	1) 도형입력
	switch (shape) {								//  2) 도형연결
		case 1: addShape(new Line()); break;
		case 2: addShape(new Circle()); break;
		case 3: addShape(new Rect()); break;
	}
}
void GraphicEditor::remove() {
	int idx = UI::getIdx();
	rmvShape(idx);
}

void GraphicEditor::paint() {		// 3. 전부 그리기
	Shape* now = pStart;			// 앞으로 출력할 도형의 포인터
	int i = 0;
	while ( now != nullptr) {		// 출력할 도형이 있을때만,
		std::cout << i << ": ";
		now->paint();
		now = now->getNext();
		i++;
	}
}
bool GraphicEditor::addShape(Shape* a, int idx) {	// [idx] 자리의 앞에 넣고, 기존 객체는 뒤로
	if (idx == -1) {			// 경우1. [default] 맨 뒤에 추가
		if (pLast == nullptr)	//	빈 리스트
			pStart = pLast = a;
		else {					//	비지 않은 리스트
			pLast->add(a);
			pLast = a;
		}
		return true;
	}
	if (idx == 0) {				// 경우2. 맨 앞(0번째 노드)에 추가
		if (pStart = nullptr)	//	빈 리스트
			pStart = pLast = a;
		else {					//	비지않은 리스트
			a->add(pStart);		//		a 노드에 뒤 리스트 연결
			pStart = a;			//		시작노드를 a 노드로 재설정
		}
		return true;
	}
	if (pStart == nullptr && idx != 0) {	// 경우3. 빈 리스트에 맨 앞/뒤가 아닌 곳 추가를 요구
		std::cout << "[오류] 빈 리스트이므로 " << idx << "번째 노드는 없습니다." << std::endl;
		return false;
	}

	// 남은 경우의 수 : 비지않은 리스트 + 중간 or 맨 뒤 or 초과
	Shape* pNow = pStart;
	Shape* pPast = nullptr;
	for (int i = 0; i < idx; i++) {
		if ((pNow) == nullptr) {			// 경우4. 입력한 인덱스가 리스트를 초과하는 경우
			std::cout << "[오류] 해당 리스트의 총 노드 갯수는 " << idx << "개보다 적습니다." << std::endl;
			return false;
		}
		else {
			pPast = pNow;
			pNow = pNow->getNext();
		}
	}
	// 현 상태 : 비지않은 노드 + 중간(pNow!=nullptr) or 맨 뒤(pNow==nullptr)
	if (pNow == nullptr) {		// 경우5. 몰랐는데 맨 뒤에 추가 [default]와 동일
		pLast->add(a);
		pLast = a;
	}
	else {						// 경우6. [가장 일반적] 비지않은 리스트의 맨 앞/뒤가 아닌 중간에 추가
		pPast->add(a);			// 앞 리스트에 a 노드 연결
		a->add(pNow);			// a 노드에 뒤 리스트 연결
	}
	return true;
}
bool GraphicEditor::rmvShape(int idx) {					// idx[0-]째 노드삭제
	if (pStart == nullptr) {							// 경우1. 빈 리스트
		std::cout << "[오류] 빈 리스트이므로 삭제할 수 없습니다." << std::endl;
		return false;
	}
	if (pStart == pLast && (idx == -1 || idx == 0)) {	// 경우2. 노드가 한 개인 리스트에서 그 하나를 삭제
		delete pStart;
		pStart = pLast = nullptr;
		return true;
	}
	if (idx == 0) {								// 경우2. 비지 않은 리스트 + 맨 앞 노드 삭제
		Shape* pNext = pStart->getNext();		//	삭제할 노드의 다음 노드(노드가 한 개인 리스트이면 nullptr)
		delete pStart;							//	노드 삭제
		pStart = pNext;							//	맨 앞의 다음 노드를 시작노드로 설정
		if (pStart == nullptr) pLast = nullptr;	//	빈 리스트라면, 끝노드도 nullptr로 설정
		return true;
	}
	// 남은 경우의 수 : 비지 않은 리스트 + 중간 or 맨 뒤(idx직접입력 or -1입력) or 초과
	Shape* pPast = nullptr;		// 지울 노드의 전 노드
	Shape* pNow = pStart;		// 지울 노드
	for (int i = 0; i < idx; i++) {				//	지우려는 노드와 그 전 노드 찾기
		if (pNow == pLast) {					// 경우3. 비지 않은 리스트 + idx의 초과입력
			std::cout << "[오류] 해당 리스트의 총 노드 갯수는 " << (idx + 1) << "개보다 적습니다." << std::endl;
			return false;
		}
		pPast = pNow;
		pNow = pNow->getNext();
		if (pNow==pLast && idx == -1)	break;	// (맨 뒤 노드를 발견했고, [default] 맨 뒤 노드를 지워야 하는 경우)
	}
	// 남은 경우의 수 : 비지 않은 리스트 + 중간 or 맨 뒤
	Shape* pNext = pNow->getNext();	// 지워야하는 노드가 마지막이라면 nullptr
	if (pStart == pLast) {			// 경우 4. 노드가 한 개인 리스트에서 남은 노드를 지워야 하는 경우	
		delete pNow;
		pStart = pLast = nullptr;
		return true;
	}
	// 남은 경우의 수 : 노드가 2개 이상인 비지 않은 리스트의 중간 or 맨 뒤 삭제
	delete pNow;					// 노드 삭제
	pPast->add(pNext);				// 앞 노드 - 뒤 리스트 연결
	if (pNext == nullptr)			// 노드가 (알고보니) 맨 뒤 노드
		pLast = pPast;				// 마지막 노드로 설정
	return true;
}

void GraphicEditor::start() {
	std::cout << "그래픽 에디터입니다." << std::endl;
	while (true) {
		int menu = UI::getMenu();
		switch (menu) {
			case 1:							// 1. 삽입
				insert();	break;
			case 2:							// 2. [n]도형 삭제
				remove();	break;
			case 3:							// 3. 모두보기
				paint();	break;
			case 4:							// 4. 종료
				return;
		}
	}
}