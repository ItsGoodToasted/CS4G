#include <iostream>
#include <string>
#include <algorithm>

int main() {
    //variables to hold 3 names
    std::string firstName, middleName, lastName;
    //variables for two name variations
    std::string firstMiddleLast, lastFirstMiddle;

    std::cout << "What is your first name?" << std::endl;
    std::getline(std::cin, firstName);

    std::cout << "What is your middle name? (press 'enter' for no middle name)" << std::endl;
    std::getline(std::cin, middleName);

    std::cout << "What is your last name?" << std::endl;
    std::getline(std::cin, lastName);

    //tests if middle name exists and modifies name variations
    if(!middleName.empty()) {
        firstMiddleLast = firstName + " " + middleName + " " + lastName;
        lastFirstMiddle = lastName + ", " + firstName + " " + middleName;
    } else {
        firstMiddleLast = firstName + " " + lastName;
        lastFirstMiddle = lastName + ", " + firstName;

    }

    std::cout << "Full Name: " << firstMiddleLast << std::endl;
    std::cout << "Last, First Middle: " << lastFirstMiddle << std::endl;

    //create array of 3 initial names
    std::string sortedNames[3] = {firstName, middleName, lastName};
    //sort array of names alphabetically
    std::sort(std::begin(sortedNames), std::end(sortedNames));
    std::cout << "Alphabetically: ";
    //print only elements of the array that aren't empty
    for (int i = 0; i < 3; i++) {
        if(!sortedNames[i].empty()) {
            std::cout << sortedNames[i] + " ";
        }
    }
    
    return 0;
}