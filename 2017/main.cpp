#include <iostream>
#include <map>
#include <fstream>
#include "day.h"
#include "day1.h"

using namespace std;

#include <algorithm>
#include <locale>

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

day *findDay(string day) {
    if (day == "day1") return new day1;

    return nullptr;
}

string getInput(const string &filePath) {
    ifstream file(filePath);
    string s = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    trim(s);

    return s;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage: ./aoc dayN inputFile" << endl;
        return 1;
    }

    day *runningDay = findDay(string(argv[1]));
    string input = getInput(argv[2]);

    cout << runningDay->first(input) << endl;
    cout << "---------------------------" << endl;
    cout << runningDay->second(input) << endl;
    return 0;
}
