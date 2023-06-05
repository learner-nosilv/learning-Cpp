/* 1, 2 Converter클래스를 상속받아 달러->원화, km->mile로 변환하는 두 클래스를 작성하기*/
#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;	// 단위변환: src -> dest [Pure Virtual Function]
	virtual string getSourceString() = 0;	// src명칭 명칭
	virtual string getDestString() = 0;		// dest 단위 명칭
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
protected:
	virtual double convert(double src) { return (src * ratio); }
	virtual string getSourceString() { return "원"; }
	virtual string getDestString() { return "달러"; }
public:
	WonToDollar(double n) :Converter(1 / n) {}		// 1 달러는 n 원
};

class KmToMile : public Converter {
	virtual double convert(double src) { return src * ratio; }
	virtual string getSourceString() { return "Km"; }
	virtual string getDestString() { return "Mile"; }
public:
	KmToMile(double n) :Converter(1 / n) {}			// 1 mile은 n Km
};

int main() {
	cout << " 1.-------------------" << endl;
	WonToDollar wd(1010); // 1 달러에 1010원
	wd.run();

	cout << " 2.-------------------" << endl;
	KmToMile toMile(1.609344);
	toMile.run();
	return 0;
}