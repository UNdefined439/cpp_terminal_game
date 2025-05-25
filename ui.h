#pragma once
#include <memory>
#include <array>
#include "players.h"

void clear();
void wait();

void displayOpts();
void displayFleeOpts(float fleeCost);
void displayPlayers(std::array<std::unique_ptr<Players>, 2>& players);