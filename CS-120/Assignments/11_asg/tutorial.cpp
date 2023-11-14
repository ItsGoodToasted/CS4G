// Nigel Lee
// CS-120-08
// Assignment 11
// 11/10/2023 

/*
Description:
 * This is a program for a tutorial on pointers.
 * Each section was broken up into functions to clean up the code
 * and to ensure test variables could be re-used by containing them
 * in the function scope.
 *
Extras:
 * no extras were added to this assignment
*/
#include<iostream>
//menu function
void menuSelect(int choice, bool& full);
//tutorial 0
void whatIsPointer();
//tutorial 1
void howToPointer();
//tutorial 2
void pointToVariable();
//tutorial 3
void changeValueVar();
//tutorial 4
void changeValueFunc();
void testFunc(int* ptr);
//tutorial 5
void voidPointer();
//tutorial 6
void pointerArray();

int main() {
    int choice;
    //full tutorial output variable
    bool full = false;
    std::cout << "The Basics of Pointers:" << std::endl;
    //tutorial loop
    do {
        //check if the user wants full tutorial and ignore menu text
        if(!full) {
            std::cout << "What tutorial would you like to view?" << std::endl;
            std::cout << "0.What is a Pointer\n1.Creating a Pointer\n2.Pointing to a Variable\n";
            std::cout << "3.Changing Values\n4.Changing with Functions\n5.Void Pointers\n";
            std::cout << "6.Pointers and Arrays\n7.The Full Tutorial\n8.quit" << std::endl;
            std::cin >> choice;
            menuSelect(choice, full);
        } else {
            //loop through each tutorial choice
            for (int i = 0; i < 7; i++) {
                    choice = i;
                    menuSelect(choice,full);
                }
            //reset full check
            full = false;
        } 
    } while(choice != 8);
    //end of tutorial loop 
}
//Was originally inside of main, but I wanted an easy way
//to loop through every choice at the user's request
void menuSelect(int choice, bool& full) {
    switch(choice) {
            case 0:
                whatIsPointer();
                break;
            case 1:
                howToPointer();
                break;
            case 2:
                pointToVariable();
                break;
            case 3:
                changeValueVar();
                break;
            case 4:
                changeValueFunc();
                break;
            case 5:
                voidPointer();
                break;
            case 6:
                pointerArray();
                break;
            case 7:
                full = true;
                break;
            case 8:
                break;
        }
}
/*
Each tutorial is its own function below. 
The \n are a way to force the desired formatting for each paragraph.

Code necessary for examples is indented for to make it more readable.

*/
void whatIsPointer() {
    std::cout << "WHAT IS A POINTER:\n";
    std::cout << "Consider the following line of code:\n\n";
    std::cout << "int var = 5;\nvoid myFunction(int& var) {\n}\n\n";
    std::cout << "Somewhere in memory, the hexidecimal address of var contains the value 5.\n";
    std::cout << "When myFunction uses var, it uses var's address.\n";
    std::cout << "\nA pointer is a variable which can be used to store a memory address "; 
    std::cout << "rather than the data at the address. If a pointer was created and ";
    std::cout << "\'pointed\' at var, it wouldn't store the 5, but rather where the 5 is.\n";
    std::cout << std::endl;
}
void howToPointer() {
    std::cout << "MAKING POINTERS:\n";
    std::cout << "To make a pointer in C++, the \'*\' is used with a variable declaration ";
    std::cout << "to specify it as a pointer.\nConsider this code as an example:\n\n";
    std::cout << "int *ptr\nstd::cout << ptr << std::endl;\n\n";
    std::cout << "What should this print?\n";
        int *ptr;
    std::cout <<"The answer is: " << ptr << std::endl;
    std::cout << "We can see ptr is storing a memory address.\n";
    std::cout << "However, it's not the address of the ptr. Like a normal variable, if it isn't ";
    std::cout << "initialized, the initial data stored will be garbage. The memory address ";
    std::cout << "printed is valid, but not useful to us.\n";
    std::cout << std::endl;
}
void pointToVariable() {
    std::cout << "USING POINTERS:\n";
    std::cout << "To actually \'point\' your pointer at another variable, you can use the \'=\' ";
    std::cout << "to assign it a memory address, and \'&\' on the variable to denote you want the ";
    std::cout << "the memory address data, not the value at the address.\n\n";
    std::cout << "Additionally, we must \'dereference\' the pointer to obtain the value in the address. ";
    std::cout << "This is done by attaching a * to the front of the pointer.\n\n"; 
    std::cout << "Consider the following code as an example:\n";
    std::cout << "int *ptr;\nint var = 5;\nptr = &var;\nstd::cout << *ptr << std::endl;\n\n";
    std::cout << "We declare a pointer, ptr, and a variable, var, which is storing the value 5.\n";
    std::cout << "We then use \'=\' to point ptr at the memory address of var, and * to dereference the pointer ";
    std::cout << "when we print it.\n";
    std::cout << "What should this code print?\n";
        int *ptr;
        int var = 5;
        ptr = &var;
    std::cout << "The answer is: " << *ptr << std::endl;
    std::cout << "The value printed is the value at our var variable location.\n"; 
    std::cout << std::endl;
}

void changeValueVar() {
    std::cout << "POINTERS AND MODIFYING VARIABLES:\n";
    std::cout << "If a pointer is storing the memory address of a variable, ";
    std::cout << "we can modify the values stored at that variable's address.\n";
    std::cout << "Consider the following code: \n";
    std::cout << "int var = 5;\nint *ptr;\nptr = &var;\n*ptr = 13;\n";
    std::cout << "std::cout << var << std::endl;\n\n";
    std::cout << "What should this code print?\n";
        int var = 5;
        int *ptr;
        ptr = &var;
        *ptr = 13;
    std::cout << "The answer is: " << var << std::endl;
    std::cout << "The value of var has changed, because the value in its address has changed.\n"; 
    std::cout << std::endl; 
}

void changeValueFunc() {
    std::cout << "POINTERS AND FUNCTIONS:\n";
    std::cout << "We can use pointers with functions just as we use variables. ";
    std::cout << "By passing the pointer in the function argument, we can tell a function to work ";
    std::cout << "with the data at a memory address, rather than a copy of it.\n\n";
    std::cout << "If this sounds like pass by reference, it's because it is, except now it's ";
    std::cout << "being done with pointers. Consider the following code:\n\n";
    std::cout << "void myFunction(int* ptr) {\n    *ptr = 13;\n}\n\n";
    std::cout << "int main() {\n    int var = 5;\n    myfunction(&var);\n";
    std::cout << "    std::cout << var << std::endl;\n}\n\n";
    std::cout << "What should this code print?\n";
        int var = 5;
        testFunc(&var);
    std::cout << "Answer " << var << std::endl;
    std::cout << "\nBy making a function that could accept a pointer an as argument, ";
    std::cout << "we can call the function on another, referenced variable and modify the data at ";
    std::cout << "its memory address directly.\n";
    std::cout << std::endl;
}
//tutorial function only to be called within changeValueFunc
void testFunc(int* ptr) {
    *ptr = 13;
}

void voidPointer() {
    std::cout << "VOID POINTERS:\n";
    std::cout << "We can declare 'type-less' pointers, called void pointers.\n";
    std::cout << "These pointers can be pointed at any variable, regardless of ";
    std::cout << "their type. We can do this by putting 'void' in place of the ";
    std::cout << "determined type like 'int' or 'float'\n\n";
    std::cout << "There is a catch, however: While we can assign a void pointer ";
    std::cout << "to any type, we can't dereference it. Instead, we must tell the compiler ";
    std::cout << "to convert the pointer to a specific type first to access the data. ";
    std::cout << "This can be done like so:\n\n";
    std::cout << "int var = 5;\nvoid* ptr = &var;\nstd::cout<< *(int*)ptr << std::endl;\n\n";
    std::cout << "In this code, we declare a void pointer ptr and give it the address of var. ";
    std::cout << "We then use (int*)ptr and convert the stored value to an int, and the * ";
    std::cout << "in front of (int*)ptr to dereference the conversion.\n";
    std::cout << "What should that code ouput?\n";
        int var = 5;
        void* ptr = &var;
    std::cout << "Answer: " << *(int*)ptr << std::endl;
    std::cout << "The void pointer, with type conversion, works without issue.\n";
    std::cout << std::endl;

}

void pointerArray() {
    std::cout << "POINTERS AND ARRAYS:\n";
    std::cout << "Pointers and arrays operate on similar principles. ";
    std::cout << "Array names function as pointers to the the first element ";
    std::cout << "of an array. Because of this, pointers and arrays can interact in fun ways.\n";
    std::cout << "Consider the following code:\n\n";
    std::cout << "int arr[4]= {1,21,19,92};\nint *ptr = arr\nstd::cout << *ptr << std::endl;";
    std::cout <<"\nstd::cout << ptr[3] << std::endl\nptr[2] = 3;\nstd::cout << arr[2] << std::cout.\n\n";
    std::cout << "What should this code print?\n";
    int arr[4] = {1, 21, 19, 92};
    int *ptr = arr;
    ptr[2] = 3;
    std::cout << "Answer :\n" << *ptr << '\n' << ptr[3] << '\n' << arr[2] << std::endl;
    std::cout << "We can see the interesting properties here. When assigned, the pointer ";
    std::cout << "is capable of indexing through the array and modifying it directly.";
    std::cout << "This relationship allows some interchangability between pointers and arrays.\n";
    std::cout << std::endl;
}
