#include <iostream>
#include "day5.h"
#include "util.h"

string day5::first(const string &input) {
    auto parsedInput = split(input, '\n');
    vector<int> steps;
    for (const auto &i : parsedInput) {
        steps.push_back(stoi(i));
    }

    int total = 0, currentStep = 0;
    while (steps.size() > currentStep && currentStep >= 0) {
        currentStep += steps[currentStep]++;
        total++;
    }

    return to_string(total);
}

string day5::second(const string &input) {
    auto parsedInput = split(input, '\n');
    vector<int> steps;
    for (const auto &i : parsedInput) {
        steps.push_back(stoi(i));
    }

    int total = 0, currentStep = 0;
    while (steps.size() > currentStep && currentStep >= 0) {
        currentStep += (steps[currentStep] >= 3 ? steps[currentStep]-- : steps[currentStep]++);
        total++;
    }

    return to_string(total);
}
