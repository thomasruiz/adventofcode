#include <algorithm>
#include <iostream>
#include "day4.h"
#include "util.h"

string day4::first(const string &input) {
    int total = 0;
    for (const string &line : split(input, '\n')) {
        auto words = split(line, ' ');
        sort(words.begin(), words.end());
        if (unique(words.begin(), words.end()) == words.end()) {
            total++;
        }
    }

    return to_string(total);
}

string day4::second(const string &input) {
    int total = 0;
    for (const string &line : split(input, '\n')) {
        auto words = split(line, ' ');
        for (string &word : words) {
            sort(word.begin(), word.end());
        }

        sort(words.begin(), words.end());
        if (unique(words.begin(), words.end()) == words.end()) {
            total++;
        }
    }

    return to_string(total);
}
