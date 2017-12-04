#include "day1.h"

string day1::first(string input) {
    int total = 0;
    string::iterator inputIterator;

    for (inputIterator = input.begin(); inputIterator != input.end(); inputIterator++) {
        string::iterator nextChar = inputIterator + 1;
        if (nextChar == input.end()) {
            nextChar = input.begin();
        }

        if (*inputIterator == *nextChar) {
            total += *inputIterator - '0';
        }
    }

    return to_string(total);
}

string day1::second(string input) {
    int total = 0;
    string::iterator inputIterator;

    bool reverse = false;
    unsigned long padding = input.length() / 2;
    for (inputIterator = input.begin(); inputIterator != input.end(); inputIterator++) {
        string::iterator nextChar = inputIterator + padding;
        if (nextChar == input.end()) {
            reverse = true;
        }

        if (reverse) {
            nextChar = inputIterator - padding;
        }

        if (*inputIterator == *nextChar) {
            total += *inputIterator - '0';
        }
    }

    return to_string(total);
}
