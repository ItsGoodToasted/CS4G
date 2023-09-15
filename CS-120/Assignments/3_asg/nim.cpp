  /*  The game of NIM 
 */

//Change the winning and loses messages
//Have the program begin by print the rules of the game
//Include running commentary in the game - think of typical sports commentary.
//Replace the magic number from the code. Make them variables
//Make the computer play perfectly
//Put the game in a loop and ask the player to play again
// Add a two player mode
 #include<iostream>     // include two libraries
 #include<cstdlib>
 #include<string>

 using namespace std;

 void rules(int min, int max, int pile) {
   cout << "\nRules:" << endl;
   cout << "1. The game begins with a pile of " << pile << " sticks" << endl;
   cout << "2. Each player takes turn removing " << min << "-" << max << " sticks from the pile." << endl;
   cout << "3. To win the game you must be the last player to remove a stick." << endl;

 }

 void commentary(int pile) {
   //Edit these so they don't repeat. It's annoying.
      if (pile >= 21 && pile <= 33 && ((pile % 3) == 0)) {
         cout << "It's too early to call. This is anyone's game." << endl;
      } else if (pile >= 10 && pile <= 20 && ((pile % 4) == 0) ) {
         cout << "Things are heating up in the NIM arena." << endl;   
      } else if (pile <= 5) {
         cout << "It's getting down to the wire! I sense victory." << endl;
      } else if (pile >= 50) {
         cout << "Settle in folks. We're in for a long one." << endl;
      }
   }

   int settings(int min, int max, int pile) {
      
   }
 int main() {           // main() starts the actual program 
 
   
    // ---------------- Variable declarations ---------------------
    int num_objects = 23;
    int move_max = 3;
    int move_min = 1; 
    int current_player = 1;
    int move, choice, settings;

    char expert_choice;
    bool expert = false;
    string name = "player 1";
    
    // ----------- Beginning of the main game loop ----------------
    do {    
      cout << R"(
          _     _   _____   _       _
         |  \  | | |_   _| |  \   /| |
         | | \ | |   | |   | | \_/ | |
         | |\ \| |  _| |_  | | \_/ | |
         |_| \_ _| |_____| |_|     |_|
      )" << endl;  
      cout << "1. New Game (Normal)" << endl;
      cout << "2. Settings" << endl;
      cout << "3. Quit" << endl;
      cout << "Make your choice:" << endl;
      cin >> choice;

      switch(choice) {
         case 1:
            rules(move_min, move_max, num_objects);
            cout << "\nPlease enter your name:" << endl;
            cin.ignore();
            getline(cin, name);

            cout << "Want to play on expert difficulty? (y/n)" << endl;
            cin >> expert_choice;
            expert = (expert_choice == 'y');

            do {
               
               if (current_player == 1) {    // conditional: if
                     cout << "Player 1 enter your move (1-3): ";  // output
                     cin >> move;                 // input
                     while (move < 1 || move > 3 || move > num_objects){
                        cout << "Illegal move. \nEnter a new move (1-3): ";
                        cin >> move;
                     }
               } else {                          // else part of conditional
                     do {                         // make sure move is legal
                        move =  1+ rand() % 3;    // random computer move
                     } while (move < 1 || move > 3 || move > num_objects);
                     cout << "Computer removed " << move << endl;
               }
               num_objects = num_objects - move;  // implement the move
               commentary(num_objects);
               cout << num_objects << " objects remaining.\n";
               current_player = (current_player + 1) % 2;  // switch players
            } while (num_objects > 0);                    
            // ------------  end of the game loop --------------------------
            if (current_player == 1) {
               cout << "A great performance and even greater victory from " << name << endl;
            } else {
               cout << "In a crushing defeat, the computer claims a win against "<< name << endl;
               cout << "Better luck next time" << endl;

            }
            
            break;
         
         case 2:
            cout << "1. WARNING: Changing settings from defaults is not reccomended for standard play" << endl;
            cout << "1. Size of pile (current setting: " << num_objects << ')' << endl;
            cout << "2. Minimum move (current setting: " << move_min << ')' << endl;
            cout << "3. Maximum move (current setting: " << move_max << ')' << endl;
            cout << "4. Return" << endl;
            cout << "Select the options you wish to change:" << endl;
            cin >> settings;

            switch(settings) {
               case 1:
                  cout << "Enter the new pile size (Max 99):" << endl;
                  cin >> num_objects;
                  if(num_objects > 99) {
                     cout << "You really think you're gonna play a game of 99 NIM?" << endl;
                     num_objects = 23;
                  } else if(num_objects <= 1) {
                     cout << "That's cheating" << endl;
                     num_objects = 23;
                  }
                  break;
                  
               case 2:
                  cout << "Enter the new min:" << endl;
                  cin >> move_min;
                  if(move_min < 1 || move_min >= move_max || move_min == num_objects) {
                     cout << "That's not a valid minimum move" << endl;
                  }
                  break;

               case 3:
                  cout << "Enter a new max:" << endl;
                  cin >> move_max;
                  if(move_max < 1 || move_max <= move_min || move_max == num_objects) {
                     cout << "That's not a valid maximum move" << endl;
                  }
                  break;

               case 4:
                  break;

               default:
                  cout << "Invalid selection" << endl;
            }
            
            break;

         case 3:
            cout << "Thanks for playing NIM!" << endl;
            return 0;
         
         default:
            cout << "Invalid selection" << endl;
            break;

      }
    } while(true);

    return 0;
}
