# 11장 C++ 입출력 시스템
> **블로그 주소** : https://blog.naver.com/hh-383/223069314385
> 
> **출판사 주소** : [생능출판사](https://www.booksr.co.kr/product/%eb%aa%85%ed%92%88-c-programming%ea%b0%9c%ec%a0%95%ed%8c%90/)


## 연습문제 정보
* **Open Challenge** : p.204
* **이론 문제** : 총 19문제
* **이론 문제 답안 제공** : 홀수번째 문제
* **실습 문제** : 총 14문제
* **실습 문제 답안 제공** : 1, 6, 10, 13번


## 파일 구성
* 📁 `11장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `11장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 내 풀이
* 📁 `11장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 내 풀이코드

---

## 🖼️ 11장 이론문제 솔루션(출판사제공)
| ![sol1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(1).jpg) | ![sol2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(2).jpg) | ![sol3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(3).jpg) |
| --  | -- | -- |


## 🖼️ 4장 개인풀이 (5).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| ![1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg) | ![2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg) | ![3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(3).jpg) |
| -- | -- | -- |
| ![4](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(4).jpg) | ![5](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(5).jpg) |  |

---

## 실습문제 리뷰

> **574p 예제 11-13**
    `신기했던 것`  **매개변수를 가진 조작자를 만들어보려다가**
```
   ostream& answer(ostream& outs, string name) {
	outs << "세상에서 제일 예쁜 사람은 \"" << name << "\" 입니다.";
	return outs;
}
```

`answer(cout, user) << endl;` 으로 실행이 되었다.  
`getline(cin, 어쩌구)` 도 비슷한 원리로 사용하는 걸까?

    
> **11.**
    `어려웠던 것`  **LINK2019의 향연** static멤버는 inline으로 작성할 수 없다고 3장에서 배웠는데 까먹음
그리고 inline함수는 파일분리하면 안되는 것도 이제 알았음
