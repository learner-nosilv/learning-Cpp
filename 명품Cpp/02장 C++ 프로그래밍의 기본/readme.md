# 2장 C++ 프로그래밍의 기본
> **블로그 주소** : https://blog.naver.com/hh-383/223064850445
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)


## 연습문제 정보
* **Open Challenge** : p.83
* **이론 문제** : 총 20문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 16문제
* **실습 문제 답안제공** : 1, 6, 11, 13번


## 파일명 형식 설명
* 📁 `2_예제_출판사제공` 　예제코드와 그림자료코드로 출판사에서 제공함
* 🖼️ `2장 이론문제 홀수번호 정답_출판사제공` 이론문제 홀수번호 솔루션
* 🖼️ `2장 개인풀이 (n).jpg` 　체크타임부터 이론문제까지 내가 풀고 채점한 노트
* 📁 `2장 실습문제 코드와 결과캡쳐` 　내가 작성한 코드+출판사가 제공한 일부 문제들에 대한 솔루션

---

![solution](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5_%EC%B6%9C%ED%8C%90%EC%82%AC%EC%A0%9C%EA%B3%B5.jpg)

---

## 🖼️ 2장 개인풀이 (n).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| ![1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg) | ![2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg) | ![3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(3).jpg) | ![4](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(4).jpg) |
| -- | -- | -- | -- |
| ![5](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(5).jpg) | ![6](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(6).jpg) | ![7](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(7).jpg) | ![8](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/02%EC%9E%A5%20C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%EC%9D%98%20%EA%B8%B0%EB%B3%B8/2%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(8).jpg) |
