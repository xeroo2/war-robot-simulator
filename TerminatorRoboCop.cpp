#include "TerminatorRoboCop.h"

TerminatorRoboCop::TerminatorRoboCop(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), MovingRobot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), canStepOnRobot(true) {}

void TerminatorRoboCop::move() {
    int newX = x, newY = y;
    bool foundEnemy = false;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (b->correctPostion(nx, ny) && isPositionOccupied(nx, ny)) {
                newX = nx;
                newY = ny;
                foundEnemy = true;
                break;
            }
        }
        if (foundEnemy) break;
    }

    if (!foundEnemy) {
        do {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            newX = x + dx;
            newY = y + dy;
        } while (!b->correctPostion(newX, newY));
    }

    if (isPositionOccupied(newX, newY)) {
        b->removeTheRobot(newX, newY);
        incrementKills();
        cout << "TerminatorRoboCop at (" << x << ", " << y << ") stepped on a robot at (" << newX << ", " << newY << ")" << endl;
    }
    setPosition(newX, newY);
}

void TerminatorRoboCop::fire() {
    int dx = rand() % 21 - 10;
    int dy = rand() % 21 - 10;
    if (abs(dx) + abs(dy) <= 10 && (dx != 0 || dy != 0)) {
        int targetX = x + dx;
        int targetY = y + dy;
        if (b->correctPostion(targetX, targetY) && isPositionOccupied(targetX, targetY)) {
            b->removeTheRobot(targetX, targetY);
            incrementKills();
            cout << "TerminatorRoboCop at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
        }
    }
}

void TerminatorRoboCop::look() {
    cout << "TerminatorRoboCop at (" << x << ", " << y << ") is looking around." << endl;
}

void TerminatorRoboCop::action() {
    look();
    move();
    fire();
}

void TerminatorRoboCop::upgraded() {
    cout << "TerminatorRoboCop upgraded to UltimateRobot!" << endl;
    emoji = 'U';
}
