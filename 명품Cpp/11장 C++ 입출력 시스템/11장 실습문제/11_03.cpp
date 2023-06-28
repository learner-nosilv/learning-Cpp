/* 3. 영어문장;한글문자 형식으로 입력될 때, ; 이후에 입력된 문자열만 출력, ctrl+Z는 ^Z로 입력종료를 나타낸다.
cin.ignore()와, cin.get() 사용하기*/
#include <iostream>

int main() {
	int ch;
	while ((ch=std::cin.get()) != EOF) {	// ctrl+Z 가 입력되면 끝, 이 순간 입력되어 버퍼로 다 들어감
		std::cin.ignore(99, ';');			// delimiter 앞까지 버퍼비우기 & delimter도 삭제
		char arr[31];
		std::cin.get(arr, 31, '\n');		// delimiter 앞까지 or 한글 15글자를 배열에 삽입
		std::cout << arr << (char)std::cin.get();
	}
	return 0;
}

// 나: 배열사용해서 cin.get(배열명, 문자갯수, delimiter) 했는데, 솔루션은 되게 간단함

/* 다시 해 봄!
#include <iostream>

int main() {
	int ch;
	std::cin.ignore(100, ';');				// 버퍼가 비워져있으면 입력받고, 최대 100글자 제거, 도중 delimiter ;가 나오면 delimiter까지만 제거
	while ((ch = std::cin.get()) != EOF) {	// 버퍼에 남아있는 문자가 없어서 get이 불가하면 ctrl+Z 가 입력되면 끝, 이 순간 입력되어 버퍼로 다 들어감
		std::cout << (char)ch;				// ; 이후의 한글 출력(한글은 2byte이므로 cout<< 두번에 한글자씩 출력됨-마지막 개행까지 출력됨
		if (ch == '\n') std::cin.ignore(100, ';');
	}
	return 0;
}
*/