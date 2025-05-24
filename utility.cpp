// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <set>
#include <stdexcept>
#include <vector>

#include "utility.h"
#include "ui.h"

using namespace std;


string lowercase(const string& str) {
	string lower = str;
	transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c){ return tolower(c); });

	return lower;
}

int rng(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void sleep(int time) {
    this_thread::sleep_for(chrono::milliseconds(time));
}

void loadingDots(int cycles, int delay, const string& str) {
	string dots[3] = {".", "..", "..."};

	for (int i = 0; i < cycles; ++i) {
		cout << "\r" << str << dots[i % 3] << string(5, ' ') << flush;
		sleep(delay);
	}
	cout << endl;
}

const set<string> reservedNames = { "null", "zombies", "heal", "attack", "explore",
	"undead", "skeletons", "bola", "sword", "poison", "sheild", "rocks", "spell", "object", "currPlayer", "otherPlayer", "diamond", "wood" };

bool isReservedName(const string& name) {
	return reservedNames.find(lowercase(name)) != reservedNames.end();
}

void getNames(string& name1, string& name2) {
    bool reserved;
    do {
        clear();
        cout << "Enter player " << BLUE << "1" << RESET << "'s name: ";
        cin >> name1;
        reserved = isReservedName(name1);
        if (reserved) {
            cout << "Name unavilable." << endl;
            sleep(1000);
            clear();
        }
    } while (reserved);

    do {
        clear();
        cout << BLUE << 1 << RESET << "'s name is: " << name1 << endl;
        cout << "Enter player " << GREEN << 2 << RESET << "'s name: ";
        cin >> name2;
        reserved = isReservedName(name2);
        if (reserved) {
            cout << "Name unavilable." << endl;
            sleep(1000);
            clear();
        }
    } while (reserved || name1 == name2);
}

void getName(int id, string& name, vector<string>& usedNames) {
    while (1) {
        try {
            cout << "Enter player " << id << "'s name: " << endl;
            cin >> name;

            if (isReservedName(name)) throw invalid_argument("Name is unavilable");
            if (find(usedNames.begin(), usedNames.end(), name) != usedNames.end()) throw invalid_argument("Name is in use by another player");

            //add alphanumeric checking

            usedNames.push_back(name);
            break;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}