/* ����, ��ᷮ���� �߻�ȭ�� ��� Ŭ���� Material
*  ���� inline �Լ��̹Ƿ� ������ϸ� �����Ѵ�.
*/
#ifndef  MATERIAL_H
#define MATERIAL_H
#define MATERIAL 5					// �����ǿ� ���̴� ���/Ŀ�Ǹӽſ� ���̴� ��� ����
#include <string>
class Material {					// ���
	std::string name;				// ����̸�
	int number;						// ��᰹��
public:
	Material(std::string name = "", int number = 0) { this->name = name; this->number = number; }
	void setMaterial(std::string name, int number) { this->name = name; this->number = number; }
	void setName(std::string name) { this->name = name; }
	void setNumber(int number) { this->number = number; }
	std::string getName() { return this->name; }
	int getNumber() { return this->number; }
	bool operator -= (Material a) {						// [������ �����ε�] ���Ҹ�
		if (this->number < a.number) return false;		// ��ᰡ �����ϸ�, ����X
		else if (this->name != a.name) return false;	// ������ �ٸ���, ����X
		this->number -= a.number;						// ������ ���� ���� ���������� ������, ����O
		return true;
	}
};
#endif // ! MATERIAL_H