#include <iostream>
#include <string>
#include <algorithm>

//Compares the string to it's reverse counterpart.
bool isPal(const std::string& wrd) {
	std::string reversedWrd = wrd;
	std::reverse(reversedWrd.begin(), reversedWrd.end());
	return wrd == reversedWrd;
}


//Converts users input to lowercase and checks if palindrome.
int main() {

	std::string word;
	std::cout << "Give me a word: ";
	std::getline(std::cin, word);
	for (int i = 0; i < word.length(); i++)
		word[i] = tolower(word[i]);

	if (isPal(word)) {
		std::cout << "It's a palindrome" << std::endl;
	}
	else {
		std::cout << "Just a normal word, buddy." << std::endl;
	}
	return 0;
	}
