#include <string>
#include <vector>
#include "day2.h"
#include "util.h"

string day2::first(const string &input) {
    int total = 0;

    for (string &line : split(input, '\n')) {
        trim(line);
        if (line.empty()) {
            continue;
        }

        int lowest = numeric_limits<int>::max();
        int highest = numeric_limits<int>::min();
        for (const string &number : split(line, '\t')) {
            int parsed = stoi(number);
            if (lowest > parsed) {
                lowest = parsed;
            }

            if (highest < parsed) {
                highest = parsed;
            }
        }

        total += highest - lowest;
    }

    return to_string(total);
}

string day2::second(const string &input) {
    int total = 0;
    for (string &line : split(input, '\n')) {
        trim(line);
        if (line.empty()) {
            continue;
        }

        const vector<string> &splitLine = split(line, '\t');
        int count = 1;
        for (const string &number : splitLine) {
            int parsed = stoi(number);
            for (const string &numberToCompare : vector<string>(splitLine.begin() + count++, splitLine.end())) {
                int parsedNumberToCompare = stoi(numberToCompare);
                if (parsedNumberToCompare != parsed) {
                    int lowest = min(parsed, parsedNumberToCompare);
                    int highest = max(parsed, parsedNumberToCompare);
                    if (highest % lowest == 0) {
                        total += highest / lowest;
                        goto done; // ouch
                    }
                }
            }
        }
        done: ;
    }

    return to_string(total);
}
