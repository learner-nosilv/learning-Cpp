/* p.619	예제12-10	int 배열과 double 변수를 바이너리 파일에 저장하고 다시 읽기
	변수나 배열, 혹은 버퍼의 내용을 그대로 저장하기 위해서는 바이너리 I/O를 반드시 사용해야 한다.
		바이너리 I/O를 이용하므로 저장된 파일은 바이너리 파일이 된다. */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// 목적 파일의 이름
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-10\\data.dat";

	// 파일쓰기스트림객체 생성 & 목적 파일 열기
	ofstream fout(destFile, ios::out | ios::binary);
	if (!fout) {
		cout << "파일 열기 오류";
		return 0;
	}

	// 파일에 쓸 배열과 변수 선언
	cout << "1. 파일에 쓸 배열과 변수 선언\n";
	int n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// 0~9가 저장된 정수형 배열
	double d = 3.15;							// 크기가 8byte인 실수형 변수
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n)/sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;

	// 목적파일에 int 배열과 double 변수를 바이너리 파일에 쓰기
	fout.write((char*)n, sizeof(n));			// char* 형으로 변환한 int형 배열 n의 시작주소에 가서, 배열크기의 byte만큼을 읽고 fout에 연결된 파일에 쓰기
	fout.write((char*)&d, sizeof(d));			// char* 형으로 변환한 double형 변수d의 주소에 가서, 변수d크기만큼의 byte만큼을 읽고 fout에 연결된 파일에 쓰기
	fout.close();								// 파일 연결 해제

	// 파일쓰기에 사용된 배열과 변수의 값 변경
	cout << "\n2. 파일에 쓸 배열과 변수 변경\n";
	for (int i = 0; i < 10; i++)	n[i] = 99;	// 배열 n의 모든 원소값을 99로 변경
	d += 5;										// 실수 d의 값 8.15로 변경
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n) / sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;

	// 파일 쓰기에 사용된 파일을 읽어서 배열과 변수에 재할당
	cout << "\n3. 파일쓰기에 사용된 파일을 읽어서 배열과 변수에 재할당\n";
	ifstream fin(destFile, ios::in | ios::binary);	// 파일 읽기 스트림객체 생성 및 쓰기에 사용되었던 파일을 읽기 목적으로 재연결
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}
	fin.read((char*)n, sizeof(n));				// 배열크기의 byte만큼을 버퍼에서 읽어 n에 할당
	fin.read((char*)&d, sizeof(d));				// double크기의 byte만큼을 버퍼에서 읽어 d에 할당
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n) / sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;
	fin.close();

	cout << "\n4. 파일내용 binary형식으로 읽기" << endl;
	fin.open(destFile, ios::in | ios::binary);
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}
	
	char buf;				// 변수: 1byte 저장
	int j = 0;				// 카운트하는 변수: 4byte 마다 개행할 예정
	int k = 0;				// 카운트하는 변수: 배열index
	while (!fin.eof()) {	// 파일이 끝나기 전까지 읽기
		fin.read(&buf, 1);	// 1byte만큼의 파일읽기
		for (int i = 7; i >= 0; i--) {			// 1byte를 1비트씩 출력
			int result = (buf >> i) & 1;		// 00000001 과의 and 연산으로 맨 앞비트만 출력
			cout << result;
			cout << ' ';
		}
		j++;									// 1byte출력할 때마다 +1
		cout << ' ';							// 1byte출력할 때마다 공백
		if (j % 4 == 0) {						// 4byte출력할 때마다
			if (k < 10) {						// 배열: 10진법으로 실제 값 출력 후 개행
				cout << '\t' << n[k] << endl;
				k++;
			}
			else cout << '\t' << d << endl;		// 변수: 10진법으로 실제 값 출력 후 개행
		}
	}
}