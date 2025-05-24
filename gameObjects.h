#pragma once

#include "objects.h"
#include "players.h"

class FreezeSpell : public Objects {
public:
	FreezeSpell(std::string source);

	void use(Players user, Players* target = nullptr) override;
};

class GoldenScepter : public Objects {
public:
	GoldenScepter(std::string source);

	void use(Players user, Players* target = nullptr) override;
};

class Rocks : public Objects {
public:
	Rocks(std::string source);
	
	void use(Players user, Players* target = nullptr) override;
};