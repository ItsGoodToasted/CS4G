// Nigel Lee
// CS-120-08
// Assignment 3
// 09/15/2023 
 
  /*  The game of NIM: A simple game where players compete to not remove the last stick from the pile. 
 */

/* Extra work:
 * Added a toggle for computer smart moves. It will avoid losing in this mode,
   but does not play perfectly as the extra credit required.
 * Left default move min/max and pile unchanged from code, but changed all conditions
   execept commentary to reflect any legal settings the user may enter
 * Added main menu to make it feel more like a game
 * Added settings menu to allow user to alter min/max moves and pile size
 * Added ASCII art to main menu to make it feel more like a game
 * Added the ability for player to change their name


 */
 #include<iostream> // include three libraries
 #include<cstdlib>
 #include<string> // necessary for player to name themselves

 using namespace std;

 void rules(int min, int max, int pile) { //rule function clean up main game loop
   cout << "\nRules:" << endl;
   cout << "1. The game begins with a pile of " << pile << " sticks" << endl;
   cout << "2. Each player takes turn removing " << min << "-" << max << " sticks from the pile." << endl;
   cout << "3. To win the game you must be the last player to remove a stick." << endl;

 }

 void commentary(int min, int max, int pile) { //commentary function to clean up main game loop
      if (pile >= 20 && ((pile % 10) == 0)) { //displays commentary only periodically
         cout << "It's too early to call. This is anyone's game." << endl;
      } else if (pile >= 10 && pile <= 20 && ((pile % 4) == 0) ) { //displays commentary only periodically
         cout << "Things are heating up in the NIM arena." << endl;   
      } else if (pile <= max + 1 && pile >= min + 1) { // displays when victory is possible
         cout << "It's getting down to the wire! I sense victory." << endl;
      } else if (pile >= 90) { // displays if user has altered settings for a long NIM game.
         cout << "Settle in folks. We're in for a long one." << endl;
      }
   }


 int main() {// main() starts the actual program 
 
   
    // ---------------- Variable declarations ---------------------
    int num_objects = 23;
    int move_max = 3;
    int move_min = 1; 
    int current_player = 1;

   // Menu and main game variables.
    int move, menu_choice, settings;

   // Player input variables
    char expert = 'n';
    char play_again = 'n';
    string name = "player 1";
    
    // ----------- Beginning of the NIM loop ----------------
    do {// Initial loop that contains the game    
      cout << R"(
          _     _   _____   _       _
         |  \  | | |_   _| |  \   /| |
         | | \ | |   | |   | | \_/ | |
         | |\ \| |  _| |_  | | \_/ | |
         |_| \_ _| |_____| |_|     |_|
      )" << endl;  
      cout << "1. New Game" << endl;
      cout << "2. Settings" << endl;
      cout << "3. Quit" << endl;
      cout << "Make your choice:" << endl;
      cin >> menu_choice;

      switch(menu_choice) {// Main menu switch statement
         case 1: // New game
            rules(move_min, move_max, num_objects); // display rules
            cout << "\nPlease enter your name:" << endl;
            cin.ignore(); // Catch for some input causing entry to skip. Not sure what.
            getline(cin, name); // Ensure player can enter numbers as a valid name

            cout << "Want to play on expert difficulty? (y/n)" << endl; //difficulty toggle
            cin >> expert;

            do {//Loop to ask player if they want to go again
               int default_pile = num_objects; // Pile storage for repeat game
               
               do { //Game loop   

                  if (current_player == 1) { // conditional: if
                        cout << "Player 1 enter your move (" << move_min << '-' << move_max << ')' << endl; // output
                        cin >> move; // input
                        while (move < move_min || move > move_max || move > num_objects){ // make sure move is legal
                           cout << "Illegal move. \nEnter a new move (" << move_min << '-' << move_max << ')' << endl;
                           cin >> move;
                        }
                  } else { // else part of conditional
                        do { //computer move loop  
                                                
                           if(num_objects <= move_max + 1 && num_objects != move_min && expert == 'y') { // checks if victory possible and expert on
                              move = num_objects - 1; // Leave the minimum move in the pile
                            
                           } else { // alternative move if expert is not on and victory uncertain
                              move =  1 + (rand() % move_max); // random computer move
                           }    
                        } while (move < move_min || move > move_max || move > num_objects);
                        // ------------  end of the computer move loop --------------------------
                        cout << "Computer removed " << move << " sticks" << endl;
                  }
                  num_objects = num_objects - move;  // implement the move
                  commentary(move_min, move_max, num_objects); // run commentary after move calculation
                  cout << num_objects << " sticks remaining.\n";
                  current_player = (current_player + 1) % 2;  // switch players
               } while (num_objects > 0);                   
               // ------------  end of the game loop --------------------------
               if (current_player == 1) { //victory/loss message condition
                  cout << "A great performance and even greater victory from " << name << endl;
               } else {
                  cout << "In a crushing defeat, the computer claims a win against "<< name << endl;
                  cout << "Better luck next time\n" << endl;
               }           

               cout << "Want to play again with current settings? (y/n)" << endl;
               cin >> play_again;
               num_objects = default_pile; // pile reset
               
            } while (play_again == 'y');
            break; // Menu choice break
            // ------------  end of the 'go again' loop --------------------------
         case 2: //Settings
            cout << "WARNING: Changing settings from defaults is not reccomended for standard play" << endl;
            cout << "1. Size of pile (current setting: " << num_objects << ')' << endl;
            cout << "2. Minimum move (current setting: " << move_min << ')' << endl;
            cout << "3. Maximum move (current setting: " << move_max << ')' << endl;
            cout << "4. Return" << endl;
            cout << "Select the options you wish to change:" << endl;
            cin >> settings;

            switch(settings) { // Settings menu switch statement
               case 1: // Pile size
                  cout << "Enter the new pile size (Max 99):" << endl;
                  cin >> num_objects;
                  if(num_objects > 99) { // catch for absurd game lengths
                     cout << "You really think you're gonna play a game of 99 NIM?" << endl;
                     num_objects = 23; // pile size reset to default
                  } else if(num_objects <= 1) { // catch for impossible game lengths
                     cout << "You have to have a pile or there's no game" << endl;
                     num_objects = 23; // pile size reset to default
                  }
                  break; // settings break
                  
               case 2: // Min move size
                  cout << "Enter the new min:" << endl;
                  cin >> move_min;
                  if(move_min < 1 || move_min >= move_max || move_min == num_objects) { //invalid size check
                     cout << "That's not a valid minimum move" << endl;
                     move_min = 1; // reset to default
                  }
                  break; // Settings break

               case 3: // Max move size
                  cout << "Enter a new max:" << endl;
                  cin >> move_max;
                  if(move_max < 1 || move_max <= move_min || move_max >= num_objects) { //invalid size check
                     cout << "That's not a valid maximum move" << endl;
                     move_max = 3; // reset to default
                  }
                  break; // Settings break

               case 4: // Quit settings
                  break; // Settings break

               default: //Invalid menu selection
                  cout << "Invalid selection" << endl;
            }
            
            break; // Menu choice break

         case 3: // Quit NIM
            cout << "Thanks for playing NIM!" << endl;
            return 0;
         
         default: // Invalid menu selection
            cout << "Invalid selection" << endl;
            break; // Menu choice break
      }
   // ------------  end of the NIM loop --------------------------
   } while(true);
}
