/* 9-9. 8�忡�� �����ߴ� ������ Ŭ���� ��,
Printer Ŭ������ print(int pages)�� show() �� �� �Լ��� �����Լ��� �����϶�.

	8-8. Ŭ����: Printer �� InkjetPrinter , LaserPrinter
* Printer: �𵨸�, ������, �μ� �ż�, �����ܷ�, ����Ʈ
* InkjetPrinter: + ��ũ�ܷ�, ����Ʈ
* LaserPrinter: + ����ܷ�, ����Ʈ
*/
#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model;			// �𵨸�
	string manufacturer;	// ������
	int printedCount;		// �� �μ� �ż�
	int availableCount;		// �μ� ���� �ܷ�

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
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��, " << "���� ��ũ " << availableInk << endl;
	}

	void print(int pages) {
		if (availableCount < pages && availableInk < pages)
			cout << "��ũ�� ������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		else if (availableCount < pages)
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		else if (availableInk < pages)
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else {
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
			printedCount += pages;		// �� �μ� �ż� ����
			availableCount -= pages;	// ���� �ܷ� ����
			availableInk -= pages;		// ��ũ �ܷ� ����
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
		cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��, " << "���� ��� " << availableToner << endl;
	}

	void print(int pages) {
		if (availableCount < pages && availableToner < pages)
			cout << "��ʿ� ������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		else if (availableCount < pages)
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		else if (availableToner < pages)
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else {
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
			printedCount += pages;				// �� �μ� �ż� ����
			availableCount -= pages;			// ���� �ܷ� ����
			availableToner -= (float)pages / 2;	// ��� �ܷ� ����
		}
	}
};

int main() {
	InkjetPrinter officejet("Officejet V40", "HP", 5, 10);
	LaserPrinter* scx = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);		// [�����䱸] �ϳ��� �������� �����Ͽ� �����Ѵ�

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	officejet.show();
	cout << "������ : ";
	scx->show();

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
				scx->print(papers);
				break;
		}

		officejet.show();
		scx->show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> answer;
	} while (answer == 'y');

	delete scx;

	return 0;
}