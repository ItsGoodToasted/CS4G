#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int importantThing = 5;
int collectedMagicalItems = 0;

struct MagicalItem {
    std::string name;
    int bonus;
};

std::vector<MagicalItem> magicalItems = {
    {"Glowing Amulet", 2},
    {"Winged Boots", 3},
    {"Crystal Elixir", 4}
};

int RollDie() {
    return rand() % 6 + 1;
}

int ExploreForest(int distance, int roll) {
    switch (roll) {
        case 1:
            std::cout << "You rolled a 1.\n";
            std::cout << "A mischievous fairy played a prank on you, causing you to lose 2 important things!\n";
            importantThing -= 2;
            distance += 1;
            break;
        case 2:
        case 3:
            std::cout << "You rolled a " << roll << ".\n";
            std::cout << "You stumbled upon a mystical spring and restored 2 important things.\n";
            importantThing += 2;
            distance += roll;
            break;
        case 4:
        case 5:
            std::cout << "You rolled a " << roll << ".\n";
            std::cout << "You encountered a mischievous spirit, and it stole 1 important thing.\n";
            importantThing -= 1;
            distance += roll;
            break;
        case 6:
            std::cout << "You rolled a 6.\n";
            std::cout << "You found a hidden glade with glowing mushrooms, gaining 3 important things!\n";
            importantThing += 3;
            distance += 2;
            break;
    }
    return distance;
}

void CollectMagicalItem() {
    int randomIndex = rand() % magicalItems.size();
    MagicalItem item = magicalItems[randomIndex];
    collectedMagicalItems++;
    std::cout << "You discovered a " << item.name << " and gained " << item.bonus << " important things!\n";
    importantThing += item.bonus;
}

void GameOver() {
    std::cout << "You ran out of magical energy and couldn't explore further.\n";
    std::cout << "Your journey ends here. Better luck next time!\n";
}

int main() {
    srand(time(0));
    
    std::cout << "Welcome to the Enchanted Forest Adventure!\n";
    std::cout << "You have embarked on a quest to find the legendary Crystal of Wonders.\n";
    std::cout << "You have made it 0 distance.\n";
    std::cout << "And have " << importantThing << " magical energy left.\n";

    while (importantThing > 0) {
        std::cout << "Press Enter to roll your next move.";
        std::cin.get();

        int roll = RollDie();
        int distance = ExploreForest(0, roll);
        
        if (collectedMagicalItems < 3) {
            std::cout << "You have made it " << distance << " distance into the Enchanted Forest.\n";
            std::cout << "And have " << importantThing << " magical energy left.\n";
        }
        else {
            std::cout << "You have made it " << distance << " distance into the Enchanted Forest.\n";
            std::cout << "And have collected all 3 magical items!\n";
        }

        if (distance >= 30 && collectedMagicalItems >= 3) {
            std::cout << "Congratulations! You've found the legendary Crystal of Wonders!\n";
            std::cout << "Your quest is complete, and you are the hero of the Enchanted Forest!\n";
            break;
        }

        if (roll == 6 && collectedMagicalItems < 3) {
            CollectMagicalItem();
        }
    }

    if (importantThing <= 0) {
        GameOver();
    }

    return 0;
}