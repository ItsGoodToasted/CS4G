#include <iostream>
#include <ctime>
#include <cstdlib>

int playerScore = 0;
bool roomVisited[7] = {false};

// Function prototypes Chat
//int room1(); 
//int room2();
//int room3();
//int room4();
//int room5();
//int room6();
//int room7();
int getRandomEvent() {
    return rand() % 3;
}

void printScore() {
    std::cout << "You have " << playerScore << " gold." << std::endl;
}

void displayWinMessage() {
    std::cout << "Congratulations! You've collected all the gold and won the game!" << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr));

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
            case 7:
                currentRoom = room7();
                break;
        }

        if (playerScore >= 20) {
            displayWinMessage();
            break;
        }
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

int room1() {
    if (!roomVisited[1]) {
        std::cout << "You find yourself in a dense forest. You spot a shiny coin on the ground." << std::endl;
        playerScore++;
        roomVisited[1] = true;
    } else {
        std::cout << "You are back in the forest. It's the same place you visited earlier." << std::endl;
    }

    printScore();

    std::cout << "You can go North (2) or East (3)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 2 || choice == 3) ? choice : 1;
}

int room2() {
    if (!roomVisited[2]) {
        std::cout << "You enter a cave. A friendly gnome gives you a bag of coins!" << std::endl;
        playerScore += 5;
        roomVisited[2] = true;
    } else {
        std::cout << "You are back in the gnome's cave. He welcomes you again." << std::endl;
    }

    printScore();

    std::cout << "You can go South (1), North (4), or West (6)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 1 || choice == 4 || choice == 6) ? choice : 2;
}

int room3() {
    std::cout << "You are in a castle courtyard. There's a drawbridge to the North." << std::endl;
    printScore();

    std::cout << "You can go North (5) or West (1)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 5 || choice == 1) ? choice : 3;
}

int room4() {
    if (!roomVisited[4]) {
        std::cout << "You find yourself in a spooky graveyard. You see an old gravestone with a gold coin." << std::endl;
        playerScore++;
        roomVisited[4] = true;
    } else {
        std::cout << "You are back in the graveyard. The gravestone remains unchanged." << std::endl;
    }

    printScore();

    std::cout << "You can go South (2) or East (5)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 2 || choice == 5) ? choice : 4;
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

    std::cout << "You can go South (3) or East (4)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 3 || choice == 4) ? choice : 5;
}

int room6() {
    std::cout << "You are in a hidden chamber. You see a locked door to the East." << std::endl;
    printScore();

    std::cout << "You can go East (2)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 2) ? choice : 6;
}

int room7() {
    std::cout << "You've reached the edge of a cliff. There's nowhere to go from here." << std::endl;
    printScore();

    std::cout << "You can only go back (2)." << std::endl;
    int choice;
    std::cin >> choice;

    return (choice == 2) ? choice : 7;
}