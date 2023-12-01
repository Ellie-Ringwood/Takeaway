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
private:
    std::string filePath;
};

