#ifndef commonTools_H
#define commonTools_H
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "AllExeptions.h"

std::vector <std::string> splitString(std::string);
std::vector <std::string> refineString(std::string);
int Gstoi(std::string);
void addVectorToVector(std::vector <std::string>&, std::vector <std::string>&);
bool isUnique(std::vector <int>, int);
std::vector <int> generateUniqueRandomNums(int, int);
bool isUniqueVector(std::vector<std::string>);

#endif

