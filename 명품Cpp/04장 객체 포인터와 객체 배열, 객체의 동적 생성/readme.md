# 4장 객체 포인터와 객체 배열, 객체의 동적 생성
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
* 📁 `4장 예제` 　∋ 📄예제코드와 그림자료코드 (출판사 제공)
* 📁 `4장 이론문제` 　∋ 🖼️홀수번호 솔루션(출판사제공), 내 풀이
* 📁 `4장 실습문제` 　∋ 📄일부문제 솔루션(출판사제공), 내 풀이코드

---

## 🖼️ 4장 이론문제 솔루션(출판사제공)
| ![sol1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(1).jpg) | ![sol2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(2).jpg) | ![sol3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C%20%ED%99%80%EC%88%98%EB%B2%88%ED%98%B8%20%EC%A0%95%EB%8B%B5%20(3).jpg) |
| --  | -- | -- |


## 🖼️ 4장 개인풀이 (5).jpg
>체크타임부터 이론문제까지 내가 풀고 채점한 노트

| ![1](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(1).jpg) | ![2](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(2).jpg) | ![3](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(3).jpg) |
| -- | -- | -- |
| ![4](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(4).jpg) | ![5](https://github.com/learner-nosilv/learning-Cpp/blob/master/%EB%AA%85%ED%92%88Cpp/04%EC%9E%A5%20%EA%B0%9D%EC%B2%B4%20%ED%8F%AC%EC%9D%B8%ED%84%B0%EC%99%80%20%EA%B0%9D%EC%B2%B4%20%EB%B0%B0%EC%97%B4%2C%20%EA%B0%9D%EC%B2%B4%EC%9D%98%20%EB%8F%99%EC%A0%81%20%EC%83%9D%EC%84%B1/4%EC%9E%A5%20%EC%9D%B4%EB%A1%A0%EB%AC%B8%EC%A0%9C/4%EC%9E%A5%20%EA%B0%9C%EC%9D%B8%ED%92%80%EC%9D%B4%20(5).jpg) |  |

---

## 실습문제 리뷰

> **OpenChallenge**

    `어려웠던 것`  **하나의 클래스에서 다른 클래스의 객체를 사용하는 개념**

    프로그램 구조에서, WordGame 클래스는 Player 객체 3개를 배열로 사용한다.
    이 때 Player 객체로 클래스의 멤버들을 사용하는데 public, private 개념이 어떻게 적용되는지 모르겠었다.

    일단은 기본타입들 사용하는 것처럼 단순하게 접근하는 것이 _본능적으로_　좋을 것 같아서 그런 생각으로 코드를 작성했다.

    아마 이번 문제는 `상속`에 대한 떡밥이 아닐까 하는 생각도 든다.
    
> **11.**
    `어려웠던 것`  **클래스의 순서** 를 지키지 않아서 헤멤
    
    A클래스에서 B클래스를 사용한다면,
    A클래스를 선언하기 전에 B클래스를 선언해야 `undefined -` 불상사를 막을 수 있다.

    여기서, 함수 프로토타입 선언하듯이
    `class Container;` 이런 것도 안 됨! 당연한 말이겠지만.......

    그러니까, 왜 문제를 CVM 다음 Container로 써준걸까...

> **14.**
    `어려웠던 것` **Enter('\n') 입력받기**
    
    코드순서가 이름입력받기 → 엔터입력받기였다.
    이름을 `cin`으로 받았더니, 개행문자가 버퍼에 남아서
    엔터입력받는 구간에서 사용자에게 입력받지 않고도 자동으로 프로그램이 진행되었다.
    
    이를 해결한 것은 이름을 `getline`으로 입력받은 것이다.
    이렇게 하면 구분자로 사용된 개행문자도 버퍼에서 빠졌다.
    (구분자는 입력 값엔 안 들어가면서 버퍼에서는 사용됨)

    엔터를 입력받아서 그 값을 저장하는 것도 어려웠다.
    `cin`도 안되고,
    `getline`도 안되고,
    그래서
    `int enter = getchar()`을 사용하였다.
    getchar() 매커니즘: 입력값을 버퍼에 넣고 한 문자만 리턴, 이 때 '\n'도 리턴한다.
        (예1) a 엔터 하면, a 리턴, 엔터는 버퍼에 남아있다가 나중에 문제일으킴
        (예2) 엔터 하면, 엔터 리턴 ← 내가 선택
