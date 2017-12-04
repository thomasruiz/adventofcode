#ifndef AOC_UTIL_H
#define AOC_UTIL_H

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

template<typename Out>
static inline void split(const string &input, char delimiter, Out result) {
    stringstream ss(input);
    string item;
    while (getline(ss, item, delimiter)) {
        *(result++) = item;
    }
}

static inline vector<string> split(const string &input, char delimiter) {
    vector<string> elements;
    split(input, delimiter, back_inserter(elements));
    return elements;
}

using namespace std;

static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
}

static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
}

static inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}

#endif //AOC_UTIL_H
