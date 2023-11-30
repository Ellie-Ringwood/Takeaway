#include "Menu.h"
#include "Beverage.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include <sstream> 
#include <vector>

Menu::Menu(std::string inputFilePath) {
    filePath = inputFilePath;
    loadFile();
}

void Menu::loadFile() {
    std::string line;
    std::ifstream file;

    file.open(filePath);
    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream stringStream(line);
            std::string word;

            std::string type = " ";
            std::string name = " ";
            double price = -1.0;
            int calories = -1;
            bool shareable = false;
            bool twoForOne = false;
            int volume = -1;
            double abv = -1.0;

            int count = 0;
            
            while (getline(stringStream, word, ',')) {
                if (!line.empty()&& word.find_first_not_of(" ") != std::string::npos) {
                    switch (count) {
                    case 0: //type
                        type = word;
                        break;
                    case 1: //name
                        name = word;
                        break;
                    case 2://price
                        price = stod(word);
                        break;
                    case 3://calories
                        calories = stoi(word);
                        break;
                    case 4://shareable
                        if (word == "y") {
                            shareable = true;
                        }
                        break;
                    case 5://2-4-1
                        if (word == "y") {
                            twoForOne = true;
                        }
                        break;
                    case 6://volume
                        volume = stoi(word);
                        break;
                    case 7://Abv
                        abv = stod(word);
                        break;
                    }
                }
                count++;
            }

            if (type == "a"){
                Appetiser* appetiser = new Appetiser(name,calories,price,shareable,twoForOne);
                items.push_back(appetiser);
            }
            else if (type == "b") {
                Beverage* beverage = new Beverage(name,calories, price,abv,volume);
                items.push_back(beverage);
            }
            else if (type == "m") {
                MainCourse* mainCourse = new MainCourse(name, calories, price);
                items.push_back(mainCourse);
            }
        }
        file.close();
    }
}

std::string Menu::toString() {
    std::string output;
    for (int i = 1; i < items.size()+1; i++) {
        output = output + "(" + std::to_string(i) + ") " + items[i]->toString();
    }
    return output;
}