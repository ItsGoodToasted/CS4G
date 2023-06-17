/*
Write a program that prints the multiplication table of a given number. 
The program should ask the user to enter a number, and then it should 
print the multiplication table for that number from 1 to 10.
*/

#include <iostream>

int main()
{
	int numA,i = 0;
	std::cout << "Give me a number: ";
	std::cin >> numA;
	for (i = 1; i <= 10; i++) {
		std::cout << numA << " * " << i << " = " << numA* i << "\n";
	}

}