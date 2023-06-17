/*
Write a program that asks the user to enter a positive integer and 
then calculates and prints the sum of its digits.
*/

#include <stdio.h>

int main() {
	int num, digit, report, digitSum = 0;

	printf("Give me a number (positive): ");
	scanf_s("%d", &num);
	

	if (num < 0) {
		num = num * -1;
		printf("I said positive so we're making it positive.");
	}
	report = num;
	while (num > 0) {
		digit = num % 10;
		digitSum += digit;
		num /= 10;
	}

	printf("The sum of your digits, %d, is %d\n",report, digitSum);

	return 0;
}