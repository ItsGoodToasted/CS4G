/*
Write a program that generates and prints a random number 
between 1 and 100. The program should then ask the user 
to guess the number and provide feedback if the guess is 
too high or too low. Continue this process until the user 
guesses the correct number.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

	srand(time(0));

	int randNum = rand() % 100 + 1;
	int guess;
	int guessCount = 0;
	
	std::cout << "Pick a number between 1 and 100.\n";

	do {
		std::cout << "Give me that number: ";
		std::cin >> guess;

		guessCount++;

		if (guess > randNum) {
			std::cout << "Your guess too high! Here, try another! \n";
		}
		else if (guess < randNum) {
			std::cout << "Your guess is too low! Here, try another! \n";
		}
		else {
			std::cout << "You fucking did it. It only took you " << guessCount << " tries.\n";
		}

	} 
	
	while (guess != randNum);

	return 0;
}
