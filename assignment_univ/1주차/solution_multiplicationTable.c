#include <stdio.h>

int main() {
    int z, i, dan;

    // 1,2 HEADER 와 밑줄 작성
    for (z = 2; z < 10; z++) {
        printf("%d단\t", z);
    }
    printf("\n");
    for (int j = 0; j < 80; j++) {
        printf("-");
    }
    printf("\n");

    // 3 for-for 중첩 반복문을 사용하여 구구단 2단~9단 전체를 출력
    for (i = 1; i < 10; i++) {
        for (dan = 2; dan < 10; dan++) {
            printf("%dX%d=%d\t", dan, i, dan * i);
        }
        printf("\n");
    }

    printf("\n");

    // 4 for-while 중첩 반복문을 사용하여 구구단 2단~9단 전체를 출력
    for (i = 1; i < 10; i++) {
        dan = 2;
        while (dan < 10) {
            printf("%dX%d=%d\t", dan, i, dan * i);
            dan++;
        }
        printf("\n");
    }

    return 0;
}