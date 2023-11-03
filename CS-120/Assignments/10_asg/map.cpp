// Nigel Lee
// CS-120-08
// Assignment 10
// 11/03/2023 

/*
Description:
 * This is a program for representing map data using ASCII characters.
Extras:
 * Added a map generation option to test map varieties
   Not really an extra as it seemed necessary to validate
   the print functions worked fully.

*/

#include <iostream>
#include <string>
//ctime library for map generation seed
#include <ctime>

class Cell {
    public:
    std::string animal;
    std::string terrain;
    int altitude;
    //Cell constructor with default initializers
    Cell(std::string randAnimal = "none", std::string randTerrain = "none", int randAltitude = 0) {
        animal = randAnimal;
        terrain = randTerrain;
        altitude = randAltitude;
        
    }
    //map terrain print function
    char printTerrain() {
        if(terrain == "prairie") {
            return '_';
        }
        if(terrain == "water") {
            return '~';
        }
        if(terrain == "mountain") {
            return '^';
        }
        return ' ';
    }
    //map animal print function
    char printAnimal() {
        if(animal == "racoon") {
            return 'R';
        }
        if(animal == "possum") {
            return 'O';
        }
        if(animal == "bunny") {
            return 'B';
        }
        return ' ';
    } 
};
//function prototypes
void generateMap(Cell map[10][20]);
void printTerrains(Cell map[10][20]);
void printAnimals(Cell map[10][20]);
int getAltitude(Cell map[10][20], int x, int y);

int main() {
    int choice;
    //declare map object of the Cell class
    Cell map[10][20];
    //generate initial map for user
    generateMap(map);
    
    do {//main menu loop
        std::cout << "1.Generate New Map\n2.Print Terrain\n3.Print Animals\n";
        std::cout << "4.Find Altitude\n5.Quit" << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1:
                generateMap(map);
                std::cout << "New map generated" << std::endl;
                break;
            case 2:
                printTerrains(map);
                break;
            case 3:
                printAnimals(map);
                break;
            case 4:
                int x, y;
                std::cout << "Enter coordinates to search (x y). Do not include commas" << std::endl;
                std::cin >> x >> y;
                std::cout <<"Altitude at (" << x << ',' << y <<") : " << getAltitude(map, x, y) << std::endl;
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid selection." << std::endl;
                break;
        }   
    } while(choice != 5); //main menu loop ends
}

void generateMap(Cell map[10][20]) {
    //seed random number generator
    srand(time(0));
    //declare string arrays of possible animals and terrains
    std::string animals[] = {"racoon", "possum", "bunny", "none"};
    std::string terrains[] = {"prairie","water", "mountain","none"};
    //loops for cells
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 20; j++) {
            //select a random animal and terrain for a cell
            std::string animal = animals[rand() % 4];
            std::string terrain = terrains[rand() % 4];
            //random altiude between 0 and 3000
            int altitude = rand() % 3001;
            //fill cell with information using constructor
            map[i][j] = Cell(animal, terrain, altitude);
        }
    }
}
//loops through map array and prints terrains
void printTerrains(Cell map[10][20]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << map[i][j].printTerrain() << ' ';
        }
        std::cout << std::endl;
    }
}
//loops through map array and prints animals
void printAnimals(Cell map[10][20]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << map[i][j].printAnimal() << ' ';
        }
        std::cout << std::endl;
    }
}
//fetches altitude in given cell of array
int getAltitude(Cell map[10][20], int x, int y) {
    return map[x][y].altitude;
}
