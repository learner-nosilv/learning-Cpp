#include <stdio.h>

int main() {
    int z, i, dan;

    // 1,2 HEADER �� ���� �ۼ�
    for (z = 2; z < 10; z++) {
        printf("%d��\t", z);
    }
    printf("\n");
    for (int j = 0; j < 80; j++) {
        printf("-");
    }
    printf("\n");

    // 3 for-for ��ø �ݺ����� ����Ͽ� ������ 2��~9�� ��ü�� ���
    for (i = 1; i < 10; i++) {
        for (dan = 2; dan < 10; dan++) {
            printf("%dX%d=%d\t", dan, i, dan * i);
        }
        printf("\n");
    }

    printf("\n");

    // 4 for-while ��ø �ݺ����� ����Ͽ� ������ 2��~9�� ��ü�� ���
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