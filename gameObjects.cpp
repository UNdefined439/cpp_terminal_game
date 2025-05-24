// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>

#include "gameObjects.h"
#include "utility.h"
#include "players.h"

using namespace std;



FreezeSpell::FreezeSpell(string source) {
	name = "Freeze Spell";
	description = "Costs 2 levels per object level to cast and freezes a opponent for (object level) rounds.";
	lvl = 1;
	maxLvl = 2;
	rarity = -1; //add system later
	this->source = source;
}
void FreezeSpell::use(Players user, Players* target) {

}

GoldenScepter::GoldenScepter(string source) {
	name = "Golden Scepter";
	description = "Turns a enemy into gold, freezing them for (object level) turns. The caster gains 0.5 levels for every turn they are frozen.";
	lvl = []() {
		int num = rng(1, 100);
		if (num < 80) return 1;
		else return 2;
		}();
	maxLvl = 2;
	rarity = -1;
	this->source = source;
}
void GoldenScepter::use(Players user, Players* target) {

}

Rocks::Rocks(string source) {
	name = "Rocks";
	description = "You picked them up because... Well, I don't know. Drop them to gain a energy boost which increases your attack by (object level) for 1 turn.";
	lvl = []() {
		int num = rng(1, 100);
		if (num < 75) return 19;
		else if (num < 90) return rng(20, 24);
		else return rng(25, 30);
		}();
	maxLvl = 30;
	rarity = -1;
	this->source = source;
}
void Rocks::use(Players user, Players* target) {

}

