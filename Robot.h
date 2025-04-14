#ifndef ROBOT_H
#define ROBOT_H

#include "Battlefield.h"

using namespace std;

class Robot {
protected:
    Battlefield *b;
    int x, y;
    int kills;
    char emoji;

public:
    Robot(Battlefield* bf, char emg, int startX, int startY);
    virtual void action() = 0;
    virtual void upgraded() = 0;
    virtual ~Robot() {}

    void incrementKills();
    int getKills() const;
    char getEmoji() const;
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);
    void removeFromBattlefield();
    void placeOnBattlefield();
    bool isPositionOccupied(int posX, int posY);
};

#endif // ROBOT_H
