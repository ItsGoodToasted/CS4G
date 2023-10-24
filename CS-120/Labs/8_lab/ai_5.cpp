#include <iostream>
#include <cstdlib>
#include <ctime>

int importantThing = 5;

int RollDie() {
    return rand() % 6 + 1;
}

int ExploreForest(int distance, int roll) {
    switch (roll) {
        case 1:
            std::cout << "You rolled a 1.\n";
            std::cout << "You encountered a friendly forest creature and gained 2 important things!\n";
            importantThing += 2;
            distance += 2;
            break;
        case 2:
        case 3:
            std::cout << "You rolled a " << roll << ".\n";
            std::cout << "You found a magical path, and you moved ahead by " << roll << " distance.\n";
            distance += roll;
            break;
        case 4:
        case 5:
            std::cout << "You rolled a " << roll << ".\n";
            std::cout << "You stumbled into a magical trap, losing 1 important thing.\n";
            importantThing -= 1;
            distance += roll;
            break;
        case 6:
            std::cout << "You rolled a 6.\n";
            std::cout << "You found a hidden treasure and gained 3 important things!\n";
            importantThing += 3;
            distance += 2;
            break;
    }
    return distance;
}

void GameOver() {
    std::cout << "You ran out of magical energy and couldn't explore further.\n";
    std::cout << "Your journey ends here. Better luck next time!\n";
}

int main() {
    srand(time(0));
    
    std::cout << "Welcome to the Enchanted Forest Adventure!\n";
    std::cout << "You have made it 0 distance.\n";
    std::cout << "And have " << importantThing << " magical energy left.\n";

    while (importantThing > 0) {
        std::cout << "Press Enter to roll your next move.";
        std::cin.get();

        int roll = RollDie();
        int distance = ExploreForest(0, roll);
        
        std::cout << "You have made it " << distance << " distance.\n";
        std::cout << "And have " << importantThing << " magical energy left.\n";

        if (distance >= 10) {
            std::cout << "Congratulations! You've successfully explored the entire Enchanted Forest.\n";
            break;
        }
    }

    if (importantThing <= 0) {
        GameOver();
    }

    return 0;
}