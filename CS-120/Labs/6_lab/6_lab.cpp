#include <iostream>
#include <cmath>





double calcTime(double gravity, double height) {
    double time = sqrt((2*height)/gravity);
    return time;

}

double calcVelocity(double gravity, double time) {
    return time * gravity;
} 




int main() {
    //Earth, Moon, Mars, Mercury, Jupiter
    double gravity[5] = {9.81, 1.62, 3.71, 3.7, 24.79};
    std::string planets[5] = {"Earth", "Moon", "Mars", "Mercury", "Jupiter"};
    double height = 0;

    std::cout << "This program will caculation the gravity on various celestial objects." << std::endl;
    while (true) {
        std::cout << "Enter a height (in meters): ";
        std::cin >> height;

        if (height < 0) {
            std::cout << "You can't start beneath the ground." << std::endl;
            continue;
        } else {
            std::cout << "The object falls from " << height << " meters." << std::endl;
            for (int i = 0; i < 5; i++) {
                double time = calcTime(gravity[i], height);
                std::cout << "On " << planets[i] << ", the object will hit the ground in " << time << " seconds"
                << " and will be going " << calcVelocity(gravity[i], time) << " meters/second." << std::endl;

        }

        break;   
        }
    }
}