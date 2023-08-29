#include <iostream>
#include <vector>

int main() {
	int size;
	std::cout << "What size you want that vector: ";
	std::cin >> size;

	std::vector<int> numbers(size);
	std::cout << "Give me some elements: ";
		for (int i = 0; i < size; i++) {
			std::cout << "Element " << (i + 1) << ": ";
			std::cin >> numbers[i];
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += numbers[i];
	}

	std::cout << "Sum of those elements: " << sum << std::endl;

	return 0;
}