#include "Menu.h"
#include "Beverage.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include <sstream> 
#include <vector>

//split into seperate vectors so they can easily be printed out in correct sections in toString() no matter the order they are in the file
std::vector<Item*> appetisers; 
std::vector<Item*> beverages;
std::vector<Item*> mainCourses;

Menu::Menu(std::string inputFilePath) {
    filePath = inputFilePath;
    loadFile();
}

Menu::~Menu() {

}

void Menu::loadFile() {
    std::string line;
    std::ifstream file;

    file.open(filePath);
    if (file.is_open()) {
        while (getline(file, line)) { //split up file into lines
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
            
            while (getline(stringStream, word, ',')) { //split up lines into words
                if (!word.empty()) {
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
            if (type == "a"){ //initialise Item child classes depending on type
                Appetiser* appetiser = new Appetiser(type,name,calories,price,shareable,twoForOne);
                items.push_back(appetiser);
                appetisers.push_back(appetiser); //seperated into vectors for easier toString() later
            }
            else if (type == "b") {
                Beverage* beverage = new Beverage(type,name,calories, price,abv,volume);
                items.push_back(beverage);
                beverages.push_back(beverage); //seperated into vectors for easier toString() later
            }
            else if (type == "m") {
                MainCourse* mainCourse = new MainCourse(type,name, calories, price);
                items.push_back(mainCourse);
                mainCourses.push_back(mainCourse); //seperated into vectors for easier toString() later
            }
        }
        currentList = items;
        file.close();
    }
}

std::string Menu::toString() {
    std::string output;
    //no matter order in files, will be put in correct sections
    //already split into vectors based on type, so dont have to do it repeatedly
    int count = 1;
    output += "--------------- MENU -----------------\n";
    output += "\t---- APPETISERS ----\n";
    for (int i = 0; i < appetisers.size(); i++) {
        output += "(" + std::to_string(count) + ") " + appetisers[i]->toString() + "\n";
        count += 1;
    }
    output += "\n\t--- MAIN COURSES ---\n";
    for (int i = 0; i < mainCourses.size(); i++) {
        output += "(" + std::to_string(count) + ") " + mainCourses[i]->toString() + "\n";
        count += 1;
    }
    output += "\n\t----- BEVERAGES -----\n";
    for (int i = 0; i < beverages.size(); i++) {
        output = output + "(" + std::to_string(count) + ") " + beverages[i]->toString() + "\n";
        count += 1;
    }
    return output;
}

std::string Menu::toString(std::vector<Item*> list) {
    std::string output;
    output += "--------------- MENU -----------------\n";
    for (int i = 0; i < list.size();i++) {
        output += "(" + std::to_string(i+1) +") " + list[i]->toString() + "\n";
    }
    return output;
}

std::vector<Item*> Menu::sortByPrice(bool isAscending) {
    if (isAscending == true) {
        std::sort(currentList.begin(), currentList.end(), [](const Item* item1, const Item* item2) {return (item1->getPrice() < item2->getPrice());});
    }
    else {
        std::sort(currentList.begin(), currentList.end(), [](const Item* item1, const Item* item2) {return (item1->getPrice() > item2->getPrice());});
    }
    return currentList;
}






