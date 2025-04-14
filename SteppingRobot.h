#ifndef STEPPINGROBOT_H
#define STEPPINGROBOT_H

#include "Robot.h"

class SteppingRobot : virtual public Robot {
public:
    SteppingRobot(Battlefield* bf, char emg, int startX, int startY);
    virtual void step() = 0; // Pure virtual function
};

#endif // STEPPINGROBOT_H
