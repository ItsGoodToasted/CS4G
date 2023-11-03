// Nigel Lee
// CS-120-08
// Lab 10
// 10/30/2023 

#include <iostream>
#include <cmath>

int main() {
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
            art[r][c] = int(5 + 3*sin(r/2.0) + 2 * cos(c/2.0));
        }
    }
    //iterate between rows
    for (int r = 0; r < rows; r++) { 
        //iterate between cells in rows
        for (int c = 0; c < columns; c++) {
            //art print switch
            switch (art[r][c]) {
                case 0:
                    std:: cout << ' ';
                    break;
                case 1:
                    std:: cout << '.';
                    break;
                case 2:
                    std:: cout << ',';
                    break;
                case 3:
                    std:: cout << ';';
                    break;
                case 4:
                    std:: cout << '*';
                    break;
                case 5:
                    std:: cout << 'l';
                    break;
                case 6:
                    std:: cout << 'p';
                    break;
                case 7:
                    std:: cout << 'P';
                    break;
                case 8:
                    std:: cout << 'A';
                    break;
                case 9:
                    std:: cout << 'H';
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