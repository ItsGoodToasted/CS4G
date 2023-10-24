// Nigel Lee
// CS-120-08
// Assignment 7
// 10/13/2023 

/*
This is the basic structure for the Pet class to be used within next
week's Pet assignment.

For an additional data member of my choice, weight was chosen.
*/

#include <iostream>
#include <string>

class Pet {
    int health; //default 50
    int hunger; //default 100
    double weight; //default 40.0
    std::string name;
    std::string species; 
    void speciesSelect(std::string& species);

    public:
        void petInfo();
        void feed();
        Pet();
};

    Pet::Pet() {
        health = 50;
        hunger = 100;
        weight = 40.0;
        std::cout << "What is the name of your pet?" << std::endl;
        std::getline(std::cin, name);
        speciesSelect(species);
    }

int main() {
    std::cout << "Generating your new pet." << std::endl;
    Pet userPet;
    userPet.petInfo();
    std::cout << "Feeding the pet" << std::endl;
    userPet.feed();
    userPet.petInfo();

}

void Pet::speciesSelect(std::string& species) {
    int selection;
    //makes an array of strings that functions as both a menu and a table of species
    std::string speciesList[6] = {"Cat", "Rat", "Spider","Crow","Bat","Ghost"};
    for (int i = 0; i < 6; i++) {
        std::cout << i << '.' << speciesList[i] << std::endl;    
    }
    std::cout << "What species do you want your pet to be?" << std::endl;
    std::cin >> selection;
    species = speciesList[selection];
}

void Pet::petInfo() {
    std::cout << "Pet Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Species: " << species << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Hunger: " << hunger << std::endl; 
    std::cout << "Weight: " << weight << std::endl; 
}

void Pet::feed() {
    hunger -= 50;
    health += 25;
}




