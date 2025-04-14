#ifndef TERMINATORROBOCOP_H
#define TERMINATORROBOCOP_H

#include "MovingRobot.h"
#include "ShootingRobot.h"
#include "SeeingRobot.h"

class TerminatorRoboCop : public MovingRobot, public ShootingRobot, public SeeingRobot {
    bool canStepOnRobot;

public:
    TerminatorRoboCop(Battlefield* bf, char emg, int startX, int startY);
    void move() override;
    void fire() override;
    void look() override;
    void action() override;
    void upgraded() override;
};

#endif // TERMINATORROBOCOP_H
