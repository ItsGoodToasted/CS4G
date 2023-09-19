


// Each Room must be its own function, with a match text description and interactables
// Each room should have an integer value assoicated with it
// Each room should return an int value to know where you're going. If you can't go
// it should return to where you are
// The main() function should have a switch function to select the room
// The rooms should change when entered again
// There should be some global score variable like gold or oxygen remaining
// Include a final boss of sorts somehow

/* TODO:
    1. Expand room functions:
        determine entry and exit
        determine flavor
        determine interactables
    2. Expand Agnes
        define combat behavior
        define dungeon entry requirements
        Ensure knife allows more damage
        Ensure Agnes health == 200
    3. Map secrets
    4. Save/Load is optional
        It's a dumb fucking idea
        But also cool

*/


#include <iostream>
#include <string>
#include <fstream>
int agnes_health = 9999;

class Traits {
    public:
        int room;
        int health = 100;
        bool secrets[5] = {0, 0, 0, 0, 0};
        int found;
        int bandage = 0;
};

void mainMenu(Traits& player) { 
    std::cout << "Hell House\n" << std::endl; //Put art here
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl; // Consider scrapping
    std::cout << "3. Quit" << std::endl;

    int menu_choice;
    std::cin >> menu_choice;

    switch(menu_choice) {
        case 1:
            player.room = 1;
            break;
        case 2:

        case 3:
    }
}


void loadGame(int currentRoom, int health, int bandages, bool totem ) {}

void saveGame(int currentRoom, int health, int secrets) {}

void displaySecrets(){

}

int livingRoom_1(Traits& player) {

}

int kitchen_2(Traits& player) {
    
}

int bedRoom_3(Traits& player) {

}

int bathRoom_4(Traits& player) {

}

int backYard_5(Traits& player) {

}

int outcrop_5(Traits& player) {

}

int cellar_6(Traits& player) {

}

int bossRoom_7(Traits& player, int boss_health) {

}

int wellBottom_8(Traits& player) {
    
}

int main() {
    Traits player;

    mainMenu(player);

    do { //Main Menu Loop
        

        switch(player.room) {
            
            case 1:
                livingRoom_1(player);
                break;
            case 2:
                kitchen_2(player);
                break;
            case 3:
                bedRoom_3(player);
                break;
            case 4:
                bathRoom_4(player);
                break;
            case 5:
                backYard_5(player);
                break;
            case 6:
                cellar_6(player);
                break;
            case 7:
                bossRoom_7(player, agnes_health);
                break;
            case 8:
                wellBottom_8(player);
                break;



        }
    
    
    } while(true);





