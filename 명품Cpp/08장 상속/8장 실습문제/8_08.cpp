/* 8. 클래스: Printer ⊂ InkjetPrinter , LaserPrinter
* Printer: 모델명, 제조사, 인쇄 매수, 종이잔량, 프린트
* InkjetPrinter: + 잉크잔량, 프린트
* LaserPrinter: + 토너잔량, 프린트
*/
#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;			// 모델명
	string manufacturer;	// 제조사
	int printedCount;		// 총 인쇄 매수
	int availableCount;		// 인쇄 종이 잔량
protected:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->printedCount = 0;
		this->availableCount = availableCount;
	}
	void printerStatus() { cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, "; }
	bool printablePage(int pages) {
		if (availableCount < pages) {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			return false;
		}
		else return true;
	}
	void printPage(int pages) {
		printedCount += pages;		// 총 인쇄 매수
		availableCount -= pages;	// 인쇄 종이 잔량
	}
};

class InkjetPrinter : virtual public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
		: Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void status() { printerStatus(); cout << "남은 잉크 " << availableInk << endl; }
	void print(int pages){
		if (availableInk < pages)				// 잉크부족
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		else if (printablePage(pages)) {		// 잉크여유 종이여유
			printPage(pages);
			availableInk -= pages;
			cout << "프린트하였습니다." << endl;
		}
	}
};

class LaserPrinter : virtual public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
		: Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void status() { printerStatus(); cout << "남은 토너 " << availableToner << endl; }
	void print(int pages) {
		if (availableToner < pages)				// 토너부족
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		else if (printablePage(pages)) {		// 토너여유 종이여유
			printPage(pages);
			availableToner -= pages;
			// 423p 결과를 보면 인쇄2매에 토너1개 사용됨 (그런 경우는 double형 availableToner & -= (double)pages/2 해줄 것)
			cout << "프린트하였습니다." << endl;
		}
	}
};

int main() {
	InkjetPrinter officejet("Officejet V40", "HP", 5, 10);
	LaserPrinter scx("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	officejet.status();
	scx.status();

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
				scx.print(papers);
				break;
		}
		officejet.status();
		scx.status();
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> answer;
	} while (answer == 'y');
	
	return 0;
}