/* 10. 두 파일이 같은지 비교하는 FileCompare 프로그램 만들기
	* 바이너리 I/O 이용
*/
#include <iostream>
#include <fstream>
using namespace std;

// 두 파일이 같은지 비교하는 함수
bool fileCompare(const char* img1, const char* img2) {
	ifstream fin1(img1, ios::in | ios::binary);		// 첫번째 파일 바이너리I/O로, 읽기목적으로 프로그램과 연결
	ifstream fin2(img2, ios::in | ios::binary);		// 두번째 파일 바이너리I/O로, 읽기목적으로 프로그램과 연결
	if (!fin1 || !fin2) {							// if 연결실패
		cout << "[Error] 파일읽기실패\n";
		return false;								// 연결실패에 의한 false 리턴
	}

	char buf1[32], buf2[32];						// 비교할 단위: 32byte
	int count1 = 0, count2 = 0;						// 실제로 읽은 바이트 량

	while (!fin1.eof() && !fin2.eof()) {
		// 32byte단위로 파일 읽기
		fin1.read(buf1, 32);
		fin2.read(buf2, 32);

		count1 = fin1.gcount();
		count2 = fin2.gcount();

		if (count1 == count2) {						// 경우1. 읽은 문자수가 같을 때
			for (int i = 0; i < count1; i++)
				if (buf1[i] != buf2[i])				//	1-1. 한 글자라도 다르면 false 리턴
					return false;
		}
		else										// 경우2. 읽은 문자수가 다를 때
			return false;							//	false 리턴
		// 경우1-2. 읽은 문자 수가 같고 문자종류도 같은 경우 = 현재까지 true
	}
	// 모든 byte가 같은 경우만 남음
	return true;
}

int main() {
	// 사용할 이미지 
	const char* img[3] = { "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_10_solution_a.jpg",
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_10_solution_b.jpg",
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_10_solution_c.jpg" };
	
	cout << "FileCompare--------------------\n";
	cout << "1. IMG1 VS IMG2 ··· ";
	if (fileCompare(img[0], img[1])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	cout << "2. IMG2 VS IMG3 ··· ";
	if (fileCompare(img[1], img[2])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	cout << "1. IMG3 VS IMG1 ··· ";
	if (fileCompare(img[2], img[0])) cout << "SAME\n";
	else cout << "DIFFERENT\n";

	return 0;
}
// 솔루션은 class를 이용하였고, 파일비교도 1byte씩 비교함