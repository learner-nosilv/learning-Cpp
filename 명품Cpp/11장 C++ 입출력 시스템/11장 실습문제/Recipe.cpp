#include "Recipe.h"
/*
void Recipe::setRecipe(std::string name, int size) {	// 재료량이 모두 같은 경우
	this->name = name;	// 레시피 이름
	this->material[0].setMaterial("Coffee", size);
	this->material[1].setMaterial("Sugar", size);
	this->material[2].setMaterial("CREAM", size);
	this->material[3].setMaterial("Water", size);
	this->material[4].setMaterial("Cup", size);
}
*/
void Recipe::setRecipe(std::string name, int* size) {		// 재료량이 다른 경우(동적할당)
	this->name = name;	// 레시피 이름
	this->material[0].setMaterial("Coffee", size[0]);
	this->material[1].setMaterial("Sugar", size[1]);
	this->material[2].setMaterial("CREAM", size[2]);
	this->material[3].setMaterial("Water", size[3]);
	this->material[4].setMaterial("Cup", size[4]);
	delete[] size;											// 동적할당 해제
}