#include <iostream>
#include <string>
#include <array>

class Animal {
    private:
        std::string name;
        double energy; //how much energy the animal has
        int speed; // how fast it run
    public:
        void print();
        double move();
        void feed(double engy);


};

void sdrawkcab(int arr[], int length) {
    for (int i = length; i >= 0; i--) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

void invert(int arr[], int length) {
    int* temp_arr = new int[length];
    for (int i = length; i >= 0; i--) {
        temp_arr[length - i] = arr[i];
    }
    for (int i = 0; i <= length; i++) {
        arr[i] = temp_arr[i];
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
    delete temp_arr;
}

int main() {
    int array[4] = {1, 2, 3, 4};
    int length = 3;
    sdrawkcab(array, length);
    invert(array, length);

}
