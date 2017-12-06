#include <iostream>
#include "day6.h"
#include "util.h"

string formatState(const vector<int> &banks) {
    stringstream ss;
    for (size_t i = 0; i < banks.size(); ++i) {
        if (i != 0)
            ss << ",";
        ss << banks[i];
    }

    return ss.str();
}

string day6::first(const string &input) {
    auto parsedInput = split(input, '\t');
    vector<int> banks;
    for (const auto &i : parsedInput) {
        banks.push_back(stoi(i));
    }

    return to_string(findLoop(banks));
}

string day6::second(const string &input) {
    auto parsedInput = split(input, '\t');
    vector<int> banks;
    for (const auto &i : parsedInput) {
        banks.push_back(stoi(i));
    }

    findLoop(banks);

    return to_string(findLoop(banks));
}

int day6::findLoop(vector<int> &banks) const {
    string state = formatState(banks);
    vector<string> results;

    int jumps = 0;
    do {
        results.push_back(state);
        auto currentBank = max_element(banks.begin(), banks.end());
        auto value = *currentBank;
        *currentBank = 0;
        while (value-- != 0) {
            currentBank++;
            if (currentBank == banks.end()) {
                currentBank = banks.begin();
            }

            *currentBank += 1;
        }

        state = formatState(banks);
        jumps++;
    } while (find(results.begin(), results.end(), state) == results.end());

    return jumps;
}
