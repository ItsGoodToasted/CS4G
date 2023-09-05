 // Nigel Lee
 // CS-120-08
 // Assignment 1
 // 08/31/2023

/* Extra work: 
 * If-else statement to ensure user's favorite number != most disliked number.
 * Alteration to lucky formula for even-ish distribution of choices.
 * Addtional variable 'fortune' to allow for seperation of lucky number and determined fortune.
*/

/* The fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 */
#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
    int disliked;  // create a variable to store the disliked number
	int age; 	   // create a variable to store the age
	int lucky;     // create a variable to store the lucky number
	int fortune;   // create a varaible to store fortune number
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite; // user input
	cout << "Enter a number you don't like (no decimals): "; // output
	cin >> disliked;
	cout << "Enter your age (no decimals): "; // ouput
	cin >> age; // user input
	// ------------- Generate fortune and lucky number -------------
	lucky = (favorite*disliked*age);
	fortune = lucky % 4; // Even-ish distribution of fortunes
	if(lucky == 0) { // Prevents input of 0 from guaranteeing lucky == 1
		lucky = (favorite + disliked + age);
	}
	lucky = abs(lucky) * 99 % 100 + 1; // Guarantee user a number between 1 and 99.
	// ------------- Lie prevention -------------
	if( favorite == disliked) { 
		cout << R"(
    Your lies have angered the machine spirits!
                      ______
                     /      \
                    | >    < |
                    |  ~~~~  |
                    |        |
                    |/\/\/\/\|
		)" << endl;
	}
	// ------------- Fortune Output -------------
	else {
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(fortune < 0){  // For Testing: 1,2,-1 to guarantee output
		cout << R"(
    Try to be less negative.
            ________
           /        \
          |  O    O  |
          |          |
          |  \____/  |
           \________/
		)" << endl;
	}
	if(fortune == 0){ // For Testing: 1, 2, 0 to guarantee output
		cout << R"(
    Think bigger!
         |
   \   _____  /
      /  _  \
  __  | |~| | __
       \|_|/ 
    /   | |   \
		)" << endl;
	}
	if(fortune == 1 ){ // For testing: 1,3,7 to guarantee output 
		cout << R"(
   Today you should embrace technology.
           ____________________
          |  ________________  |
          | |                | |
          | |     Hello,     | |
          | |     World!     | |
          | |                | |
          | |________________| |
          |____________________|
       ____________________________
      |[*][*][*][*][*][*][*][*][*] |
      | [*][*][*][*][*][*][*][*][*]|
      |[*][*][*][*][*][*][*][*][*] |
      |____________________________|
		)" << endl;
	}
	if(fortune == 2){ // For Testing: 1, 3, 6 to guarantee output
		cout << R"(
    Today is your lucky day!
       ___            ___
      |   |          |   |
       | |            | |
       \O\            /O/
        \O\          /O/
         \O\________/O/
          \__________/	
		)" << endl;
	}
	if(fortune == 3){ // For Testing: 1, 3, 9 to guarantee output
		cout << R"(
    Your soul mate is nearby. Say, "Hi".
           _ - - _   _ - - _
          /       \ /       \
          |                 |
          \                 /
            \             /
              \         /
                \     /
                  \ /
		)" << endl;
	}
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
