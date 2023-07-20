#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

ifstream f("data.json");
json data = json::parse(f);

// cout << "Program Completed!" << endl;