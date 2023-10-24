// Nigel Lee
// CS-120-08
// Assignment 8
// 10/20/2023 

/*
This is a basic tamagachi-like game.

* The additional interactions functions added:
    play(), walk(), medicine()
* No extra work was done.
*/

#include <iostream>
#include <string>
//ctime for random event selection
#include <ctime>

class Pet {
    int health; //default 50 / max 100 / min 0
    int hunger; //default 50 / max 200 / min -200 
    double weight; //default 40.0 / min 10.0
    int happiness; //default 5 // max 10 / min 1

    void speciesSelect(std::string& species);

    public:
        //basic info
        std::string name;
        std::string species;
        void petInfo();
        //4 interaction functions
        void feed();
        void play();
        void walk();
        void medicine();
        //3 random events
        void eventA();
        void eventB();
        void eventC();
        //condition verification
        void updateStatus(bool&);
        //Constructor
        Pet();
};
    Pet::Pet() {
        //Pet object default stats
        health = 50;
        hunger = 100;
        weight = 40.0;
        happiness = 5;
        std::cout << "What is the name of your pet?" << std::endl;
        std::getline(std::cin, name);
        speciesSelect(species);
    }
//function prototype for random event selection
void randomEvent(Pet&);

int main() {
    int choice;
    bool quit = false;
    std::cout << "TAMA: The Pet Management Game" << std::endl;
    std::cout << "Generating your new pet." << std::endl;
    Pet userPet;
    //main game loop begins
    do {
        //display info
        userPet.petInfo();
        //present menu
        std::cout << "What would you like to do with " << userPet.name << std::endl;
        std::cout << "1.Feed\n2.Play\n3.Walk\n4.Medicine\n5.quit" <<std::endl;
        std::cin >> choice;
        //menu selection
        switch(choice) {
            case 1: 
                userPet.feed();
                break;
            case 2: 
                userPet.play();
                break;
            case 3: 
                userPet.walk();
                break;
            case 4:
                userPet.medicine();
                break;
            case 5:
                quit = true;
                break;
            default:
                std::cout << userPet.name << " looks confused" << std::endl;
                break;
        }
        //trigger a possible random event
        randomEvent(userPet);
        //verify pet status and check for death. Quit if death == true.
        userPet.updateStatus(quit);
    } while(!quit); //end of main game loop
}
//function to call random pet class event
void randomEvent (Pet& pet) {
    //seed random number generation.
    srand(time(0));
    //roll a 1d6.
    int roll = rand() % 6 + 1; 
    //filtering to only odd rolls of the 1d6.
    if (roll % 2 != 0 ) {
        switch(roll) {
            case 1:
                pet.eventA();
                break;
            case 2:
                pet.eventB();
                break;
            case 3:
                pet.eventC();
                break;
        }
    }
}
//decide pet species
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
//display pet information
void Pet::petInfo() {
    std::cout << "Pet Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Species: " << species << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Hunger: " << hunger << std::endl; 
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Happiness: " << happiness << std::endl;
}
//feed pet. Overfeeding not allowed
void Pet::feed() {
    hunger -= 100;
    if (hunger <= -200) {
        std::cout << name << " is too full to eat anymore!" << std::endl;
        hunger = -200;
    } else {
    health += 25;
    std::cout << name << " munches on the kibble" << std::endl;
    }
}
//present user play options
void Pet::play() {
    int choice;
    //crude input validation loop
    while (choice < 1 || choice > 4) {
        std::cout << "How would you like to play with " << name << std::endl;
        std::cout << "1.Laser Pointer\n2.Ball\n3.Pet\n4.Treat" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << name << " chases around a laser pointer." << std::endl;
                break;
            case 2:
                std::cout << name << " runs after the ball you throw." << std::endl;
                break;
            case 3:
                std::cout << name << " gets belly rubs." << std::endl;
                break;
            case 4:
                std::cout << name << " gets " << species << "-nip." << std::endl;
                break;
            default:
                std::cout << name << " doesn't understand. Try again." << std::endl;
                break;
        }
    } //end of validation loop
    happiness += 3;
    hunger += 25;
}
//walk pet. Can tire them out and reduce hunger
void Pet::walk() {
    std:: cout << name << " goes for a stroll with you." << std::endl;
    hunger += 50;
    //check if pet has energy for walk
    if (hunger > 100) {
        health -= 10;
    } else {
        health += 10;
    }

}
//emergency heal to prevent death
//does not prevent death by weight loss
void Pet::medicine() {
    std::cout << name << " drinks the medicine. Yuck!" << std::endl;
    health += 50;
    happiness -= 5;
    hunger += 100;
}
//depression event, negative stat improvement
void Pet::eventA() { 
    std::cout << name << " is feeling depressed. You should cheer them up" << std::endl;
    happiness -= 2;
    health -= 5;
}
//typical pet behavior event, positive stat improvement
void Pet::eventB() {
    std::cout << name << " destroyed some furniture. They look satisfied." << std::endl;
    happiness += 3;
    hunger += 20;
}
//double outcome event tied to happiness. Negative or positive improvement
void Pet::eventC() {
    std::cout << name << " got into the trash. You hope they didn't eat something" << std::endl;
        //crude, low random chance of pet eating something
        //a max happy pet will eat out of the trash
        if (happiness % 5 == 0) {
            health -= 1;
            happiness -= 2;
            hunger += 100;
            std::cout << name << " threw up!" << std::endl;
        } else {
            happiness += 1;
            hunger -= 20;
        }

}
//large, catch all function to evaluate condition
void Pet::updateStatus(bool& death) {
    //lower happiness each turn to provide challenge 
    happiness -= 1;
    //limits happiness range, modifies stats

    if (happiness <= 1) {
        std::cout << name << " looks miserable." << std::endl;
        happiness = 1;
        health -= 30;
        weight -= 1;
    } else if (happiness >= 10) {
        std::cout << name << " is smiling" << std::endl;
        happiness = 10;
        health += 10;
    }
    //limits range of hunger
    if (hunger > 200) {
        hunger = 200;
        std::cout << name << " is feeling hungry." << std::endl;
    } else if (hunger < -200) {
        hunger = -200;
    }
    //weight gain or loss based off "calorie" intake
    if (hunger > 100) {
        weight -= 2;
    } else if (hunger < -100) {
        weight += 2;
    }
    //Extreme loss of health based on low weight. Lower weight, bigger loss.
    if (weight < 25.0) {
        health -= (100 / weight);
        std::cout << name << " is starving! Feed them something!" << std::endl;
    }
    //death check. Prevents a pet from staying alive at sub 10 weight.
    //limits health to 100, provides hints on death.
    if (health <= 0 || weight <= 10) {
        std::cout << name << " has died! Next time take better care of your tama." << std::endl;
        if (health <= 0) {
            std::cout << "Hint: A healthy tama is an alive tama." << std::endl;
        } else {
            std::cout << "Hint: Don't forget to feed your tama." << std::endl;
        }
        death = true;
    } else if (health > 100) {
        health = 100;
    }
}