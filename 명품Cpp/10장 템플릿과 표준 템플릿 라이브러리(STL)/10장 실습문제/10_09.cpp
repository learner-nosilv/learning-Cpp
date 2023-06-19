/* 9.	STL의 vector 클래스를 이용하여 숫자입력을 받고, 입력한 정수들과 평균을 출력하는 프로그램 작성하기
*		프로그램 종료: 0
*/
#include <iostream>
#include <vector>		// Standard Template Library
using namespace std;

bool cinNcheck(int& a) {
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10, '\n');
		return false;
	}
	else
		return true;
}

int main() {
	vector<int> arr;
	int answer = 0, size = 0, result = 0;
	while (true) {
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		if (cinNcheck(answer) == false) {	// 경우1. 오류를 일으키는 값
			cout << "제대로 된 값을 입력하세요." << endl;
			continue;
		}
		else if (answer == 0)				// 경우2. 값이 0 (종료)
			break;
		else {								// 경우3. 정상입력
			arr.push_back(answer);			//	가변배열에 삽입
			result += answer;				//	원소 총 합
			size++;							//	arr.size() 해도 되지만..
			for (int i = 0; i < size; i++)	//	원소 전부 출력
				cout << arr[i] << ' ';
			cout << '\n';
			cout << "평균 = " << (double)result / size << endl;
		}
	}
	return 0;
}