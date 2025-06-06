// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <memory>
#include <array>
#include "players.h"
using namespace std;

void clear() {
#ifdef _WIN32
	system("cls");
#else 
	system("clear");
#endif
}

void wait() {
	cout << endl << "Enter any key to continue...";
	cin.ignore();
	cin.get();
}

void displayOpts() {
	cout << "Would you like to: cast a healing spell (costs 1 level), attack a enemy, or go exploring? \nEnter 'heal', 'attack', or 'explore' to start the action. To open inventory, enter 'inventory' (doesn't count as an action)." << endl;
}

void displayFleeOpts(float fleeCost) {
	cout << "Would you like to, attack or flee (lose " << fleeCost << " levels)? To open inventory enter 'inventory' (doesn't count as an action). \n Enter 'attack' or 'flee'." << endl;
}

void displayPlayers(array<unique_ptr<Players>, 2>& players) {
	for (const auto& player : players) {
		player->display();
	}
}