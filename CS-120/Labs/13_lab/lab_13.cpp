// Nigel Lee
// CS-120-08
// Lab 13
// 11/27/2023 

#include <iostream>
#include <string>
//for required strcmp()
#include <cstdlib> 
//for absolute value requirement
#include <cmath>

//create a main that accepts arguments.
int main(int argc, char *argv[]) {
    //verify 4 arguments present
    if (argc != 4) {
        std::cout << "Usage: calc num1 operator num2\n";
        //return that input is incorrect
        return 1;
    }
    //declare variables and convert necessary 'strings'
    double num1 = std::stod(argv[1]);
    double num2 = std::stod(argv[3]);
    //use strcmp to compare strings, 0 meaning the strings are equal
    //trigger user's entered operator on the doubles
    if (strcmp(argv[2], "+") == 0) {
            std::cout << num1 + num2 << "\n";
    } else if (strcmp(argv[2], "-") == 0) {
            std::cout << num1 - num2 << "\n";
    } else if (strcmp(argv[2], "*") == 0) {
            std::cout << num1 * num2 << "\n";
    } else if (strcmp(argv[2], "/") == 0) {
        //division by zero check
        if (num2 != 0) {
            std::cout << num1 / num2 << "\n";
        } else {
            std::cout << "You can't divide by zero.\n";
        }
    //absolute value operation
    } else if (strcmp(argv[2], "a") == 0) {
            std::cout << abs(num1) << "\n";
    } else {
            std::cout << "You can't do that.\n";
    }

    return 0;
}