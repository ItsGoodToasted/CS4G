1.
a. To keep things from using with width and height that aren't the rectangle class. 
b. Defines what a rectangle is for the class.
c. Area of the rectangle: 50

2. 
   ```cpp
class Student {
private:
	std::string name;
	int age;
	std::string major;
	
public:
	Student(const std::string& studentName, int studentAge,         const std::string& studentMajor) {
	name = studentName;
	age = studentAge;
	major = studentMajor;
	}
	
void displayDetails() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Major: " << major << std::endl;
	}
};    
   
   ```

3.
```cpp
class BankAccount {
private:
	std::string accountNumber;
	double balance;
	
public:
	BankAccount() {
	accountNumber = "";
	balance = 0.0;
	}
void deposit(double amount) {
	balance += amount;
	std::cout << "Deposit of $" << amount << "successful." << std::endl;	
}
void withdraw(double amount) {
if (balance >= amount) {
	balance -= amount;
	std::cout << "Withdrawal of $" << amount << " successful." << std::endl;
	} 
	else {
		std::cout << "No fucking money. Withdrawal forbidden." << std::endl; 
		}
	}
}
```
4.
a.
Model: Toyota Camry, Year: 2020
Model: Toyota Camry, Year: 2022

b. 
Car2 is taking on the properties of car1. In a very short statement, you can copy a large amount of data from one variable to another. Car1 is an object acting as a collection of information, with the class of the car outlining the traits that something in the car class can take on.

c. Default accessibility. Members in a struct are by default public, where as class members are by default private. A struct would be chosen over a class depending on preference and project conventions a team would want to use.