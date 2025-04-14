#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Battlefield {
    int row;
    int col;
    char **battleground;

public:
    Battlefield(int x, int y);
    ~Battlefield();
    void map();
    void display();
    void placeOfRobot(int x, int y, char emoji);
    void removeTheRobot(int x, int y);
    bool correctPostion(int x, int y);
    void fixPosition(int &x, int &y);
    char& operator()(int x, int y);
    bool isPositionOccupied(int x, int y);
    int getRows();
    int getCol();
};

#endif // BATTLEFIELD_H
