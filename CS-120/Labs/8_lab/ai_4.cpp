#include <iostream>

// Global variables
int playerScore = 0;
bool roomVisited[6] = {false};

// Function prototypes
int room1();
int room2();
int room3();
int room4();
int room5();
int room6();

void printScore() {
    std::cout << "You have " << playerScore << " gold." << std::endl;
}

int main() {
    int currentRoom = 1;

    std::cout << "Welcome to the Text Adventure Game!" << std::endl;
    
    while (currentRoom != 0) {
        switch (currentRoom) {
            case 1:
                currentRoom = room1();
                break;
            case 2:
                currentRoom = room2();
                break;
            case 3:
                currentRoom = room3();
                break;
            case 4:
                currentRoom = room4();
                break;
            case 5:
                currentRoom = room5();
                break;
            case 6:
                currentRoom = room6();
                break;
        }
    }
    
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

int room1() {
    if (!roomVisited[1]) {
        std::cout << "You are in a forest. You see a shiny coin on the ground." << std::endl;
        playerScore++;
        roomVisited[1] = true;
    } else {
        std::cout << "You are back in the forest. It's the same place you visited earlier." << std::endl;
    }

    printScore();

    std::cout << "You can go North (1) or East (3)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}

int room2() {
    if (!roomVisited[2]) {
        std::cout << "You are in a dark room. You find a torch on the wall." << std::endl;
        playerScore++;
        roomVisited[2] = true;
    } else {
        std::cout << "You are back in the dark room. It's the same place you visited earlier." << std::endl;
    }

    printScore();

    std::cout << "You can go North (1) or Down (5)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}

int room3() {
    std::cout << "You are in a castle courtyard. There's a drawbridge to the North." << std::endl;
    printScore();

    std::cout << "You can go North (1) or West (2)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}

int room4() {
    std::cout << "You are in a mysterious cave. It's dark and damp." << std::endl;
    printScore();

    std::cout << "You can go East (3) or Down (6)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}

int room5() {
    if (!roomVisited[5]) {
        std::cout << "You are in a treasure room. You find a pile of gold coins!" << std::endl;
        playerScore += 10;
        roomVisited[5] = true;
    } else {
        std::cout << "You are back in the treasure room. It's the same place you visited earlier." << std::endl;
    }

    printScore();

    std::cout << "You can go Up (2) or Down (4)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}

int room6() {
    std::cout << "You are in a hidden chamber. You see a locked door to the East." << std::endl;
    printScore();

    std::cout << "You can go Up (4) or East (3)." << std::endl;
    int choice;
    std::cin >> choice;

    return choice;
}