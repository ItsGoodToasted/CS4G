// Nigel Lee
// CS-120-08
// Lab 10
// 10/30/2023 

#include <iostream>
#include <cmath>

int main() {
    //pi within a useful decimal place
    double pi = 3.14159265358979;
    //array size variables
    const int rows = 20;
    const int columns = 40;
    //array to store art numbers
    int art[rows][columns];
    //iterate between rows
    for (int r = 0; r < rows; r++) {
        //iterate between cells in rows
        for (int c = 0; c < columns; c++) {
            //fill arrray with equation output
            art[r][c] = int(5 + 3*sin(r/(2*pi)) + 2*cos(c/(2*pi)));
        }
    }
    //iterate between rows
    for (int r = 0; r < rows; r++) { 
        //iterate between cells in rows
        for (int c = 0; c < columns; c++) {
            //art print switch
            switch (art[r][c]) {
                case 0:
                    std:: cout << '#';
                    break;
                case 1:
                    std:: cout << '$';
                    break;
                case 2:
                    std:: cout << '*';
                    break;
                case 3:
                    std:: cout << '@';
                    break;
                case 4:
                    std:: cout << ':';
                    break;
                case 5:
                    std:: cout << ' ';
                    break;
                case 6:
                    std:: cout << '_';
                    break;
                case 7:
                    std:: cout << '-';
                    break;
                case 8:
                    std:: cout << '|';
                    break;
                case 9:
                    std:: cout << 'O';
                    break;
                default:
                    std::cout << 'x';
                    break;

            }
        }
        //switch row to be printed on
        std::cout << std::endl;
    }

}