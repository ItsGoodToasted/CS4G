// Nigel Lee
// CS-120-08
// Lab 4
// 09/18/2023 

/* A simple calculator program,
controlled by a menu and 
divided into separate functions */
#include<iostream>
#include<cmath>
using namespace std;
//---------- Function Prototypes -----------
void print_menu(); 
double get_value();
double getRadius();
double getHeight();
double divide(double,double);
double surfaceAreaCylinder(double, double);
double volumeCylinder(double,double);
double surfaceAreaCone(double, double);
//--------------  Main -------------------
int main()
{
     double operand1, operand2, answer;
     int choice, valid_choice;
     do{
           print_menu();
           cin >> choice;
           valid_choice = 1;           // assume choice is valid
           switch(choice){
             case 0:                    // program will exit
                  break;
             case 1:                    // addition
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 + operand2;
                  cout << operand1 << " + " << operand2 << " = " << answer << endl;
                  break;
              case 2:                    // division
                   operand1 = get_value();
                   operand2 = get_value();
                   answer = divide(operand1,operand2);
                   cout << operand1 << " / " << operand2 << " = " << answer << endl;
                   break;
              case 3:
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 - operand2;
                  cout << operand1 << " - " << operand2 << " = " << answer << endl;
                  break;
              case 4:
                  cout << "This is a calculator for the surface area of a cylinder" << endl;
                  operand1 = getRadius();
                  operand2 = getHeight();
                  answer = surfaceAreaCylinder(operand1, operand2);
                  cout << "Surface area of cylinder with radius " << operand1 << " and height " << operand2 << " = " << answer << endl;
                  break;
              case 5:
                  cout << "This is a calculator for the surface area of a cylinder" << endl;
                  operand1 = getRadius();
                  operand2 = getHeight();
                  answer = volumeCylinder(operand1, operand2);
                  cout << "Volume of cylinder with radius " << operand1 << " and height " << operand2 << " = " << answer << endl;
                  break;
              case 6:
                  cout << "This is a calculator for the surface area of a cylinder" << endl;
                  operand1 = getRadius();
                  operand2 = getHeight();
                  answer = surfaceAreaCone(operand1, operand2);
                  cout << "Surface area of cone with radius " << operand1 << " and height " << operand2 << " = " << answer << endl;
                  break;
              default:
                   valid_choice = 0;   // choice is invalid
                   cout << "Invalid Choice." << endl;
            }
      }while(choice != 0);    // if not 0, loop back to start
      return 0;
}

//--------------  Functions -------------------
double divide(double dividend, double divisor){
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
//----------------- get_value function ----------------
double get_value(){
      double temp_value;
      cout << "Please, enter a value: ";
      cin >> temp_value;
      cout << "Thanks." << endl;
      return temp_value;
}
double getRadius() {
      double temp_value;
      cout << "Enter the radius: ";
      cin >> temp_value;
      return temp_value;
}
double getHeight() {
      double temp_value;
      cout << "Enter a height: ";
      cin >> temp_value;
      return temp_value;
}

//-------------------- print_menu function -------------
void print_menu(){
     cout << endl;
     cout << "(1) Add" << endl;
     cout << "(2) Divide" << endl;
     cout << "(3) Subtract" << endl;
     cout << "(4) Surface Area of Cylinder" << endl;
     cout << "(5) Volume of a cylinder" << endl;
     cout << "(6) Surface Area of Cone" << endl;
     cout << "(0) Exit" << endl;
     cout << "Enter your choice: ";
}
//------------------surfaceAreaCylinder function ---------------
double surfaceAreaCylinder(double radius, double height) {
      double pi = 3.1415926;
      double temp_value;
      temp_value = 2 * ((pi * radius * height) + (pi * radius * radius));
      return temp_value;
}
//------------------volumeCylinder function ---------------
double volumeCylinder(double radius, double height) {
      double pi = 3.1415926;
      double temp_value;
      temp_value = (pi * radius * radius * height);
      return temp_value;
}
//------------------surfaceAreaCone function ---------------
double surfaceAreaCone(double radius, double height) {
      double pi = 3.1415926;
      double temp_value;
      temp_value = (pi * radius)*(radius + sqrt((height * height) + (radius * radius)));
      return temp_value;
}