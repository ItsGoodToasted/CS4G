/*
Write a program that takes a sentence as input and 
counts the number of words in it. Assume that words 
are separated by spaces.
*/

#include <iostream>
#include <string>


int main() {
	std::string words;

	std::cout << "Say some shit: ";
	std::getline(std::cin, words);

	int count = 0;
	bool isWord = false;

	for (char s : words) {
		if (s == ' ') {
			isWord = false;
		}
		else if (!isWord) {
			isWord = true;
			count++;
		}
	}

	std::cout << "Your sentence has " << count << " words in it.\n";

	return 0;
}