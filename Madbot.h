#ifndef MADBOT_H
#define MADBOT_H

#include "ShootingRobot.h"
#include "SeeingRobot.h"

class Madbot : public ShootingRobot, public SeeingRobot {
    bool upgrade;

public:
    Madbot(Battlefield* bf, char emg, int startX, int startY);
    void fire() override;
    void look() override;
    void action() override;
    void upgraded() override;
};

#endif // MADBOT_H
