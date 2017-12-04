#include "day1.h"

string day1::first(const string &input) {
    int total = 0;
    for (string::const_iterator inputIterator = input.begin(); inputIterator != input.end(); inputIterator++) {
        string::const_iterator nextChar = inputIterator + 1;
        if (nextChar == input.end()) {
            nextChar = input.begin();
        }

        if (*inputIterator == *nextChar) {
            total += *inputIterator - '0';
        }
    }

    return to_string(total);
}

string day1::second(const string &input) {
    int total = 0;
    bool reverse = false;
    unsigned long padding = input.length() / 2;
    for (string::const_iterator inputIterator = input.begin(); inputIterator != input.end(); inputIterator++) {
        string::const_iterator nextChar = inputIterator + padding;
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
