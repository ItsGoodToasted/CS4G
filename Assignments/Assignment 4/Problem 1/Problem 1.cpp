#include <iostream>
#include <string>

//Checks for the 5 vowels, not including y
int countVowels(const std::string& words) {
	int count = 0;
	for (char wrd : words) {
		wrd = tolower(wrd);
		if (wrd == 'a' || wrd == 'e' || wrd == 'i' || wrd == 'o' || wrd == 'u')
			count++;
	}
	return count;
}


int main() {

	std::string input;

	std::cout << "Tell me something: ";
	std::getline(std::cin, input);

	int vowelCount = countVowels(input);
	std::cout << "Number of vowels in the shit your wrote: " << vowelCount << std::endl;

	return 0;
}