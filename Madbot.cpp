#include "Madbot.h"

Madbot::Madbot(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), upgrade(false) {}

void Madbot::fire() {
    int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int targetX, targetY;

    int randomDirection = rand() % 4;
    targetX = x + neighbors[randomDirection][0];
    targetY = y + neighbors[randomDirection][1];

    if (b->correctPostion(targetX, targetY) && isPositionOccupied(targetX, targetY)) {
        b->removeTheRobot(targetX, targetY);
        incrementKills();
        cout << "Madbot at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
        if (getKills() >= 3) {
            upgraded();
        }
    }
}

void Madbot::look() {
    cout << "Madbot at (" << x << ", " << y << ") is looking around." << endl;
}

void Madbot::action() {
    look();
    fire();
}

void Madbot::upgraded() {
    upgrade = true;
    cout << "Madbot upgraded to RoboTank!" << endl;
    emoji = 'K';
}
