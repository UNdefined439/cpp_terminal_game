// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <string>

#include "objects.h"

using namespace std;

void Objects::display() const { 
	cout << YELLOW << name << RESET << ": " << description << "\nLevel: " << lvl << ", max level: " << maxLvl << endl; 
}
string Objects::getDescription() const { 
	return description; 
}
string Objects::getName() const { 
	return name;
}
string Objects::getSource() const { 
	return source; 
}
int Objects::getLvl() const { 
	return lvl; 
}
int Objects::getMaxLvl() const { 
	return maxLvl; 
}
int Objects::getRarity() const { 
	return rarity; 
}
