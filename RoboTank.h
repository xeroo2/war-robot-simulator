#ifndef ROBOTANK_H
#define ROBOTANK_H

#include "ShootingRobot.h"
#include "SeeingRobot.h"

class RoboTank : public ShootingRobot, public SeeingRobot {
    bool upgrade;

public:
    RoboTank(Battlefield* bf, char emg, int startX, int startY);
    void fire() override;
    void look() override;
    void action() override;
    void upgraded() override;
};

#endif // ROBOTANK_H
