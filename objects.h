#pragma once

#include <string>

#include "utility.h"

class Players;

class Objects {
protected:
	int lvl = 1, maxLvl = 1, rarity = -1;
	std::string description = "", name = "", source = "";
public:
	virtual ~Objects() = default;

	std::string getName() const;
	int getLvl() const;
	int getMaxLvl() const;
	int getRarity() const;
	std::string getDescription() const;
	std::string getSource() const;

	virtual void use(Players user, Players* target = nullptr) = 0;

	void display() const;
};
