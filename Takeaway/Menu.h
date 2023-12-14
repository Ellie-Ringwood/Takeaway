#pragma once
#include "ItemList.h"
#include <fstream> 
#include <iostream>
#include <sstream> 

class Menu : public ItemList
{
public:
    Menu(std::string);
    ~Menu();
    void loadFile();
    virtual std::string toString();
    std::string toString(std::vector<Item*>);
    std::vector<Item*> sortByPrice(bool);
private:
    std::string filePath;
};

