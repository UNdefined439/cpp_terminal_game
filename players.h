#pragma once

#include <string>
#include <vector>
#include <memory>

#include "objects.h"
#include "effects.h"
class Objects;
class Effects;

class Players {
private:
	int health, damage, block, id, extraMaxHealth; 
	float lvl;
	std::vector<std::unique_ptr<Objects>> inventory;
	std::vector<std::unique_ptr<Effects>> effects;
	std::string name;
public:
	Players(int health, int damage, int block, std::string name, int id = -1);

	int getHealth() const;
	int getDamage() const;
	int getBlock() const;
	std::string getName() const;
	int getId() const;
	float getLvl() const;
	int calcMaxHealth() const;
	int getInventorySize() const;
	int getEffectsSize() const;
	int getExtraMaxHealth() const;
	void display() const;

	float changeLvl(float change, bool silent = true);
	int changeHealth(int change, bool silent = true);
	int changeBlock(int block, bool silent = true);
	int changeExtraMaxHealth(int extra, bool silent = true);
	int changeDamage(int change, bool silent = true);

	bool isAlive() const;
	bool checkEffects(std::string action, bool silent = true) const;

	bool hasObj(std::string object, bool silent = true);
	bool addObj(std::unique_ptr<Objects> object, bool silent = true);
	bool removeObj(std::string object, bool silent = true);
	
	void tickEffects(bool silent = true);
	bool hasEff(std::string effect, bool silent = true) const;
	bool addEff(std::unique_ptr<Effects> effect, bool silent = true);
	bool removeEff(std::string effect, bool silent = true) ;
};

