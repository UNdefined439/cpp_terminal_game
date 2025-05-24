#pragma once

#include <string>
#include "players.h"

class Effects {
protected:
	std::string name = "";
	int turns = 0;
	int strength = 0;
	Players* on = nullptr;
public:
	virtual ~Effects() = default;

	std::string getName() const;
	int getTurns() const;

	virtual void apply(Players& player) = 0;
	virtual bool undo(Players& player) = 0;
	virtual int tick();
	virtual bool check() const;
	virtual bool stack(int extra, bool silent = true);
};