// Nigel Lee
// CS-120-08
// Assignment 6
// 10/6/2023 

/* Problems done: 1, 2, 3, 4, 5.
   All problems created as functions
   Problem functions called in main switch statement.
   This was done so to have 1 file rather than 5.
*/
#include <iostream>

void problem1(int x) { // function to print #
    for(int i = 0; i < x; i++) {// count up to x
        std::cout << "#"; // print during count
    }
    std::cout << std::endl;
}

void problem2(int x){ //function to check pos,neg, or 0
    if (x > 0) {
        std::cout << "Positive";
    }
    else if (x < 0) {
        std::cout << "Negative";
    } else if (x == 0) {
        std::cout << "Zero";
    }
    std::cout << std::endl;
}

void problem3(int x) { // function to check if prime
    bool prime = true;
    if (x <= 1) { //Anything below 1 is not prime
        prime = false;
    } else {
        for (int i = 2; i <= x/2; i++) { //loop to test if prime
            if(x % i == 0) {
                prime = false;
                break;
            }
        }
    }
    if(prime) { 
        std::cout << x << " is prime";
    } else {
        std::cout << x << " is not prime";
    }
    std::cout << std::endl;
}

void problem4(int x, int y) { //function to count up to x by y
    for (int i = 0; i <= x; i += y){ //modifies i to reach x, or closest number to x
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}
void problem5(int x) { //function to print multiplication table
    for (int i = 1; i <= x; i++ ) { //Start row of table
        for (int j = 1; j <= x; j++){ //Fill for of table
            std::cout << i * j << " "; // print table
        }
        std::cout << std::endl; // next line of table
    }
    std::cout << std::endl;
}
void printQuestion(int &x, int &y, int choice) { //function for x,y input
    std::cout << "Enter your x value: ";
    std::cin >> x;
    if(choice == 4) {// y not needed for problems except 4
        std::cout << "Enter your y value: ";
        std::cin >> y;
    }
}
int main() {

    int x;
    int y;
    int choice;
    bool quit = false;

    while(!quit) { //loops program
        std::cout << "Select an option:" << std::endl;
        for (int i = 1; i <= 5; i ++) {
        std::cout << "Problem: " << i << std::endl; 
        }
        std::cout << "Quit: 0" << std::endl;
        std::cin >> choice;
        
        switch (choice) {// main menu switch
            case 0:
                quit = true;
                std::cout << "Goodbye" << std::endl;
                break;
            case 1:
                printQuestion(x, y, choice);
                problem1(x);
                break;
            case 2:
                printQuestion(x, y, choice);
                problem2(x);
                break;
            case 3:
                printQuestion(x, y, choice);
                problem3(x);
                break;
            case 4:
                do {
                printQuestion(x, y, choice);
                } while(x < 0 || y < 0); // check for negatives
                problem4(x,y);
                break;
            case 5:
                printQuestion(x, y, choice);
                problem5(x);
                break;
        }
    }
}