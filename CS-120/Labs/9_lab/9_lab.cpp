//necessary for assignment requirements
#include <iostream>
#include <fstream> 
//unnecessary but used to familiarize myself with vectors in c++
#include <vector>
#include <string>
#include <sstream>
//included to round the average temp to a reasonable level of precision
#include <cmath>

void readFile(std::vector<int>& days, std::vector<double>& lows, std::vector<double>& depths);
int lowTemp(const std::vector<double>& lows);
double averageTemp(const std::vector<double>& lows);
std::vector<double> depthChange(const std::vector<double>& depths);

int main() {
    std::vector<int> days;
    std::vector<double> lows, depths;

    readFile(days, lows, depths);

    int lowest = lowTemp(lows);
    double average = averageTemp(lows);
    std::vector<double> dailyDepthDif = depthChange(depths);

    std::cout << "Temperature information for Moscow in Janauary, 2016:" << std::endl;
    std::cout << "Lowest recorded temperature: " << lowest << " F" << std::endl;
    std::cout << "Average Lowest Temperature: " << average << std::endl;
    std::cout << "Daily Changes in Snow Depth: " << std::endl;
    for (int i = 0; i < dailyDepthDif.size(); i++) {
        std::cout << "Day: " << days[i] << ": " << dailyDepthDif[i] << " inches" << std::endl;
    }

}

void readFile(std::vector<int>& days, std::vector<double>& lows, std::vector<double>& depths) {
    std::ifstream weather("weather.txt");
    std::string cell;

    std::getline(weather, cell);

    while(std::getline(weather, cell)) {
        int day;
        double low, depth;

        std::istringstream stream(cell);
        std::string currentCell;
        for (int i = 1; i <= 8; i++) {
            stream >> currentCell;
            switch(i) {
                case 1:
                    day = stoi(currentCell);
                    break;
                case 4:
                    low = stod(currentCell);
                    break;
                case 8:
                    depth = std::stod(currentCell);
            }
        }

        days.push_back(day);
        lows.push_back(low);
        depths.push_back(depth);
    }
}

int lowTemp(const std::vector<double>& lows) {
    double lowest = lows[0];
    for (auto cell : lows) {
        if (cell < lowest) {
            lowest = cell;
        }
    }
    return lowest;
}

double averageTemp(const std::vector<double>& lows) {
    double total = 0.0;
    for (auto cell : lows) {
        total += cell;
    }
    double average = total / lows.size();
    return std::round(average * 10) / 10;
}

std::vector<double> depthChange(const std::vector<double>& depths) {
    std::vector<double> dailyDepthChange;
    double previousCell = depths[0];
    for (auto currentCell : depths) {
        double change = currentCell - previousCell;
        dailyDepthChange.push_back(change);
        previousCell = currentCell;
    }
    return dailyDepthChange;
}
