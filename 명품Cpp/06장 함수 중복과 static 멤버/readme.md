# 6장 함수 중복과 static 멤버
> **블로그 주소** : https://blog.naver.com/hh-383/223093239434
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
| <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5.jpg"  width="60%" height="60%"> |  |  |
| --  | -- | -- |



## 🖼️ 6장 개인풀이 (2).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg"  width="80%" height="80%"> | <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/06%EC%9E%A5%20%ED%95%A8%EC%88%98%20%EC%A4%91%EB%B3%B5%EA%B3%BC%20static%20%EB%A9%A4%EB%B2%84/6%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/6%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg"  width="85%" height="85%"> |  |
| -- | -- | -- |

---

## 실습문제 리뷰

> **OpenChallenge**  
> `어려웠던 것 1` **static 자체가 좀 막연-**  
> `어려웠던 것 2` **객체배열을 선언&초기화하는 방법**  
   
   중간고사 마지막 단원이다보니, 이론공부를 할 때 날림공부를 했다.  
   (날림이라 함은, 예제를 읽고만 넘어갔단 말)  
   그랬더니 금방금방 까먹고, 막연한 느낌이 없지않아있다.  
  
   변수는 *선언* & *할당(초기화)*  
   함수는 *원형선언* & *정의*  
   클래스는 *선언부* & *구현부*  
   static 변수는 *클래스 내 선언* → *전역범위 내 선언&할당(초기화)*  
   (or) static 변수는 *클래스 내 선언* → *전역범위 내 정의*  
   라는 새로운 개념이어서 좀 헷갈렸다.  
    
   그리고, 또 어려웠던 것은 **객체배열의 선언동시초기화**이다.  
   `클래스명 배열명[갯수] = {생성자(...), 생성자(...), 생성자(...), ... }` 로  
   선언동시초기화한다는 것을 오늘 처음 알았다ㅋㅋㅠ  
  
  
> **1.** `몰랐던 개념`  **포인터의 디폴트 매개변수설정**  
  
   포인터의 디폴트 매개변수는 `NULL`이 아닌 `nullptr` 이라는 걸 배웠다.  
  
    
> **4.** `몰랐던 개념`  **default매개변수는 선언, 정의 둘 중 한 곳에만**  
  
```
class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);
	~MyVector() { delete[] mem; }
	void showMem();
};

MyVector::MyVector(int n = 100, int val = 0) {
	this->size = n;
	mem = new int[size];
	for (int i = 0; i < size; i++)
		mem[i] = val;
}
```
   이렇게 작성하면, `C2572 redefinition of default argument:parameter` 에러가 뜬다.  
  
```
class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);	// (int n, int val)
	~MyVector() { delete[] mem; }
	void showMem();
};

MyVector::MyVector(int n, int val) {	// (int n = 100, int val = 0)
	this->size = n;
	mem = new int[size];
	for (int i = 0; i < size; i++)
		mem[i] = val;
}
```
   이렇게 선언부과 구현부 둘 중에 한 곳에만 작성하니 괜찮았다.