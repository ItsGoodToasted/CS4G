// Nigel Lee
// CS-120-08
// Assignment 9
// 10/26/2023 

/* This is a program which allows the user to search through a records file.
 * This assignment was created by Nigel Lee
 * Vectors were used in place of C/C++ arrays to familiarize myself with them
 * No extras were added to this assignment

*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Animal {
    public:
        //3 seperate lines for readability. 
        std::string name, species, gender, personality, hobby, birthday;
        std::string catchphrase, favoriteSong, style1, style2, color1, color2;
        std::string wallpaper, flooring, furniture, list, filename, uniqueID;
        
        //class constructor for all members from records vector
        Animal(std::vector<std::string> records) {
            name = records[0];
            species = records[1];
            gender = records[2];
            personality = records[3];
            hobby = records[4];
            birthday = records[5];
            catchphrase = records[6];
            favoriteSong = records[7];
            style1 = records[8];
            style2 = records[9];
            color1 = records[10];
            color2 = records[11];
            wallpaper = records[12];
            flooring = records[13];
            furniture = records[14];
            filename = records[15];
            uniqueID = records[16];
    }
    void print();
    void speak();
};

int main() {
    //vector of objects to store each row
    std::vector<Animal> animals;
    //import data
    std::ifstream records("records.txt");
    std::string row;
    //header skip
    std::getline(records, row);
    //parse data loop
    while(std::getline(records,row)) {
        //storage vector for data to be put in object
        std::vector<std::string> tempData;
        //fill from each line
        std::stringstream stream(row);
        //storage for each entry in row
        std::string entry;
        //find entries between commas
        while(std::getline(stream, entry, ',')) {
            //store entry
            tempData.push_back(entry);
        }
        //make object from temp vector, put object in object vector
        animals.push_back(Animal(tempData));
        //clearing temporary data storage for new entry
        tempData.clear();
    }//end parse data loop
    
    int choice;
    std::string search;
    //main menu loop
    do {
        std::cout << "What would you like to do:" << std::endl;
        std::cout << "1.Search(name)\n2.Search(species)\n3.Search(color)\n";
        std::cout << "4.Quit" << std::endl;
        std::cin >> choice;
        //search fail bool
        bool found = false;
        switch(choice) {
            case 1:
                std::cout << "Enter the name to search: ";
                std:: cin >> search;
                //name search loop
                for(auto& animal : animals) {
                    if(animal.name == search) {
                        animal.print();
                        animal.speak();
                        found = true;
                    }
                }
                if(!found) {
                    std::cout << "No " << search << " found" << std::endl;
                }
                break;
            
            case 2:
                std::cout << "Enter a species to search:";
                std::cin >> search;
                //species search loop
                for(auto& animal : animals) {
                    if(animal.species == search) {
                        animal.print();
                        found = true;
                    }
                }
                if(!found) {
                    std::cout << "No " << search << " found" << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter a color to search:";
                std::cin >> search;
                //color search loop
                for(auto& animal : animals) {
                    if(animal.color1 == search || animal.color2 == search) {
                        animal.print();
                        found = true;
                    }
                }
                if(!found) {
                    std::cout << "No " << search << " found" << std::endl;
                }
                break;
            //quit case
            case 4:
                break;
            
            default:
                std::cout << "Invalid selection. Please enter a valid choice." << std::endl;
                break;
        }

    } while (choice != 4);
}
//animal print function. Sometimes endl doesn't go through, likely terminal display issue
void Animal::print() {
    std::cout << name << " is a " << gender << " " << species << " who likes listening to " << favoriteSong << std::endl;
}
//animal catchphrase function
void Animal::speak() {
    std::cout << name << " says, \"" << catchphrase << "\"" << std::endl;

}


