/*
Write a program that asks the user to enter a positive integer 
and then calculates and prints the factorial of that number.
*/


#include <stdio.h>
int main() {

    int i, num;
    unsigned long long fac = 1;

    printf("Give me a number: ");
    scanf_s("%d", &num);
    if (num > 65) {
        printf("Too fucking big.");
    }
    else if (num < 0) {
        printf("Pls no negatives");
    }
    else {
        for (i = 1; i <= num; i++) {
            fac = fac * i;
        }
        printf("!%d = %llu", num, fac);
        return 0;
    }
}