#ifndef INC_2017_DAY_H
#define INC_2017_DAY_H

#include <string>

using namespace std;

class day {
public:
    virtual string first(string input) = 0;
    virtual string second(string input) = 0;
};

#endif //INC_2017_DAY_H
