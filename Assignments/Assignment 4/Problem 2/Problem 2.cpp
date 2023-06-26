#include <iostream>

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

double divide(int a, int b) {
	if (b == 0) {
		std::cout << "Are you fucking stupid?" << std::endl;
		return 0;
	}
	return static_cast<double> (a) / b;
}

int main() {
	int num1, num2;

	std::cout << "Give me a number: ";
	std::cin >> num1;

	std::cout << "Give me another number: ";
	std::cin >> num2;

	int sum = add(num1, num2);
	std::cout << "Sum: " << sum << std::endl;

	int difference = subtract(num1, num2);
	std::cout << "Difference: " << difference << std::endl;

	int product = multiply(num1, num2);
	std::cout << "Product: " << product << std::endl;

	double quotient = divide(num1, num2);
	std::cout << "Quotient: " << quotient << std::endl;

	return 0;
}