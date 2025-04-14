#include "Robot.h"

Robot::Robot(Battlefield* bf, char emg, int startX, int startY) : b(bf), emoji(emg), x(startX), y(startY), kills(0) {
    placeOnBattlefield();
}

void Robot::incrementKills() {
    kills++;
}

int Robot::getKills() const {
    return kills;
}

char Robot::getEmoji() const {
    return emoji;
}

int Robot::getX() const {
    return x;
}

int Robot::getY() const {
    return y;
}

void Robot::setPosition(int newX, int newY) {
    if (b->correctPostion(newX, newY)) {
        removeFromBattlefield();
        x = newX;
        y = newY;
        placeOnBattlefield();
    }
}

void Robot::removeFromBattlefield() {
    b->removeTheRobot(x, y);
}

void Robot::placeOnBattlefield() {
    b->placeOfRobot(x, y, emoji);
}

bool Robot::isPositionOccupied(int posX, int posY) {
    return b->isPositionOccupied(posX, posY);
}
