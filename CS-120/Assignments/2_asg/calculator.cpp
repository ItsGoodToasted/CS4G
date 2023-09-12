// Nigel Lee
// CS-120-08
// Assignment 2
// 09/08/2023

/* Description:
   A basic calculator capable of 5 different operations on 2 numbers.
*/

/* Extra work: 
 * Added the ability to calculate exponentials.
 * Changed input method from a numbered list to direct input of operator.
 * Ensured divison by 0 does not result in the end of the application
*/


#include <iostream>
#include <cstring>

// Seperate function for calculations to clean up main()
double calculate(double num1, double num2, char op) { // Use
    double result;
    // If statement uses operator in place of numbered list selection to closer resemble a calculator.
    if(op == '+') {
        result = num1 + num2;
    } else if(op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/' ) {
        result = num1 / num2;
    } else if (op == '^') { 
        // Ensures values to the power of 0 equal 1.
        result = 1; 
        // Alternative to using the cmath libary only for exponentials.
        for (int i = 0; i < num2; i++) {
            result *= num1;
        }
    }
    return result;
}

int main() {
    double x, y;
    char operation;
    // Stored string of supported operations for easy editing
    char support[] = "\nAddition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nexponentials (^)\n";

    double result;
    std::cout << "Welcome to the basic calculator." << std::endl;
    std::cout << "This calculator currently supports 5 different operations on 2 operands." << std::endl;
    std::cout << "Let's get started." << std::endl;
    // Loop to ensure division by 0 does not require restarting the program
    while(true){
        std::cout << "Give me some information:" << std::endl;
        std::cout << "What is your first number?" << std::endl;
        std::cin >> x;
        std::cout << "And the second number?" << std::endl;
        std::cin >> y;
        std::cout << "What operation will I be performing on these today:\n(e.g. input \"/\" for division)" << support << std::endl;
        std::cin >> operation;
        // Checks if user has attempted division by zero
        if (operation == '/'&& y == 0) {
            std::cout << "You can't divide by 0. Let's try again." << std::endl;
            continue;
        }
        // Calls the calculate() function to perform user's desired operation
        result = calculate(x, y, operation);
        std::cout << "Your result is : " << x << " " << operation << " " << y << " = " << result << std::endl;
        break;        
    }
    return 0;          
}
