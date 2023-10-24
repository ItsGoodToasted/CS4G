// Nigel Lee
// CS-120-08
// Lab 9
// 10/24/2023 

//necessary for assignment requirements
#include <iostream>
#include <fstream> 
//unnecessary but used to familiarize myself with vectors in c++
#include <vector>
#include <string>
#include <sstream>
//included to round the average temp to a reasonable level of precision
#include <cmath>
//function prototypes
void readFile(std::vector<int>& days, std::vector<double>& lows, std::vector<double>& depths);
int lowTemp(const std::vector<double>& lows);
double averageTemp(const std::vector<double>& lows);
void depthChange(const std::vector<int>& days, const std::vector<double>& depths);

int main() {
    std::vector<int> days;
    std::vector<double> lows, depths;
    //use readfile to fill declared vectors
    readFile(days, lows, depths);
    //use lowTemp and averageTemp to calculate fill the variables report to user
    int lowest = lowTemp(lows);
    double average = averageTemp(lows);

    std::cout << "Temperature information for Moscow in Janauary, 2016:" << std::endl;
    std::cout << "Lowest recorded temperature: " << lowest << " F" << std::endl;
    std::cout << "Average Lowest Temperature: " << average << "F " << std::endl;
    depthChange(days, depths);

}
//function for reading and pulling values from weather.txt
void readFile(std::vector<int>& days, std::vector<double>& lows, std::vector<double>& depths) {
    //read values into weather object
    std::ifstream weather("weather.txt");
    std::string cell;
    //disregard the header of weather.txt
    std::getline(weather, cell);
    //loop for parsing each row of weather
    while(std::getline(weather, cell)) {
        int day;
        double low, depth;
        //use isstringstream to check for whitespace and fill cell with resulting data
        std::istringstream stream(cell);
        std::string currentCell;
        //loop for examining columns within rows of weather
        for (int i = 1; i <= 8; i++) {
            //store the value pulled from isstringstream into a "cell variable"
            stream >> currentCell;
            switch(i) {
                case 1:
                    day = stoi(currentCell);
                    break;
                case 5:
                    low = stod(currentCell);
                    break;
                case 8:
                    depth = std::stod(currentCell);
            }
        } //end of column loop
        //fill arrays with appropriate data
        days.push_back(day);
        lows.push_back(low);
        depths.push_back(depth);
    }//end of row loop
}
//function for calculating the lowest temp in the vector
int lowTemp(const std::vector<double>& lows) {
    double lowest = lows[0];
    //iterate through entire vector, mapping cell to each value per loop
    for (auto cell : lows) {
        if (cell < lowest) {
            lowest = cell;
        }
    }
    return lowest;
}
//function for calculating the average value of the vector
double averageTemp(const std::vector<double>& lows) {
    double total = 0.0;
    //iterate through entire vector, mapping cell to each value per loop
    for (auto cell : lows) {
        total += cell;
    }
    double average = total / lows.size();
    //returns a rounded version of temp
    //it isn't normal to return weather temperature to precision beyond a decimal
    return std::round(average * 10) / 10;
}
//function for calculating the change between values in the depth vector
//reports changes with value in day vector from same position
void depthChange(const std::vector<int>& days, const std::vector<double>& depths) {
    std::vector<double> dailyDepthChange;
    double previousCell = depths[0];
    //iterate through entire vector, mapping cell to each value per loop
    for (auto currentCell : depths) {
        //calculate cell difference
        double change = currentCell - previousCell;
        //merge change into vector
        dailyDepthChange.push_back(change);
        //change starting value for calculation
        previousCell = currentCell;
    }
    std::cout << "Daily Changes in Snow Depth: " << std::endl;
    //loop to report daily depth changes on each day
    for (int i = 0; i < dailyDepthChange.size(); i++) {
        std::cout << "Day: " << days[i] << ": " << dailyDepthChange[i] << " inches" << std::endl;
    }
}
