#include <iostream> 

void processData(int* data) {
    int* temp = new int[5];
    // Copy values from data to temp
    for (int i = 0; i < 5; ++i) {
        temp[i] = data[i];
    }
    // Perform some operations with temp
    delete[] temp;
}

int main() {
    int* array = new int[5];
    // Initialize and process the array
    processData(array);
    delete[] array;

    return 0;
}
