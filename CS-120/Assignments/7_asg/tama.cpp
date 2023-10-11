#include <iostream>
#include <string>

class pet {
    int health; //default 100
    int hunger; //default 100
    std::string name;
    std::string species;
    std::string color;
    std::string size;

    public:
    pet();
    void speciesSelect();
    void petInfo();
    void feed();
};

    pet::pet() {
        health = 100;
        hunger = 100;

        std::cout << "What is the name of your pet?" << std::endl;
        std::getline(std::cin, name);
        speciesSelect();


    }

int main() {

}

void speciesSelect() {
    int selection;
    std::string species[6] = {"Cat", "Wolf", "Spider","Crow","Bat","Ghost"};
    std::cout << "What species do you want your pet to be?" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << i << '.' << species[i] << std::endl;    
    }
    std::getline(std::cin, selection);
}



