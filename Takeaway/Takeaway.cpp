/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		cout << "\nEnter menu, sort, add, remove, checkout, help or exit: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			std::cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			int userChoice = 0;
			try {
				for (int i = 1; i < parameters.size();i++) {
					userChoice = stoi(parameters[i]);
					Item* choice; // you need to instantiate this using the menu object!
					choice = menu.items[userChoice - 1];
					order.add(choice);
				}
				std::cout << order.toString() << std::endl;
				
			}
			catch (...) {
				std::cout << "Not exceptable input, try again" << std::endl;
			}
		}
		else if (command.compare("remove") == 0)
		{
			vector<int> positions;
			try {
				for (int i = 1; i < parameters.size();i++) { // adds parameters behind command to list of positions
						positions.push_back(stoi(parameters[i])-1);
				}
				order.remove(positions);
				std::cout << order.toString() << std::endl;
			}
			catch (...) {
				std::cout << "Not exceptable input, try again" << std::endl;
			}
		}
		else if (command.compare("checkout") == 0)
		{
			std::cout << "------------ CHECKOUT --------------\n"
				<< order.toString() << std::endl;
			std::string userChoice;
			while (!(userChoice.compare("y") == 0 || userChoice.compare("n") == 0)) {
				std::cout << "Do you want to place your order?\nType 'y' to confirm, or 'n' to go back and modify it: ";
				std::cin >> userChoice;
				std::cin.clear(); //stops infinate loop of cin not being called properly
				std::cin.ignore();
			}
			if (userChoice.compare("y") == 0){
				std::cout << "Your receipt has been saved. Thank you for ordering! Good-Bye" << std::endl;
				order.printReceipt();
				userCommand = "exit";
			}
		}
		else if (command.compare("sort") == 0)
		{

		}
		else if (command.compare("help") == 0)
		{
			std::cout << "------------- HELP :) ---------------\n"
				<< "Enter one of these commands:\n"
				<< "menu - display the menu to the user\n"
				<< "add [INDEX] - add an item to the order by numeric index in the menu(starting at 1)\n"
				<< "remove [INDEX] - remove item from order by numeric index in the order(starting at 1)\n"
				<< "checkout - display the items in the user’s order, the price, and discount savings\n"
				<< "help - display a help menu for the user with the available options\n"
				<< "exit - terminate the program gracefully\n";
		}
		parameters.clear();
	}
	std::cout << "Press any key to quit...";
	std::getchar();
}