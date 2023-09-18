


// Each Room must be its own function, with a match text description and interactables
// Each room should have an integer value assoicated with it
// Each room should return an int value to know where you're going. If you can't go
// it should return to where you are
// The main() function should have a switch function to select the room
// The rooms should change when entered again
// There should be some global score variable like gold or oxygen remaining
// Include a final boss of sorts somehow

#include <iostream>
#include <string>
#include <fstream>

int player_health = 100;
int secrets_found;
int agnes_health = 100;
int bandage = 0;
char secrets[5];

void mainMenu(int currentRoom) {
    std::cout << "Hell House\n" << std::endl; //Put art here
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl; // Consider scrapping
    std::cout << "3. Quit" << std::endl;

    int menu_choice;
    std::cin >> menu_choice;

    switch(menu_choice) {
        case 1:
            currentRoom = 1;
        case 2:

        case 3:
    }
}


void loadGame(int currentRoom, int health, int bandages, char* secrets[5], bool totem ) {}

void saveGame(int currentRoom, int health, int secrets) {}

void displaySecrets(char secrets[5]){}

int livingRoom_1(){}

int kitchen_2(){}

int bedRoom_3(){}

int bathRoom_4(){}

int backYard_5(){}

int outcrop_5(){}

int cellar_6(){}

int bossRoom_7(){}

int wellBottom_8(){}

int main() {

    do { //Main Menu Loop

    }


}





