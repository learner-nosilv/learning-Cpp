# 6장 함수 중복과 static 멤버
> **블로그 주소** : https://blog.naver.com/hh-383/
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)


## 연습문제 정보
* **Open Challenge** : p.309
* **이론 문제** : 총 16문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 9문제
* **실습 문제 답안 제공** : 1, 5번


## 파일 구성
* 📁 `6장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `6장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 🖼️내 풀이
* 📁 `6장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 📄내 풀이코드

---

## 🖼️ 6장 이론문제 솔루션(출판사제공)
| <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5.jpg"  width="80%" height="80%"> |  |  |
| --  | -- | -- |



## 🖼️ 6장 개인풀이 (2).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg"  width="80%" height="80%"> | <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg"  width="80%" height="80%"> |  |
| -- | -- | -- |

---

## 실습문제 리뷰

> **OpenChallenge**  
> `어려웠던 것 1` **반복문과 조건문의 중첩으로 파악하기가 어려워짐**  
> `어려웠던 것 2` **Hint가 제시한 배열구조가 더 어렵게 했다.**
   
   쉬울 것 같아서 달려들었는데, while for if 의 향연으로 들여쓰기가 5번이 나왔다.  
   그랬더니, 어디서 break 하고 continue 하면 되는건지  
   이 block를 나오면 어떤 상태가 되는건지 혼란이 오면서 뇌에 과부하가 오기시작했다.  
   이 문제를 푸는데에 3시간을 잡아먹었다.     
   6장까지 시험공부해야하는데 얘에 몰두하다가 6장을 못 훑어보았다.


   그러다 시험끝난 주말에 노트에 적어가며 구상한 후,  
   코드를 작성하니까 30분안에 더 깔끔멀끔하게 작성할 수 있었다. 띠용  
   `복잡하다 싶으면 구상을 먼저 하자.`  


> **11.** `어려웠던 것`  **문자열리터럴이 인자일 때 파라미터 작성법**  

   포인터나 참조매개변수는 직관적으로 이해할 수 있었는데,  
   배열을 `int f ( arr[], int size )` 이렇게 받아와서 arr을 사용하는 건 아직 어색하다.  
   문자열을 `int f ( char* title )` 로 가져와서 title을 활용하는 것도 마찬가지이다.  
   그래서, solution처럼 간단히 작성할 수 있는 코드도 장황하게 작성했다....  

```cpp:solution.cpp
void Book::set(const char* title, int price) {
	... 
	int len = strlen(title);
	...
	strcpy(this->title, title);
	...
}
```
  
```cpp:mine.cpp
void Book::set(char* title, int price) {
	...
	int len;
	for (len = 0; *(title + len != '\0'; len++);	// int len = strlen(title);
	...
	for (int i = 0; i <= len; i++) {			// strcpy(this->title, title);
		*((this->title) + i) = *(title + i);
	}
	...
}
```
  ﻿
   아! 그리고 교재 오류덕분에,
   **리터럴 상수는 파라미터형을 `char*` 로 하면 받을 수 없고,
  `const char*` 으로 해야 인자로 받을 수 있다**는 것을 알았다.

   프로토타입은 `set(char*, int)` 호출문은 `set("명품자바", 12000)` !!  