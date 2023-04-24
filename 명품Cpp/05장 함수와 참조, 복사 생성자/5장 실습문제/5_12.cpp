/* 12.
* 학과를 나타내는 Dept 클래스
* main()의 실행결과가 다음과 같이 되도록 Dept 클래스에 멤버들을 모두 구현하고
* 전체 프로그램을 완성하기
* 
* 60점 이상과 초과가 혼용되어있는데, (1)의 실행결과를 보면 60점 이상이 아니라, <<초과>>가 맞다.
*/

#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;				// 점수를 저장하는 배열 동적할당)
public:
	Dept(int size) {			// 배열 동적할당
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept);
	~Dept() { delete[] scores; }
	int getSize() { return size; }
	void read();				// 학과소속 모든 학생들의 점수를 읽어오기
	bool isOver60(int index) {	// 특정 index의 학생점수가 60 초과일시 true
		if (scores[index] > 60)
			return true;
		else
			return false;
	}
};
 
Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int [(this->size)];
	for (int i = 0; i < (this->size); i++)
		this->scores[i] = dept.scores[i];
}

void Dept::read() {
	cout << this->size << "개 점수 입력>> ";
	for (int i = 0; i < this->size; i++)
		cin >> this->scores[i];
}

// (2) 복사 생성자가 없는 경우, com.score와 dept.score는 동일한 값을 갖는다.
// 이 때, 함수 countPass()가 종료되면, 파라미터 dept가 소멸되며 dept.score가 가리키고 있는 동적할당공간도 해제된다.
// 추 후, 함수 main()이 종료되어 com객체가 소멸할 때 com.score가 기리키고 있는 동적할당공간 해제명령이 실행되며 런타임오류 발생
int countPass(Dept dept) {		// (2) 복사생성자 호출위치 : [call by value] Dept dept(com);
								//		인자 com을 파라미터 dept에 전달하며 복사생성자 실행 
	int count = 0;				// (3) (2) Dept & dept [call by reference] 로 변경해주면 런타임 오류가 발생하지 않음
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i))
			count++;
	}
	return count;
}

int main(){
	Dept com(10);	// com 학과 : 학생 10인
	com.read();		// 점수 읽어들이기
	int n = countPass(com);
	cout << "60점 초과는 " << n << "명" << endl;

	return 0;					 
}