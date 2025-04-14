#include "RoboTank.h"

RoboTank::RoboTank(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), upgrade(false) {}

void RoboTank::fire() {
    int targetX = rand() % (b->getRows() - 2) + 1;
    int targetY = rand() % (b->getCol() - 2) + 1;

    if (isPositionOccupied(targetX, targetY)) {
        b->removeTheRobot(targetX, targetY);
        incrementKills();
        cout << "RoboTank at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
        if (getKills() >= 3) {
            upgraded();
        }
    }
}

void RoboTank::look() {
    cout << "RoboTank at (" << x << ", " << y << ") is scanning the battlefield." << endl;
}

void RoboTank::action() {
    look();
    fire();
}

void RoboTank::upgraded() {
    upgrade = true;
    cout << "RoboTank upgraded to UltimateRobot!" << endl;
    emoji = 'U';
}
