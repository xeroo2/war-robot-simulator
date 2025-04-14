#ifndef BLUETHUNDER_H
#define BLUETHUNDER_H

#include "ShootingRobot.h"

class BlueThunder : public ShootingRobot {
    bool upgrade;
    int fireDirection;

public:
    BlueThunder(Battlefield* bf, char emg, int startX, int startY);
    void fire() override;
    void action() override;
    void upgraded() override;
};

#endif // BLUETHUNDER_H
