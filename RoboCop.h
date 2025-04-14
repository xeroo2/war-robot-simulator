#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "MovingRobot.h"
#include "ShootingRobot.h"
#include "SeeingRobot.h"

class RoboCop : public MovingRobot, public ShootingRobot, public SeeingRobot {
    bool canStepOnRobot;

public:
    RoboCop(Battlefield* bf, char emg, int startX, int startY);
    void move() override;
    void fire() override;
    void look() override;
    void action() override;
    void upgraded() override;
};

#endif // ROBOCOP_H
