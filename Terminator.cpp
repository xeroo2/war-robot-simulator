#include "Terminator.h"

Terminator::Terminator(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), MovingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), canFire(false) {}

void Terminator::move() {
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
        cout << "Terminator at (" << x << ", " << y << ") stepped on a robot at (" << newX << ", " << newY << ")" << endl;
        if (getKills() >= 3) {
            upgraded();
        }
    }
    setPosition(newX, newY);
}

void Terminator::look() {
    cout << "Terminator at (" << x << ", " << y << ") is looking around." << endl;
}

void Terminator::action() {
    look();
    move();
}

void Terminator::upgraded() {
    canFire = true;
    cout << "Terminator upgraded to TerminatorRoboCop!" << endl;
    emoji = 'T';
}
