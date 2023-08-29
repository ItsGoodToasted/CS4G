/*
Write a program that takes an integer as input and checks if it is positive,
negative, or zero. If the number is positive, print "Positive". If the number 
is negative, print "Negative". If the number is zero, print "Zero".
*/

#include <iostream>

int main()
{
	int num = 0;
	std::cout << "Give me a number: ";
	std::cin >> num;
	if (num < 0) {
		std::cout << "Negative";
	}
	else if (num > 0) {
		std::cout << "Positive";
	}
	else {
		std::cout << "Zero";
	}
	return 0;	
}