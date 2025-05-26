#pragma once

#include <string>
#include <set>
#include <vector>

constexpr std::string_view RESET = "\033[0m";
constexpr std::string_view RED = "\033[31m";
constexpr std::string_view BLUE = "\033[34m";
constexpr std::string_view GREEN = "\033[32m";
constexpr std::string_view YELLOW = "\033[33m";
constexpr std::string_view BLACK = "\033[30m";
constexpr std::string_view MAGENTA = "\033[35m";
constexpr std::string_view CYAN = "\033[36m";
constexpr std::string_view WHITE = "\033[37m";

extern const std::set<std::string> reservedNames;
bool isReservedName(const std::string&);
std::string lowercase(std::string&);
void getNames(std::string& name1, std::string& name2);
void getName(int id, std::string& name, std::vector<std::string>& usedNames);

int rng(int min, int max);
void loadingDots(int cycles, int delay, const std::string& str);
void sleep(int time = 1000);

