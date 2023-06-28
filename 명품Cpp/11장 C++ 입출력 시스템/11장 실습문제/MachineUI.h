#ifndef UI_H
#define UI_H
#include <iostream>
#include <iomanip>
#include "Material.h"
#include "Recipe.h"

class MachineUI {
	static bool isErr();
public:
	static void greeting();						// 머신 실행 시, 특정 문구 출력
	static void parting();						// 머신 종료 시, 특정 문구 출력
	static void filling();						// 머신의 재료통 충전 시, 특정 문구 출력
	static void making(std::string name);		// 머신으로 특정 메뉴 제작 시, 특정 문구 출력
	static void lacking();						// 머신이 재료부족으로 제작실패 시, 특정 문구 출력
	static int getMenu(Recipe* r, int size);	// 머신의 메뉴선택 (parameter: 머신의 레시피배열, 레시피갯수)
	static void showMaterial(Material* m);		// 머신의 재료통 상태 출력
};
#endif // !UI_H