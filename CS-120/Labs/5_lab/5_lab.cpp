#include<iostream>
int a, b;


void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}
int main() {
int a, b;
std::cout << "Give me an a: ";
std::cin >> a;

std::cout << "Give me a b: ";
std::cin >> b;

std::cout << "a = " << a << std::endl;
std::cout << "b = " << b << std::endl;

std::cout << "Swapping" << std::endl;
swap(a, b);

std::cout << "a = " << a << std::endl;
std::cout << "b = " << b << std::endl;
}
