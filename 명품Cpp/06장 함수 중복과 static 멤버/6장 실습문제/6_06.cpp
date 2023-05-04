/* 6. 동일한 크기로 배열을 변환하는 다음 2개의 static 멤버함수를 가진 ArrayUtility2 클래스 작성하기
* 콘솔결과를 보고 적절한 main() 작성하기
*/
#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	// s1, s2를 연결한 배열 동적생성 & 포인터형 리턴
	static int* concat(int s1[], int s2[], int size);
	// s1-s2인 배열 동적생성 & 포인터형 리턴 , 해당 배열의 크기는 참조파라미터로 간접리턴 
	static int* remove(int s1[], int s2[], int size, int& retSize);	
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* add = new int[2 * size];
	int j = 0;
	for (int i = 0; i < size; i++, j++)
		add[j] = s1[i];
	for (int i = 0; i < size; i++, j++)
		add[j] = s2[i];
	return add;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* temp = new int[size];	// 임시결과배열
	retSize = 0;				// 결과배열의 크기

	// 배열 s1에서 s2를 뺀 결과 구하기
	for (int i = 0; i < size; i++) {	// s1[0~]

		// s1[i] s2[0~] 비교
		int match_idx = 0;
		while (match_idx < size) {
			if (s1[i] == s2[match_idx]) break;
			match_idx++;
		}	
		// 상황1. if(s1[i] == s2[match_idx])에 의해 or 상황2. while(match_idx < size)에 의해
		if(match_idx>=size){		// 상황2. s1[i]가 s2배열에 없는 경우
			temp[retSize] = s1[i];	// 임시결과배열에 저장
			retSize++;				// 결과배열의 크기증가
		}
	}

	// 임시결과배열은 크기가 size이므로, 크기가 retSize인 결과배열 동적메모리 할당
	int* sub = new int[retSize];
	for (int i = 0; i < retSize; i++)
		sub[i] = temp[i];

	// 임시 결과배열 동적메모리 반환
	delete[] temp;

	return sub;
}

int main() {
	const int size = 5;
	int x[size] = { 0, };
	int y[size] = { 0, };

	cout << "정수를 " << size << " 개 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < size; i++)
		cin >> x[i];

	cout << "정수를 " << size << " 개 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < size; i++)
		cin >> y[i];

	cout << "합친 정수 배열을 출력한다" << endl;
	int* add_result = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < 2*size; i++)
		cout << add_result[i] << ' ';
	cout << endl;

	int subsize;
	int* sub_result = ArrayUtility2::remove(x, y, size, subsize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << subsize << endl;
	for (int i = 0; i < subsize; i++)
		cout << sub_result[i] << ' ';
	cout << endl;

	delete[] add_result;
	delete[] sub_result;

	return 0;
}