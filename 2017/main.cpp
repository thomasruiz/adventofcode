#include <iostream>
#include <fstream>
#include "day.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "util.h"

using namespace std;

day *findDay(const string &day) {
    if (day == "day1") return new day1;
    if (day == "day2") return new day2;
    if (day == "day3") return new day3;
    if (day == "day4") return new day4;
    if (day == "day5") return new day5;

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
    if (runningDay == nullptr) {
        cerr << "day not found" << endl;
        return 1;
    }

    string input = getInput(argv[2]);
    trim(input);
    if (input.empty()) {
        cerr << "input not found" << endl;
        return 1;
    }

    cout << runningDay->first(input) << endl;
    cout << "---------------------------" << endl;
    cout << runningDay->second(input) << endl;
    return 0;
}
