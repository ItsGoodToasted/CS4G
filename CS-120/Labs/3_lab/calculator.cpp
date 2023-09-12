// Nigel Lee
// CS-120-08
// Lab 03: Calculator Modifications
// September 11, 2023

/* Description:
   A basic calculator capable of 6 different operations on 2 numbers.
*/

#include <iostream>
#include <cstring>
//limits library necessary validation of user input. g++ Throws errors without it.
#include <limits>

//Seperate function for calculations to clean up main()
double calculate(double num1, double num2, char op) {
    double result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break; 
        case '^':
        // Ensures values to the power of 0 equal 1.
        result = 1; 
        // Alternative to using the cmath libary only for exponentials.
        for (int i = 0; i < num2; i++) {
            result *= num1;
        }
            break;
        case 's':
            int inc = 1;
            //converting num2 value to integer before loop
            int check = num2;
            //catch for cases where user desires a sum in reverse
            if(num1 > num2) {
                inc = -1;
            }
            //sums the values between num1 and num2
            for (int i = num1; i != check + inc; i += inc) {
                result += i;
            } 
            break;
    }  
    return result;
}

int main() {
    double x, y;
    //array for operation validation and listed support for user convenience
    char operation;
    //variable for user input to run a second calculation
    char support[] = {'+', '-', '*', '/', '^', 's'};
    
    char input;

    std::cout << "Welcome to the basic calculator." << std::endl;
    std::cout << "This calculator currently supports 6 different operations on 2 operands." << std::endl;
    std::cout << "Let's get started." << std::endl;
    //main loop for calculator 
    do {
        std::cout << "Give me some information:" << std::endl;
        std::cout << "What is your first number?" << std::endl;
        //input validation to ensure to prevent non-number inputs
        while (!(std::cin >> x)) {
            
            std::cin.clear(); // clearing error flag in variable
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clearing input buffer
            std::cout << "Invalid Input. Please enter a number this time." << std::endl;
        }
        //input validation to ensure to prevent non-number inputs
        std::cout << "And the second number?" << std::endl;
        while (!(std::cin >> y)) {
            
            std::cin.clear(); // clearing error flag in variable
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clearing input buffer
            std::cout << "Invalid Input. Please enter a number this time." << std::endl;
        }
        
        bool valid = false;
        // loop for valid operator check
        while(!valid) {
            std::cout << "What operation will I be performing on these today:\n(e.g. input \"/\" for division)" << std::endl;
            //Displays supported operation array for user convenience
            for(int i = 0; i < 6; i++)
            std::cout << '(' << support[i] << ")\n";
            std::cin >> operation;
            // protection against inputs like "hello world s"
            std::cin.clear();// clearing error flag in variable
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// clearing input buffer
            //validates that the user input is part of the supported operation array
            for(int i = 0; i < 6; i++) {
                if(operation == support[i]) {
                    valid = true;  
                    break;  
                }
            }

            if(!valid) {
                std::cout << "Invalid operator. Please select a valid, listed operator." << std::endl;
            }
        }
        //Division by 0 error check
        if(y == 0 && operation == '/') {
            std::cout << "Error: You cannot divide by 0." << std::endl;
        } else {
            double result = calculate(x, y, operation);
            std::cout << "Your result is : " << x << " " << operation << " " << y << " = " << result << std::endl;        
        }

        std::cout << "Do you want to run another calculation?(y/n)" << std::endl;
        std::cin >> input;
    // close of main calculator loop
    } while(input == 'y'); 

    return 0;
}

