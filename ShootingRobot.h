#ifndef SHOOTINGROBOT_H
#define SHOOTINGROBOT_H

#include "Robot.h"

class ShootingRobot : virtual public Robot {
public:
    ShootingRobot(Battlefield* bf, char emg, int startX, int startY);
    virtual void fire() = 0; // Pure virtual function
};

#endif // SHOOTINGROBOT_H
