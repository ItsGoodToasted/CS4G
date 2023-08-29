/*
Write a program that prints the Fibonacci sequence up to a given number. 
The program should ask the user to enter a number, and then it should 
print the Fibonacci sequence up to that number.
*/

#include <stdio.h>

//Tests if the input is a perfect square
int perfectSquare(int num) {
	int sqrt = 0;
	while (sqrt * sqrt <= num) {
		if (sqrt * sqrt == num)
			return 1;
		sqrt++;
	}
	return 0;
}

//Tests if a number is in the Fibonacci Sequence by checking if either 5N^2+4 or 5N^2-4 is a perfect square
int isFib(int num) {
	return perfectSquare(5 * num * num + 4) | perfectSquare(5 * num * num - 4);
}

//Prints the fibonacci sequence up to a given input.
void printFib(int num) {
	int a = 0, b = 1, c = 0;
	while (c <= num) {
		printf("%d ", c);
		c = a + b;
		a = b;
		b = c;
	}
	printf("\n");
}

//Receives the users input and runs the fibonacci test. If valid, prints fibonacci.
int main() {
	int number;

	printf("Give me a number: ");
	scanf_s("%d", &number);

	if (isFib(number)) {
		printFib(number);
	}
	else {
		printf("%d isn't a Fibonacci number.",number);
	}
	return 0;
}
