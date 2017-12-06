#ifndef AOC_DAY6_H
#define AOC_DAY6_H


#include <vector>
#include "day.h"

class day6 : public day {
public:
    string first(const string &input) override;
    string second(const string &input) override;

private:
    int findLoop(vector<int> &banks) const;
};


#endif //AOC_DAY6_H
