/*
Write a program that asks the user to enter two integers
and then finds and prints the maximum of the two numbers.
*/

#include <stdio.h>

int main() {

	int numA;
	int numB;
	printf("Enter a number: ");
	scanf_s("%d", &numA);
	printf("Enter another number: ");
	scanf_s("%d", &numB);
	if (numB > numA) {
		printf("%d is bigger", numB);
	}
	else if (numB == numA) {
		printf("They are the same fucking number, dickass");
	}
	else {
		printf("%d is bigger", numA);
	}
	return 0;
}