#include "Menu.h"

Menu::Menu(std::string inputFilePath) {
    filePath = inputFilePath;
    loadFile();
}

void Menu::loadFile() {
    std::ifstream file;
    file.open(filePath);
    if (file.is_open()) {
        while (getline(file, line, ',')) {
            std::cout << line << std::endl;
        }
        file.close();
    }
}