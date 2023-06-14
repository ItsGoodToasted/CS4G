#include <iostream> 
struct Color {
	int r, g, b;
};

int myFunction(int a, int b) {
	a = a + b;
	return a;
}

void myFunction2(Color& color, int blue) {
	color.b = blue;
	std::cout << "Color: (r =" << color.r << ", g = " << color.g << ", b = " << color.b << ")" << std::endl;
	return;
}

int main() {
	int someValue = 1;
	int someOtherValue = 6;
	// At this point, someValue is 1 and someOtherValue is 6. No need to log here.
	int result = myFunction(someValue, someOtherValue);
	std::cout << "Result: " << result << std::endl;
	std::cout << "SomeValue: " << someValue << std::endl;

	int blueValue = 159;
	Color myColor = { 0, 0, 0 };
	// At this point, color.r = 0, color.g = 0, color.b = 0. No need to log here.
	myFunction2(myColor, blueValue);
	std::cout << "Color: (r =" << myColor.r << ", g = " << myColor.g << ", b = " << myColor.b << ")" << std::endl;
}