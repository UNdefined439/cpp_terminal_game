#include <iostream>
#include <chrono>
#include <memory>
#include "events.h"
#include "ui.h"
#include "utility.h"
#include "players.h"
#include "gameObjects.h"

using namespace std;

void explore(Players& human) {
	int num = rng(1, 100);
	if (num < 50)
		dungeon(human);
	else if (num < 75)
		merchant(human);
	else if (num < 90)
		treasure(human);
	else
		dragon(human);
}

void dungeon(Players& human) {
	clear();
	string name = human.getName();
	cout << name << ":" << endl << endl;
	loadingDots(1, 500, "You pick up a torch and cowering behind your shield enter the darkness");
	sleep(1000);
	clear();
		
	Players monster = []() {
		int num = rng(1, 100);
		if (num < 35) return Players(0, 0, 0, "TREASURE");
		if (num < 55) return Players(0, 0, 0, "Zombie");
		if (num < 75) return Players(0, 0, 0, "Booby Traps");
		if (num < 90) return Players(0, 0, 0, "Skeleton");
		return Players(0, 0, 0, "Ghost");
	}();
	
	if (monster.getName() == "TREASURE") {

	} else {
		string msg = name + " has come across a room of " + monster.getName();
		loadingDots(1, 500, msg);
		sleep(1000);

		int turns = 1;
		bool flee = false;
		while (monster.isAlive() && human.isAlive()) {
			clear();
			human.display();
			monster.display();

			if (turns % 2 == 1) {
				// monster
			} else {
				string action;
				do {
					break;
				} while (action != "attack" && action != "flee");

				if (action == "flee") {
					flee = true;
					break;
				} else {

				}
			}
			++turns;
		}
	}
}

void merchant(Players& human) {
	loadingDots(1, 500, "A friendly merchant beckons you to his stall, a gleam in his eyes tell you something is going to be different this time");
	sleep(1000);

	for (int i = 0; i < 3; ++i) {
		clear();
		auto a = []() {
			int num = rng(1, 100);
			if (num < 40) return make_unique<FreezeSpell>("Merchant");
			if (num < 60) return make_unique<FreezeSpell>("Merchant"); // place holders
			if (num < 80) return make_unique<FreezeSpell>("Merchant");
			if (num < 90) return make_unique<FreezeSpell>("Merchant");
			return make_unique<FreezeSpell>("Merchant");
		}();
		auto b = []() {
			int num = rng(1, 100);
			if (num < 40) return make_unique<GoldenScepter>("Merchant");
			if (num < 60) return make_unique<GoldenScepter>("Merchant"); // place holders
			if (num < 80) return make_unique<GoldenScepter>("Merchant");
			if (num < 90) return make_unique<GoldenScepter>("Merchant");
			return make_unique<GoldenScepter>("Merchant");
		}();
		
		cout << "Option A" << endl;
		a->display();
		cout << "Option B" << endl;
		b->display();

		string choice;
		do {
			cout << "Do you want to 'reroll', take 'a' or take 'b'. You have " << 3 - i << " rerolls left." << endl;
			cin >> choice;
			choice = lowercase(choice);
			if (choice == "reroll" && i == 2) {
				cout << "You have used all your rerolls, pick 'a' or 'b'." << endl;
				sleep(1000);
				continue;
			}
			else if (choice != "a" && choice != "b" && choice != "reroll") {
				cout << "Invalid command" << endl;
				sleep(1000);
			}
		} while (choice != "a" && choice != "b" && choice != "reroll");
		if (choice == "reroll")
			continue;
		else {
			cout << "Smart choice, the merchant hands you the object." << endl;
			if (choice == "a")
				human.addObj(move(a));
			else
				human.addObj(move(b));
		}
		break;
	}
}

void treasure(Players& human) {

}

void dragon(Players& human) {

}