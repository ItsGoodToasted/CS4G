#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<std::string> countries;

	countries.push_back("China");
	countries.push_back("Rhodesia");
	countries.push_back("Brazil");
	countries.push_back("Vietnam");
	countries.push_back("Romania");

	std::sort(countries.begin(), countries.end());

	std::cout << "Your sorted list of countries, sir:" << std::endl;
	for (const auto& country : countries) {
		std::cout << country << std::endl;
	}
	return 0;
}