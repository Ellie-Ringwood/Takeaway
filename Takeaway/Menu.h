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
    virtual std::string toString();
private:
    std::string filePath;
    std::vector <Item*> items;
};

