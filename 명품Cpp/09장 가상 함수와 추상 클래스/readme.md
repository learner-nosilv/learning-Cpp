# 9장 가상 함수와 추상 클래스
> **블로그 주소** : https://blog.naver.com/hh-383/223069314385
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)


## 연습문제 정보
* **Open Challenge** : p.458
* **이론 문제** : 총 15문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 10문제
* **실습 문제 답안 제공** : 1, 3, 6번


## 파일 구성
* 📁 `9장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `9장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 내 풀이
* 📁 `9장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 내 풀이코드

---

## 🖼️ 9장 이론문제 솔루션(출판사제공)과 개인풀이
| ![sol1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/09%EC%9E%A5%20%EA%B0%80%EC%83%81%20%ED%95%A8%EC%88%98%EC%99%80%20%EC%B6%94%EC%83%81%20%ED%81%B4%EB%9E%98%EC%8A%A4/9%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/9%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5.jpg) | ![mine1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/09%EC%9E%A5%20%EA%B0%80%EC%83%81%20%ED%95%A8%EC%88%98%EC%99%80%20%EC%B6%94%EC%83%81%20%ED%81%B4%EB%9E%98%EC%8A%A4/9%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/9%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg) | ![mine2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/09%EC%9E%A5%20%EA%B0%80%EC%83%81%20%ED%95%A8%EC%88%98%EC%99%80%20%EC%B6%94%EC%83%81%20%ED%81%B4%EB%9E%98%EC%8A%A4/9%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/9%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg) |
| --  | -- | -- |

---

## 실습문제 리뷰

**개념이 어색했다.**  
   
Virtual, Pure Virtual Function, Abstract Class 라는 개념에 익숙해지는 시간이 필요했다.  
   
교재에게 고마운 건,  
* 개념이 글로 다 세세히 적혀있어서 복습하기 좋다는 점과
* 어색한 개념이 점차 익숙해질 수 있도록 문제들이 체크타임->이론문제->실습문제들로 난이도 쉬움부터 익스트림까지 다양하게 많다는 점  
   
이다.
   
> **OpenChallenge**
    `어려웠던 것`  **맵 디스플레이**

   맵을 깔아놓고, 나중에 원하는 좌표로 돌아갈 수 있는 방법을 모른다.  
   따라서, 모든 객체의 (x, y)를 다 구해둔 다음에  
   맵에 한 땀 한 땀 비교문으로 검사해가면서 표시해야했다.  
   잡아 먹히는 경우도 고려해야했다...  

    
> **10.**
    `어려웠던 것`  **파일쪼개기** Main, Shape, UI, GraphicEditor로 코드를 나누는 것
    
   GraphicEditor 에 다 넣으면 되는 걸 UI 라는 클래스로 떼내려니 귀찮았다.   
