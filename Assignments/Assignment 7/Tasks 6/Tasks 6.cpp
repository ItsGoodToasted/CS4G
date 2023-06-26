#include <iostream>
#include <vector>
#include <algorithm>

void printUnique(const std::vector<int>& vec1, const std::vector<int>& vec2) {
	std::vector<int> unique;

	for (int num1 : vec1) {
		for (int num2 : vec2) {
			int product = num1 * num2;
			if (std::find(unique.begin(), unique.end(), product) == unique.end()) {
				unique.push_back(product);
			}
		}
	}

	for (int product : unique) {
		std::cout << product << " ";
	}
	std::cout << std::endl;
}

int main() {
	
	std::vector<int> vec1;
	std::vector<int> vec2;

	int size1, size2;

	std::cout << "Enter the size of the first vector: ";
	std::cin >> size1;

	std::cout << "Enter the elements in the first vector: " << std::endl;
	for (int i = 0; i < size1; i++) {
		int element;
		std::cout << "Element " << (i + 1) << ": ";
		std::cin >> element;
		vec1.push_back(element);
	}

	std::cout << "Enter the size of the second vector: ";
	std::cin >> size2;

	std::cout << "Enter the elements in the second vector: " << std::endl;
	for (int i = 0; i < size2; i++) {
		int element;
		std::cout << "Element " << (i + 1) << ": ";
		std::cin >> element;
		vec2.push_back(element);
	}

	std::cout << "Unique products of each possible pairwise combination between your two vectors: " << std::endl;
	printUnique(vec1, vec2);
}