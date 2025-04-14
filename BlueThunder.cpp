#include "BlueThunder.h"

BlueThunder::BlueThunder(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), upgrade(false), fireDirection(0) {}

void BlueThunder::fire() {
    int targetX = x, targetY = y;
    switch (fireDirection) {
        case 0: targetX = x - 1; targetY = y; break;
        case 1: targetX = x; targetY = y + 1; break;
        case 2: targetX = x + 1; targetY = y; break;
        case 3: targetX = x; targetY = y - 1; break;
    }

    if (b->correctPostion(targetX, targetY) && isPositionOccupied(targetX, targetY)) {
        b->removeTheRobot(targetX, targetY);
        incrementKills();
        cout << "BlueThunder at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
        if (getKills() >= 3) {
            upgraded();
        }
    }

    fireDirection = (fireDirection + 1) % 4;
}

void BlueThunder::action() {
    fire();
}

void BlueThunder::upgraded() {
    upgrade = true;
    cout << "BlueThunder upgraded to Madbot" << endl;
    emoji = 'M';
}
