# 10장 템플릿과 표준 템플릿 라이브러리(STL)
> **블로그 주소** : https://blog.naver.com/hh-383/223133170636
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)

## 연습문제 정보
* **Open Challenge** : p.520
* **이론 문제** : 총 18문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 16문제
* **실습 문제 답안 제공** : 1, 5, 7, 11, 13, 15번


## 파일 구성
* 📁 `10장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `10장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 내 풀이
* 📁 `10장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 내 풀이코드

---

## 🖼️ 10장 이론문제 솔루션(출판사제공)
| ![sol1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/10%EC%9E%A5%20%ED%85%9C%ED%94%8C%EB%A6%BF%EA%B3%BC%20%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(STL)/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(1).jpg) | ![sol2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/10%EC%9E%A5%20%ED%85%9C%ED%94%8C%EB%A6%BF%EA%B3%BC%20%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(STL)/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(2).jpg) |  |
| --  | -- | -- |


## 🖼️ 10장 개인풀이 (3).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| ![1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/10%EC%9E%A5%20%ED%85%9C%ED%94%8C%EB%A6%BF%EA%B3%BC%20%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(STL)/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/10%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg) | ![2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/10%EC%9E%A5%20%ED%85%9C%ED%94%8C%EB%A6%BF%EA%B3%BC%20%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(STL)/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/10%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg) | ![3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/10%EC%9E%A5%20%ED%85%9C%ED%94%8C%EB%A6%BF%EA%B3%BC%20%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC(STL)/10%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/10%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(3).jpg) |
| -- | -- | -- |


---

## 실습문제 리뷰

> **OpenChallenge, 12.**
> `어려웠던 것` 중복되지않게 4단어를 랜덤하게 뽑는 방법 구상
> 
 1번은 그냥 뽑고, 2번째는 1번이랑 비교, 3번째는 1, 2번이랑 비교, 4번째는 1, 2, 3번이랑 비교하도록 구현하였는데 팩토리얼스러운 방식이 최선인지 궁금하다.
