#include <iostream>
#include <vector>
#include <algorithm>

void removeOccur(std::vector<int>& numbers, int target) {
	for (auto i = numbers.begin(); i != numbers.end(); ) {
		if (*i == target) {
			i = numbers.erase(i);
		}
		else {
			i++;
		}
	}
}

int main() {
	std::vector<int> numbers;

	int size;
	std::cout << "Enter the size of your vector: ";
	std::cin >> size;

	std::cout << "Enter your vector elements: " << std::endl;
	for (int i = 0; i < size; i++) {
		int element;
		std::cout << "Element " << (i + 1) << ": ";
		std::cin >> element;
		numbers.push_back(element);
	}

	int target;
	std::cout << "Enter the number you want gone: ";
	std::cin >> target;

	removeOccur(numbers, target);

	std::cout << "Your cleansed vector sir. It's very pog." << std::endl;
	for (int number : numbers) {
		std::cout << number << " ";
	}
	std::cout << std::endl;

	return 0;
}