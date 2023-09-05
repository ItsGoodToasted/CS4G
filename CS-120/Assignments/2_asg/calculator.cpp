#include <iostream>
#include <cstring>


double calculate(double num1, double num2, char op) {
    double result;
    if(op == '+') {
        result = num1 + num2;
    } else if(op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/' ) {
        result = num1 / num2;
    } else if (op == '^') {
        result = 1; 
        for (int i = 0; i < num2; i++) {
            result *= num1;
        }
    }
return result;
}

int main() {
    double x, y;
    char operation;

    char support[] = "\nAddition (+)\nSubtraction (-)\nMultiplication (*)\nDivision (/)\nexponentials (^)\n";
    double result = 0.00000;
    std::cout << "Welcome to the basic calculator.\n" << std::endl;
    while(true){
        std::cout << "Start by giving me some information:" << std::endl;
        std::cout << "What is your first number?" << std::endl;
        std::cin >> x;
        std::cout << "And the second number?" << std::endl;
        std::cin >> y;
        std::cout << "What operation will I be performing on these today:" << support << std::endl;
        std::cin >> operation;

        if (operation == '/'&& y == 0) {
            std::cout << "You can't divide by 0." << std::endl;
            continue;
        } else {
            result = calculate(x, y, operation);
            std::cout << "Your result is : " << x << " " << operation << " " << y << " = " << result << std::endl;
            break;           
        }
    }
    return 0;
}