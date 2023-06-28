/* 레시피명과 필요한 재료(Material:재료명, 재료량)으로 추상화 된 레시피 클래스 Recipe */
#ifndef RECIPE_H
#define RECIPE_H
#include "Material.h"		// <string>헤더와 MATERIAL상수도 존재
class Recipe {
	std::string name;				// 레시피 이름
	Material material[MATERIAL];	// 필요 재료 배열[5]
public:
	Recipe() {}						// 기본생성자
	// void setRecipe(std::string name, int size = 0);			// [함수 오버로딩] 재료량이 모두 같은 경우
	void setRecipe(std::string name, int* size);			// [함수 오버로딩] 재료량이 다른 경우(동적할당 받은 배열必)
	std::string showRecipeName() { return this->name; }		// 레시피 명 리턴
	Material* showMaterial() { return this->material; }		// 레시피 재료 배열 리턴
};
#endif // !RECIPE_H