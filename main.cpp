// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <string>
#include <vector>
/*
#include <thread>
#include <chrono>
#include <map>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <functional>
#include <set>
#include <optional>
*/


#include "objects.h"
#include "players.h"
#include "ui.h" 
#include "utility.h"
#include "events.h"
#include "enemies.h"

using namespace std;



int main() {
    string name1, name2;
    getNames(name1, name2);
    wait();
    clear();
    unique_ptr<Players> players[2] = { make_unique<Players>(100, 25, 15, name1, 0), make_unique<Players>(100, 25, 15, name2, 1)};

    int round = 1, r = 1;
    while (players[0]->isAlive() && players[1]->isAlive()) {
        unique_ptr<Players>& currPlayer = r % 2 == 0 ? players[1] : players[0];
        unique_ptr<Players>& otherPlayer = r % 2 == 0 ? players[0] : players[1];

        if (!currPlayer->checkEffects("play", false))
            goto nextRound;
        if (r % 2 == 0)
            ++round;
    nextRound:
        ++r;
        wait();
        clear();
    }

    return 0;
}