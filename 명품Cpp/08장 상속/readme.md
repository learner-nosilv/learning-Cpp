# 8장 상속
> **블로그 주소** : https://blog.naver.com/hh-383/223069314385
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)
  
---
    
## 연습문제 정보
* **Open Challenge** : p.411
* **이론 문제** : 총 16문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 9문제
* **실습 문제 답안 제공** : 1, 3, 5, 7번
  
---
  
## 파일 구성
* 📁 `8장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `8장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 내 풀이
* 📁 `8장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 내 풀이코드
  
---
  
## 🖼️ 8장 이론문제 솔루션(출판사제공)과 8장 개인풀이 (2).jpg
| <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/08%EC%9E%A5%20%EC%83%81%EC%86%8D/8%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/8%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5.jpg"> | <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/08%EC%9E%A5%20%EC%83%81%EC%86%8D/8%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/8%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg"  width="60%" height="60%">  | <img src="https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/08%EC%9E%A5%20%EC%83%81%EC%86%8D/8%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/8%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg"  width="50%" height="50%"> |
| --  | -- | -- |
  
---
  
## 실습문제 리뷰

> **OpenChallenge**  
   `어려웠던 것1`  **while 블록 안에서 객체를 생성하고 포인터를 연결하는 일**  
   `어려웠던 것2`  **new delete**  
  
   특정 블록에서 객체를 생성하면, 그 객체는 lifecycle이 블록과 같다.  
   그래서, `객체선언;` `포인터=&객체;` 해도 블록이 종료되면 오류가 났다.  
   엄밀히 말하면, int형은 남아있었는데, string형은 다 날아갔다.  
   _(값복사, 주소복사의 원리인 것 같은데)_  
   `Product* management[100];`인 상황에서, 해결책으로  
   1. `Book book[100];` `management[0]=&book[1];` 이건 너무 메모리낭비  
   2.  두번째, `management[0]=&Book();` 이건 컴파일 오류  
   3. 결론! `management[0]=new Book();` **동적할당** 예~  
  
   이렇게, 포인터배열management는 부분적으로 동적할당을 받았기때문에  
   동적할당해제도 `delete[] management;` 하면 오류가 난다....  
   그러니까, **for문을 통해서 동적할당 받은 부분만 해제**해줘야한다.  
  
    
> **8.**  
   `어려웠던 것1`  내 마음대로가 아닌 책의 **요구사항대로 작성하기**  
   `어려웠던 것2`  **파일분리**는 항상 어렵다 + **접근범위** 를 신경쓰는 일  
    
   내가 임의로 작성한 코드(1)와 책의 요구사항대로 작성한 코드(2) 중  
   어떤 코드가 더 효율적인지 모르겠다.  
  
   #ifndef를 사용하지만 그래도,  
   이 소스는 어떤 헤더파일만 넣어주면 될지 고민을 좀 했다.  
   캡슐화의 원칙을 최대한 지키려니  
   클래스가 많은 상황에서 Public VS Private 를 의식하는 것도  
   신경이 많이 쓰이고 복잡복잡  