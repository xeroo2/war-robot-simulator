#include "RoboCop.h"

RoboCop::RoboCop(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), MovingRobot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), canStepOnRobot(false) {}

void RoboCop::move() {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    int newX = x + dx;
    int newY = y + dy;
    if (b->correctPostion(newX, newY) && (!isPositionOccupied(newX, newY) || canStepOnRobot)) {
        setPosition(newX, newY);
    }
}

void RoboCop::fire() {
    for (int i = 0; i < 3; ++i) {
        int dx = rand() % 21 - 10;
        int dy = rand() % 21 - 10;
        if (abs(dx) + abs(dy) <= 10 && (dx != 0 || dy != 0)) {
            int targetX = x + dx;
            int targetY = y + dy;
            if (b->correctPostion(targetX, targetY) && isPositionOccupied(targetX, targetY)) {
                b->removeTheRobot(targetX, targetY);
                incrementKills();
                cout << "RoboCop at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
                if (getKills() >= 3) {
                    upgraded();
                }
            }
        }
    }
}

void RoboCop::look() {
    cout << "RoboCop at (" << x << ", " << y << ") is looking around." << endl;
}

void RoboCop::action() {
    look();
    move();
    fire();
}

void RoboCop::upgraded() {
    canStepOnRobot = true;
    cout << "RoboCop upgraded to TerminatorRoboCop!" << endl;
    emoji = 'T';
}
