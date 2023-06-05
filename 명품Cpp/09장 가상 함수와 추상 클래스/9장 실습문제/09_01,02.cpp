/* 1, 2 ConverterŬ������ ��ӹ޾� �޷�->��ȭ, km->mile�� ��ȯ�ϴ� �� Ŭ������ �ۼ��ϱ�*/
#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;	// ������ȯ: src -> dest [Pure Virtual Function]
	virtual string getSourceString() = 0;	// src��Ī ��Ī
	virtual string getDestString() = 0;		// dest ���� ��Ī
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
protected:
	virtual double convert(double src) { return (src * ratio); }
	virtual string getSourceString() { return "��"; }
	virtual string getDestString() { return "�޷�"; }
public:
	WonToDollar(double n) :Converter(1 / n) {}		// 1 �޷��� n ��
};

class KmToMile : public Converter {
	virtual double convert(double src) { return src * ratio; }
	virtual string getSourceString() { return "Km"; }
	virtual string getDestString() { return "Mile"; }
public:
	KmToMile(double n) :Converter(1 / n) {}			// 1 mile�� n Km
};

int main() {
	cout << " 1.-------------------" << endl;
	WonToDollar wd(1010); // 1 �޷��� 1010��
	wd.run();

	cout << " 2.-------------------" << endl;
	KmToMile toMile(1.609344);
	toMile.run();
	return 0;
}