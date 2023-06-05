/* 9-9. 8장에서 구현했던 프린터 클래스 중,
Printer 클래스의 print(int pages)와 show() 이 두 함수를 가상함수로 구현하라.

	8-8. 클래스: Printer ⊂ InkjetPrinter , LaserPrinter
* Printer: 모델명, 제조사, 인쇄 매수, 종이잔량, 프린트
* InkjetPrinter: + 잉크잔량, 프린트
* LaserPrinter: + 토너잔량, 프린트
*/
#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model;			// 모델명
	string manufacturer;	// 제조사
	int printedCount;		// 총 인쇄 매수
	int availableCount;		// 인쇄 종이 잔량

	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->printedCount = 0;
		this->availableCount = availableCount;
	}

	virtual void show() = 0;
	virtual void print(int pages) = 0;

};

class InkjetPrinter : public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
		: Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void show() {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, " << "남은 잉크 " << availableInk << endl;
	}

	void print(int pages) {
		if (availableCount < pages && availableInk < pages)
			cout << "잉크와 용지가 부족하여 프린트 할 수 없습니다." << endl;
		else if (availableCount < pages)
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		else if (availableInk < pages)
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			printedCount += pages;		// 총 인쇄 매수 증가
			availableCount -= pages;	// 종이 잔량 감소
			availableInk -= pages;		// 잉크 잔량 감소
		}
	}
};

class LaserPrinter : public Printer {
	float availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, float availableToner)
		: Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void show() {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, " << "남은 토너 " << availableToner << endl;
	}

	void print(int pages) {
		if (availableCount < pages && availableToner < pages)
			cout << "토너와 용지가 부족하여 프린트 할 수 없습니다." << endl;
		else if (availableCount < pages)
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		else if (availableToner < pages)
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			printedCount += pages;				// 총 인쇄 매수 증가
			availableCount -= pages;			// 종이 잔량 감소
			availableToner -= (float)pages / 2;	// 토너 잔량 감소
		}
	}
};

int main() {
	InkjetPrinter officejet("Officejet V40", "HP", 5, 10);
	LaserPrinter* scx = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);		// [문제요구] 하나만 동적으로 생성하여 시작한다

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	officejet.show();
	cout << "레이저 : ";
	scx->show();

	char answer;
	do {
		int printerIdx, papers;		// 선택한 프린터, 인쇄 매수
		while (true) {
			cout << '\n' << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
			cin >> printerIdx;
			cin >> papers;
			if ((printerIdx == 1 || printerIdx == 2) && papers > 0) break;
		}

		switch (printerIdx) {
			case 1:
				officejet.print(papers);
				break;
			case 2:
				scx->print(papers);
				break;
		}

		officejet.show();
		scx->show();
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> answer;
	} while (answer == 'y');

	delete scx;

	return 0;
}