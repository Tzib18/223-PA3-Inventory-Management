#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream> 
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <chrono>
using namespace std;

void parseCSV(const string& filename);
void printHelp();
bool validCommand(string line);
void evalCommand(string line);
void bootStrap();
int runapp(int argc, char const *argv[]);
