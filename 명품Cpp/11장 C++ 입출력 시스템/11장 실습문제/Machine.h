#ifndef MACHINE_H
#define MACHINE_H

#include "Material.h"	// <string>, MATERIAL 5
#include "Recipe.h"
#include "MachineUI.h"

#define RECIPE 3		// 머신이 보유할 레시피 갯수
#define FILL 3			// 머신의 재료통 용량

class Machine {
	Material material[MATERIAL];	// 머신의 재료통
	Recipe coffee[RECIPE];			// 머신이 보유한 레시피
	bool operator -= (Recipe r);	// [연산자 오버로딩] 머신에서 레시피만큼의 재료량 소모
	void fill();					// 재료통 채우기 [3]만큼
	bool make(int recipeIdx);		// 레시피대로 실제 제작
public:
	Machine();			// 생성자: 재료통과 레시피 세팅
	void run();			// 머신 실행
};
#endif // !MACHINE_H