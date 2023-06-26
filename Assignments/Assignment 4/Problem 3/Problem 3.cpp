#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


char genRandomUppercase() {
	return static_cast<char>('A' + rand() % 26);
}

char genRandomLowercase() {
	return static_cast<char>('a' + rand() % 26);
}

char genRandomNum() {
	return static_cast<char>('0' + rand() % 10);
}

char genRandomSpec() {
	const std::string specialChars = "!@#$%^&*(){}[]|:;'<>?";
	return specialChars[rand() % specialChars.length()];
}



int main() {
	int passwordLength;
	std::string password;

	std::cout << "How many characters you want in that password?: " << std::endl;
	std::cin >> passwordLength;

	srand(static_cast<unsigned int>(time(0)));

	char (*genRandomChar[])() = { genRandomLowercase,genRandomUppercase,genRandomNum,genRandomSpec };

	for (int i = 0; i < passwordLength; i++) {
		int random = rand() % 4;
		password += genRandomChar[random]();
	}

	std::cout << "Here's your new password: " << password << std::endl;

	return 0;
	}
