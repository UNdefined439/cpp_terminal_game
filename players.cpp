// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <vector>
#include <cmath>
#include "players.h"
#include "gameObjects.h"

using namespace std;

Players::Players(int health, int damage, int block, string name, int id) : health(health), damage(damage), block(block), name(name), id(id) {
	lvl = 0.0;
	extraMaxHealth = 0;
	this->addObj(make_unique<FreezeSpell>("start"));
	this->addObj(make_unique<Rocks>("start"));
}

int Players::getHealth() const {
	return health;
}
int Players::getDamage() const {
	return damage;
}
int Players::getBlock() const {
	return block;
}
string Players::getName() const {
	return name;
}
int Players::getId() const {
	return id;
}
float Players::getLvl() const {
	return lvl;
}
int Players::calcMaxHealth() const {
	return static_cast<int>(health + (10 * lvl));
}
int Players::getInventorySize() const {
	return static_cast<int>(inventory.size());
}
int Players::getEffectsSize() const {
	return static_cast<int>(effects.size());
}
int Players::getExtraMaxHealth() const {
	return extraMaxHealth;
}
void Players::display() const {
	cout << name << ":\nLevel " << lvl << ", Health " << health << ", Damage " << damage << ", Block Chance " << block << endl;
}

float Players::changeLvl(float change, bool silent) {
	lvl += change;
	if (lvl < 0)
		lvl = 0;
	if (!silent)
		cout << this->getName() << "'s level " << (change > 0 ? "dropped to " : "rose to ") << lvl << endl;
	return lvl;
}
int Players::changeHealth(int change, bool silent) {
	int maxHealth = calcMaxHealth();
	health += change;
	if (health > maxHealth)
		health = maxHealth;
	if (health < 0)
		health = 0;

	if (!silent)
		cout << this->getName() << "'s health " << (change > 0 ? "dropped to " : "rose to ") << health << endl;
	return health;
}
int Players::changeBlock(int change, bool silent) {
	block += change;
	if (block < 0)
		block = 0;
	if (block > 80)
		block = 80;

	if (!silent)
		cout << name << "'s block " << (change > 0 ? "dropped to " : "rose to ") << block << endl;
	return block;
}
int Players::changeExtraMaxHealth(int change, bool silent) {
	extraMaxHealth += change;
	if (extraMaxHealth < 0)
		extraMaxHealth = 0;

	if (!silent)
		cout << name << "'s bonus max health " << (change > 0 ? "dropped to " : "rose to ") << extraMaxHealth << endl;
	return extraMaxHealth;
}
int Players::changeDamage(int change, bool silent) {
	damage += change;
	if (damage < 0)
		damage = 0;
	
	if (!silent)
		cout << name << "'s attack " << (change > 0 ? "dropped to " : "rose to ") << damage << endl;
	return damage;
}

bool Players::isAlive() const {
	return (health > 0);
}
bool Players::checkEffects(string action, bool silent) const {
	//use map to check if any of the effects effect player depending on the action the player is trying to take
	return false;
}

bool Players::hasObj(string objectName, bool silent) {
	bool ans = find_if(inventory.begin(), inventory.end(), [objectName](unique_ptr<Objects>& obj) { return obj->getName() == objectName; }) != inventory.end();

	if (!silent)
		cout << this->getName() << (ans ? " has a " : " doesnt have a ") << objectName << endl;
	return ans;
}
bool Players::addObj(unique_ptr<Objects> object, bool silent) {
	bool added = false;
	if (!this->hasObj(object->getName()) && inventory.size() <= 10) {
		if (!silent)
			cout << this->getName() << " got a " << object->getName() << ". To view and use, open inventory with the command 'inventory', on your turn." << endl;
		inventory.push_back(move(object)); 
		return true;
	}

	if (!silent)
		cout << this->getName() << " couldn't get a " << object->getName() << ". NOTE: You can only have up to 10 items in your inventory and only 1 of each item type.";
	return added;
}
bool Players::removeObj(string object, bool silent) {
	return false;
}


void Players::tickEffects(bool silent) {
	for (auto eff = effects.begin(); eff != effects.end();) {
		if ((*eff)->tick()) {
			if (!silent)
				cout << this->getName() << " is no longer affected by " << (*eff)->getName() << endl;
			eff = effects.erase(eff);
		}
		else {
			eff++;
		}
	}
}
bool Players::hasEff(string effect, bool silent) const {
	return false;
}
bool Players::addEff(unique_ptr<Effects> effect, bool silent) {
	if (hasEff(effect->getName())) {
		// use a map to see if it just adds to that effect, needs a different approach or just fails and does nothing, or have it as a overrideen function in the effect classes
		return false;
	} else {
		effects.push_back(move(effect));
		if (!silent)
			cout << "" << endl;
		return true;
	}
}
bool Players::removeEff(string effectStr, bool silent) {
	for (auto it = effects.begin(); it != effects.end(); ) {
		if ((*it)->getName() == effectStr) {
			if (!silent)
				cout << name << " is no longer affected by " << effectStr << endl;
			effects.erase(it);
			return true;
		}
	}

	if (!silent)
		cout << name << " does not have the effect: " << effectStr << endl;
	return false;
}