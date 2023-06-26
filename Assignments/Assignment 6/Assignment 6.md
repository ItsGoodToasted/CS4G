1.
a. It's the difference between giving the function a copy of the data and handing it the original. Pass-by-value does not give a function the memory address of a value, but allocates a new address with a clone of that data. Pass-by-reference just hands off the memory address.

b. Because of this copy nature, pass-by-value is great when the original data needs to remain intact, but carries the burden of creating duplicate data. If you had a large table of data a function needs to access, pass-by-value is going to yield two whole tables worth. If you aren't modifying the entire table, why give it the entire table? Pass-by-value small quantities of data you need to modify in table, and pass-by-reference data that can stay as is.

c. Conservation of memory. Ideally, you want to minimize memory usage when possible and pass-by-reference, but if what you are doing modifies values you don't want permanently changed, then you are contaminating the data for all other functions. Memory must be sacrificed and you pass-by-value.

2.
```cpp
void swapNumbers(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int num1 = 10;
	int num2 = 20;
	
	std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
	
	swapNumbers(num1, num2);
	
	std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
	
	return 0;

}
```

3.
a. A pointer is a variable with the value of an address, or put simply, a variable that says "some shit is over in this location, **here**". You aren't copying the vast stores of data in a location. You're merely yelling at say, a function, where the hell that data is.

b. Dereferencing a pointer is asking, "What is the **shit** stored in that 'here' you mentioned?" You are, much like pass-by-reference, examining a location in memory and asking for the data stored there.

c. Very similar to the usage of references in using large stores of data, however they come with the benefit of being flexible in their usage. In a large collection of data, such as several arrays, pointers can be easily modified to point to different arrays. Furthermore, that null pointer value isn't useless if it happens. It can be helpful as a tool to indicate data that was expected to be in one location isn't and is missing in error.

4.
```cpp
void cubeNumber(int& num) {
	num = num * num * num;
}

int main() {
	int number = 5;
	
	std::cout << "Prepare for " << number << " to be cubed." << std::endl;
	
	cubeNumber(number);
	
	std::cout << "It's been cubed. It's now " << number << std::endl;
	
	return 0;
}
```

5.
a. Dynamic memory allocation is allocating memory at runtime rather than a static pre-assigned amount. It allows a program to manage memory as is needed.

b. The new operator allocates memory for whatever object is being requested and throws a pointer at it saying, "Here's where your object will be." You know where it's stored, and so you know where to access it, regardless of where you are.

c. The delete keyword uses information stored during memory allocation to determine how much memory was initially stored that now needs to be return to the operating system.

6.
```cpp
int* createArray(int size) {
	if (size <= 0) {
		return nullptr;
	}
	int* array = new int[size];
	
	return array;
		
}

int main() {
	int size = 5;
	
	int* myArray = createArray(size);
	
	if (myArray != nullptr) {
		
		for (int i = 0; i < size; i++) {
			myArray[i] = i +1;
			std::cout << myArray[i] << " ";
		}
		
		delete[] myArray;
	}
	
	return 0;
}
```

7.
a. Allocated memory that is never deallocated. It sits there, cockblocking the OS from perfectly usable memory, The program will continually allocate memory, never stopping because that is what it was told to do.

b. Tell it to deallocate. Use ```delete``` and let your function know to free the memory you requested. Also, use smart pointers, which handle this deallocation automatically. 

8.
a. Yes. Temp originally pointed at the space allocated for it. When temp = data, temp now points to the array stored in data. The memory once assigned to temp was not deallocated. 

b. Memory is being double-freed. I don't know what that does. Google tells me what that does is undefined behavior. It's probably for the best we not fucking have that.

c. 
```cpp
void processData(int* data) {
	// Perform some operations with whatever is passed in for data.
}

int main() {
	int* array = new int[5];
	// Initialize and process the array
	processData(array);
	delete[] array;
	
	return 0;
}
```

d. delete[] != delete. They do not do the same thing. One can deallocate memory from new, the other from new[]. Trying to use one in place of the other is also undefined behavior. We don't do that.