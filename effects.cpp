// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <string>

#include "effects.h"
#include "players.h"

using namespace std;

string Effects::getName() const {
	return name;
}
int Effects::getTurns() const {
	return turns;
}
int Effects::tick() {
	return --turns;
}
bool Effects::check() const {
	return turns > 0;
}
bool Effects::stack(int extra, bool silent) {
	turns += extra;
	return true;
}