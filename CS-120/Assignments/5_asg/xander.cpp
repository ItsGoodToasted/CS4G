// Nigel Lee
// CS-120-08
// Assignment 5
// 09/29/2023 


/*  A simple adventure game where you journey on a quest to become a wizard.  
 */

/* Extra work:
No extra work added.
 */
#include <iostream>
#include <cstdlib>

int soul_remaining = 100; //Global variable for soul storage

void progress(int mag, int soul) { //reports current user resources
    std::cout << "You've attained " << mag << " percent magical energy"<< std::endl;
    std::cout << "You have " << soul  << " percent of your soul left." << std::endl;
}
int areaOne(int &soul) {
    std::cout << "You come across a strange, glowing berry in a forest." << std::endl;
    std::cout << "Consuming it, you glimpse briefly into the Weave All Things" << std::endl;
    soul = soul - 5;
    int magic = 15;
    std::cout << "You feel energized. +5 Magic" << std::endl;
    std::cout << "Your soul tingles. -10 Soul" << std::endl;
    
    return magic;

}

int areaTwo(int &soul) {
    std::cout << "You find a magic ritual site in a canyon." << std::endl;
    std::cout << "Offering your soul, you tap into primal sources of magic" << std::endl;
    soul = soul - 10;
    int magic = 15;
    std::cout << "You've achieved new insights. +15 Magic" << std::endl;
    std::cout << "You're soul strains in discomfort'. -10 Soul" << std::endl;
    
    return magic;
}

int areaThree(int &soul) {
    std::cout << "You stop for a moment and gaze into the starry night sky" << std::endl;
    std::cout << "Recognizing the patterns in the celestial unknown, you gleam astral knowledge." << std::endl;
    soul = soul + 10;
    int magic = 10;
    std::cout << "Your intelligence is inspiring. +10 Magic" << std::endl;
    std::cout << "Your soul feels heavier. +10 Soul" << std::endl;
    
    return magic;
}

int areaFour(int &soul) {
    std::cout << "A demon approaches you on your path." << std::endl;
    std::cout << "Fooled by his offers of power, you accept a pact to trade part of your soul" << std::endl;
    soul = soul - 20;
    int magic = - 5;
    std::cout << "The demon's tricks leave you weak. -5 Magic" << std::endl;
    std::cout << "Your soul screams in pain. -20 Soul" << std::endl;
    
    return magic;
}

int areaFive(int &soul) {
    std::cout << "You stumble into a village of gnomes who welcome you with glee." << std::endl;
    std::cout << "In your short stay, you study their arcane trickery." << std::endl;
    soul = soul - 1;
    int magic = 2;
    std::cout << "You've learned a new jinx. +2 Magic" << std::endl;
    std::cout << "Your devious behavior wounds you. -1 Soul" << std::endl;
    
    return magic;
}

int areaSix(int &soul) {
    std::cout << "You find an injured fairy and offer to carry it to safety." << std::endl;
    std::cout << "As thanks for your efforts, it soothes your ethereal wounds" << std::endl;
    soul = soul + 10;
    int magic = 0;
    std::cout << "You failed to learn anything meaningful. +0 Magic" << std::endl;
    std::cout << "Your spirit feels at ease. +10 Soul" << std::endl;
    
    return magic;
}

int areaSeven(int &soul) {
    std::cout << "You discover a magical door to the Great Astral Library." << std::endl;
    std::cout << "You sneak a peak at Forbidden Magic for Dummies: Vol VII." << std::endl;
    soul = soul - 5;
    int magic = 10;
    std::cout << "You add a few new spells to your repetoire. +5 Magic" << std::endl;
    std::cout << "You read a book for dummies and feel a little insulted. -10 Soul" << std::endl;
    
    return magic;
}
int main() {
    bool quit = 0;
    int magic_gained = 0;
    std::cout << "You are the great Xander Darkspell, a fearsome student of magic hungry for knowledge." << std::endl;
    std::cout << "Your quest: Became a powerful wizard with a sick looking orb and a cool tower." << std::endl;
    std::cout << "Journey the world and gather magic to reach your dream." << std::endl;
    std::cout << "Tread with caution, for you risk losing your soul in your greed." << std::endl;

    

    do {
        srand(time(0)); // seed rand using time
        int dice = rand() % 7 + 1; // roll 1d6
        if(soul_remaining > 100) { //ensures soul cannot exceed 100
            std::cout << "Your body cannot contain more than 100 percent of a soul." << std::endl;
            std::cout << "The excess spiritual energy disperses. -" << soul_remaining - 100 << " soul" << std::endl; 
            soul_remaining = 100;
            continue;
        }
        progress(magic_gained, soul_remaining); //update user with progress

        if(magic_gained >= 100) { //checks win connect
            std::cout << "You, the great Xander Darkspell, have attained ultimate power." << std::endl;
            std::cout << "The knights who bullied you now look on in fear at your supreme intellect." << std::endl;
            std::cout << "GOOD END" << std::endl;
            quit = 1;
            break;
        } else if(soul_remaining <= 0) { //check lose condition
            std::cout << "Your soul is left hollow and the world of wizardy is lost to you." << std::endl;
            std::cout << "Lacking a soul, you are left only one choice: Law School." << std::endl;
            std::cout << "BAD END" << std::endl;
            quit = 1;
            break;
        }

        std::cout << "Press Enter to continue onwards in your journey.";
        std::cin.ignore(); //accept user input
        std::cout << "The die of fate is cast, you roll a " << dice << std::endl;
        
        switch(dice) {// check dice roll
            case 1:
                magic_gained += areaOne(soul_remaining);
                break;
            case 2:
                magic_gained += areaTwo(soul_remaining);
                break;
            case 3:
                magic_gained += areaThree(soul_remaining);
                break;
            case 4:
                magic_gained += areaFour(soul_remaining);
                break;
            case 5:
                magic_gained += areaFive(soul_remaining);
                break;
            case 6:
                magic_gained += areaSix(soul_remaining);
                break;
            case 7:
                magic_gained += areaSeven(soul_remaining);
                break;
        }

        
    } while (!quit);
}