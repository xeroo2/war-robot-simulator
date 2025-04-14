#ifndef TERMINATOR_H
#define TERMINATOR_H

#include "MovingRobot.h"
#include "SeeingRobot.h"

class Terminator : public MovingRobot, public SeeingRobot {
    bool canFire;

public:
    Terminator(Battlefield* bf, char emg, int startX, int startY);
    void move() override;
    void look() override;
    void action() override;
    void upgraded() override;
};

#endif // TERMINATOR_H
