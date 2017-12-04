#include <map>
#include <iostream>
#include "day3.h"

string day3::first(const string &input) {
    int parsedInput = stoi(input);
    int numbersPerLine;
    int bottomRight;
    for (numbersPerLine = 1; (bottomRight = numbersPerLine * numbersPerLine) < parsedInput; numbersPerLine += 2);
    int bottomLeft = bottomRight - (numbersPerLine - 1);
    int topLeft = bottomLeft - (numbersPerLine - 1);
    int topRight = topLeft - (numbersPerLine - 1);

    int xpos = 0;
    int ypos = 0;
    int maxPos = (numbersPerLine - 1) / 2;
    if (bottomLeft < parsedInput) {
        // We are on the bottom line
        xpos = abs(maxPos - bottomRight) - parsedInput;
        ypos = maxPos;
    } else if (topLeft < parsedInput) {
        // We are on the left column
        xpos = maxPos;
        ypos = abs(maxPos - bottomLeft) - parsedInput;
    } else if (topRight < parsedInput) {
        // We are on the top line
        xpos = abs(maxPos - topLeft) - parsedInput;
        ypos = maxPos;
    } else {
        // Right column then, duh
        xpos = maxPos;
        ypos = abs(maxPos - topRight) - numbersPerLine - parsedInput;
    }

    return to_string(abs(xpos) + abs(ypos));
}

int find(const map<pair<int, int>, int> &grid, int x, int y) noexcept {
    try {
        return grid.at(pair(x, y));
    } catch (out_of_range &e) {
        return 0;
    }
}

string day3::second(const string &input) {
    int parsedInput = stoi(input);
    map<pair<int, int>, int> grid;
    int x = 0, y = 0, maxX = 0, minY = 0;
    int i = 1;
    grid[pair(x, y)] = i;
    while (i <= parsedInput) {
        int maxY = minY * -1;
        if (x == maxX && y == minY && maxX == maxY) {
            maxX++;
            x++;
        } else if (x == maxX && y == maxY && maxX != maxY) {
            minY--;
            y++;
        } else if (x == maxX && y != maxY) {
            y++;
        } else {
            int minX = maxX * -1;
            if (y == maxY && x != minX) {
                x--;
            } else if (x == minX && y != minY) {
                y--;
            } else {
                x++;
            }
        }

        i = find(grid, x + 1, y + 1) + find(grid, x + 1, y) + find(grid, x + 1, y - 1)
            + find(grid, x, y + 1) + find(grid, x, y) + find(grid, x, y - 1)
            + find(grid, x - 1, y + 1) + find(grid, x - 1, y) + find(grid, x - 1, y - 1);
        grid[pair(x, y)] = i;
    }

    return to_string(i);
}
