


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
    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "Impsum Lorum" << std::endl;
        case 2:
            std::cout << "Impsum Lorum" << std::endl;
        case 3:
            std::cout << "Impsum Lorum" << std::endl;
        case 4:
            std::cout << "Impsum Lorum" << std::endl;
            player.room = 2;
        case 5:
            std::cout << "Impsum Lorum" << std::endl; 
    }

}

int kitchen_2(Traits& player) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int bedRoom_3(Traits& player) {
    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }

}

int bathRoom_4(Traits& player) {
    
   int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int backYard_5(Traits& player) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int outcrop_6(Traits& player) {

   int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int ritualRoom_7(Traits& player) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}


int cellar_8(Traits& player) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int bossRoom_9(Traits& player, int boss_health) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

int wellBottom_10(Traits& player) {

    int choice = 0;
    std::cout << "Ipsum Lorum" << std::endl;
    std::cout << "You notice:\n(1) Couch\n (2) Front Door\n(3) Coffee Table\n" << std::endl;
    if(player.secrets[3]) {
        std::cout << "Exits Available: (4) Kitchen\n (5) Bookshelf Passage" << std::endl;
    } else{
        std::cout << "Exits Available: (4) Kitchen" << std::endl;
    }
    std::cin >> choice;

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
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
                outcrop_6(player);
                break;
            case 7:
                ritualRoom_7(player);
                break;
            case 8:
                cellar_8(player);
                break;
            case 9:
                bossRoom_9(player, agnes_health);
            case 10:
                wellBottom_10(player);
            default:



        }
    
    
    } while(true);





