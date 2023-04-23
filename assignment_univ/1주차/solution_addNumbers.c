/*
In this program, the main() function prompts the user to enter two real numbers, 
reads them from the keyboard using the scanf() function, and stores them in variables num1 and num2.
It then calls the add() function, passing num1 and num2 as arguments, and 
stores the result in the variable sum.Finally, it prints the value of sum using the printf() function.
The add() function simply adds the two numbers and returns the result.

Refer https://bymakers.tistory.com/6 for dealing with _CRT_SECURE_NO_WARNINGS 
*/


#include <stdio.h>

float add(float num1, float num2);

float add(float num1, float num2) {
    return num1 + num2;
}

int main() {
    float num1, num2, sum;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    sum = add(num1, num2);

    printf("The sum is: %.2f\n", sum);

    return 0;
}






