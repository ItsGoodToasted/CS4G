#include <stdio.h>
#include <stdlib.h>

int findLargestElement(int* arr, int size) {
    int largest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int size;
    printf("Enter the size of your array: ");
    scanf_s("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed! God fucking damn it.\n");
        return 1;
    }
    
    printf("Enter the elements of your array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf_s("%d", &array[i]);
    }

    int largest = findLargestElement(array, size);
    printf("The largest element is: %d\n", largest);

    free(array);

    return 0;
}