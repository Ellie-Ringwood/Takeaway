#include "Menu.h"
#include "Beverage.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include <sstream> 

Menu::Menu(std::string inputFilePath) {
    filePath = inputFilePath;
    loadFile();
}

void Menu::loadFile() {
    std::string line;
    std::ifstream file;

    
    

    int count = 1;
    int countIncludingEmpty = 1;

    file.open(filePath);
    if (file.is_open()) {
        while (getline(file, line,',')) {
            std::string type = " ";
            std::string name = " ";
            double price = -1.0;
            int calories = -1;
            bool shareable = false;
            bool twoForOne = false;
            int volume = -1;
            double abv = -1.0;

            std::cout << line << count << std::endl;
            
            if (!line.empty()) {
            switch (count) {
                case 1: //type
                    type = line;
                    break;
                case 2: //name
                    name = line;
                    break;
                case 3://price
                    price = stod(line);
                    break;
                case 4://calories
                    calories=stoi(line);
                    break;
                case 5://shareable
                    if (line == "y") {
                        shareable = true;
                    }
                    break;
                case 6://2-4-1
                    if (line == "y") {
                        twoForOne = true;
                    }
                    break;
                case 7://volume
                    volume = stoi(line);
                    break;
                case 8://Abv
                    abv = stod(line);
                    count = 0;
                    break;
                }
            }
            else {
                std::cout << "empty" << count << std::endl;
                if (count == 7) {
                    count = 0;
                }
                else {

                }
            }
            count++;


            //std::cout << type << name << price << calories << shareable << twoForOne << volume << abv << std::endl;
            

            //std::cout << line << std::endl;
            /*int previousIndex = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ',') {

                    previousIndex = i;
                }
                std::cout << i << std::endl;
            }
            */
            

            //std::cout << line << std::endl;
            //items.push_back(item);
        }
        file.close();
    }
}