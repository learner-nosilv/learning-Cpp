/* 재료명, 재료량으로 추상화된 재료 클래스 Material
*  전부 inline 함수이므로 헤더파일만 존재한다.
*/
#ifndef  MATERIAL_H
#define MATERIAL_H
#define MATERIAL 5					// 레시피에 쓰이는 재료/커피머신에 쓰이는 재료 종류
#include <string>
class Material {					// 재료
	std::string name;				// 재료이름
	int number;						// 재료갯수
public:
	Material(std::string name = "", int number = 0) { this->name = name; this->number = number; }
	void setMaterial(std::string name, int number) { this->name = name; this->number = number; }
	void setName(std::string name) { this->name = name; }
	void setNumber(int number) { this->number = number; }
	std::string getName() { return this->name; }
	int getNumber() { return this->number; }
	bool operator -= (Material a) {						// [연산자 오버로딩] 재료소모
		if (this->number < a.number) return false;		// 재료가 부족하면, 연산X
		else if (this->name != a.name) return false;	// 재료명이 다르면, 연산X
		this->number -= a.number;						// 재료명이 같고 수가 부족하지도 않으면, 연산O
		return true;
	}
};
#endif // ! MATERIAL_H