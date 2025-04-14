#ifndef ULTIMATEROBOT_H
#define ULTIMATEROBOT_H

#include "MovingRobot.h"
#include "ShootingRobot.h"
#include "SeeingRobot.h"
#include "SteppingRobot.h"

class UltimateRobot : public MovingRobot, public ShootingRobot, public SeeingRobot, public SteppingRobot {
public:
    UltimateRobot(Battlefield* bf, char emg, int startX, int startY);
    void move() override;
    void fire() override;
    void look() override;
    void step() override;
    void action() override;
    void upgraded() override;
};

#endif // ULTIMATEROBOT_H
