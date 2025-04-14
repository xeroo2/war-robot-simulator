#include "UltimateRobot.h"

UltimateRobot::UltimateRobot(Battlefield* bf, char emg, int startX, int startY) 
    : Robot(bf, emg, startX, startY), MovingRobot(bf, emg, startX, startY), ShootingRobot(bf, emg, startX, startY), SeeingRobot(bf, emg, startX, startY), SteppingRobot(bf, emg, startX, startY) {}

void UltimateRobot::move() {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    int newX = x + dx;
    int newY = y + dy;

    if (b->correctPostion(newX, newY)) {
        if (isPositionOccupied(newX, newY)) {
            b->removeTheRobot(newX, newY);
        }
        setPosition(newX, newY);
    }
}

void UltimateRobot::fire() {
    for (int i = 0; i < 3; ++i) {
        int targetX = rand() % (b->getRows() - 2) + 1;
        int targetY = rand() % (b->getCol() - 2) + 1;

        if (isPositionOccupied(targetX, targetY)) {
            b->removeTheRobot(targetX, targetY);
            cout << "UltimateRobot at (" << x << ", " << y << ") killed a robot at (" << targetX << ", " << targetY << ")" << endl;
        }
    }
}

void UltimateRobot::look() {
    cout << "UltimateRobot at (" << x << ", " << y << ") is looking around." << endl;
}

void UltimateRobot::step() {
    cout << "UltimateRobot is stepping on robots in its path." << endl;
}

void UltimateRobot::action() {
    look();
    move();
    step();
    fire();
}

void UltimateRobot::upgraded() {
    // UltimateRobot does not upgrade to anything else
}
