#ifndef SEEINGROBOT_H
#define SEEINGROBOT_H

#include "Robot.h"

class SeeingRobot : virtual public Robot {
public:
    SeeingRobot(Battlefield* bf, char emg, int startX, int startY);
    virtual void look() = 0; // Pure virtual function
};

#endif // SEEINGROBOT_H
