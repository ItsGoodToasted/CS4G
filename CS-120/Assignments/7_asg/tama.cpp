#include <iostream>
#include <string>

class pet {
    public:
        int health; //default 100
        int hunger; //default 100
        std::string name;
        std::string species;
        std::string color;
        std::string size;
        pet();
        void speciesSelect(std::string);
        void petInfo();
        void feed();
};

    pet::pet() {
        health = 100;
        hunger = 100;

        std::cout << "What is the name of your pet?" << std::endl;
        std::getline(std::cin, name);
        speciesSelect(species);
        

    }

int main() {

}

void speciesSelect(std::string species) {
    int selection;
    std::string speciesList[6] = {"Cat", "Wolf", "Spider","Crow","Bat","Ghost"};
    for (int i = 0; i < 6; i++) {
        std::cout << i << '.' << speciesList[i] << std::endl;    
    }
    std::cout << "What species do you want your pet to be?" << std::endl;
    std::cin >> selection;
    species = speciesList[selection];
}



