#ifndef MOVINGROBOT_H
#define MOVINGROBOT_H

#include "Robot.h"

class MovingRobot : virtual public Robot {
public:
    MovingRobot(Battlefield* bf, char emg, int startX, int startY);
    virtual void move() = 0; // Pure virtual function
};

#endif // MOVINGROBOT_H
