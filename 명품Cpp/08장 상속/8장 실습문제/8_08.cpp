/* 8. Ŭ����: Printer �� InkjetPrinter , LaserPrinter
* Printer: �𵨸�, ������, �μ� �ż�, �����ܷ�, ����Ʈ
* InkjetPrinter: + ��ũ�ܷ�, ����Ʈ
* LaserPrinter: + ����ܷ�, ����Ʈ
*/
#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;			// �𵨸�
	string manufacturer;	// ������
	int printedCount;		// �� �μ� �ż�
	int availableCount;		// �μ� ���� �ܷ�
protected:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->printedCount = 0;
		this->availableCount = availableCount;
	}
	void printerStatus() { cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��, "; }
	bool printablePage(int pages) {
		if (availableCount < pages) {
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return false;
		}
		else return true;
	}
	void printPage(int pages) {
		printedCount += pages;		// �� �μ� �ż�
		availableCount -= pages;	// �μ� ���� �ܷ�
	}
};

class InkjetPrinter : virtual public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
		: Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void status() { printerStatus(); cout << "���� ��ũ " << availableInk << endl; }
	void print(int pages){
		if (availableInk < pages)				// ��ũ����
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else if (printablePage(pages)) {		// ��ũ���� ���̿���
			printPage(pages);
			availableInk -= pages;
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
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
	void status() { printerStatus(); cout << "���� ��� " << availableToner << endl; }
	void print(int pages) {
		if (availableToner < pages)				// ��ʺ���
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else if (printablePage(pages)) {		// ��ʿ��� ���̿���
			printPage(pages);
			availableToner -= pages;
			// 423p ����� ���� �μ�2�ſ� ���1�� ���� (�׷� ���� double�� availableToner & -= (double)pages/2 ���� ��)
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
		}
	}
};

int main() {
	InkjetPrinter officejet("Officejet V40", "HP", 5, 10);
	LaserPrinter scx("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	officejet.status();
	scx.status();

	char answer;
	do {	
		int printerIdx, papers;		// ������ ������, �μ� �ż�
		while (true) {
			cout << '\n' << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
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
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> answer;
	} while (answer == 'y');
	
	return 0;
}