#include "playerEffects.h"
#include "effects.h"

Frozen::Frozen(int length) {
	turns = length;
	name = "Frozen";
}
void Frozen::apply(Players& player) {

}
bool Frozen::undo(Players& player) {
	return false;
}

Invisible::Invisible(int length) {
	turns = length;
	name = "Invisible";
}
void Invisible::apply(Players& player) {

}
bool Invisible::undo(Players& player) {
	return false;
}

MaxHealthBoost::MaxHealthBoost(int length, int boost) {
	turns = length;
	strength = boost;
}
void MaxHealthBoost::apply(Players& player) {
	player.changeExtraMaxHealth(strength);
}
bool MaxHealthBoost::undo(Players& player) {
	player.changeExtraMaxHealth(-strength);
	return true;
}

DamageBoost::DamageBoost(int length, int boost) {
	turns = length;
	strength = boost;
}
void DamageBoost::apply(Players& player) {
	player.changeDamage(strength);
}
bool DamageBoost::undo(Players& player) {
	player.changeDamage(-strength);
	return true;
}

BlockBoost::BlockBoost(int length, int boost) {
	turns = length;
	strength = boost;
}
void BlockBoost::apply(Players& player) {
	player.changeBlock(strength);
}
bool BlockBoost::undo(Players& player) {
	player.changeBlock(-strength);
	return true;
}

