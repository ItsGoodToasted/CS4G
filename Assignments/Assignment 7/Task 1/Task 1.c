#include <stdio.h>

int main() {
	int array[5] = { 10, 20, 30, 40, 50 };

	printf("Reverse this bitch:\n");
	for (int i = 4; i >= 0; i--) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}