#pragma once
#include "ItemList.h"
#include <fstream> 
#include <iostream>
#include <sstream> 

class Menu : public ItemList
{
public:
    Menu(std::string);
    void loadFile();
private:
    std::string filePath;
    std::string line;
    std::string word;
};

