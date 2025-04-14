#include "Battlefield.h"

Battlefield::Battlefield(int x, int y) {
    this->row = x + 2; // Adding 2 for the boundary rows
    this->col = y + 2; // Adding 2 for the boundary columns

    battleground = new char *[this->row];
    for (int i = 0; i < this->row; i++) {
        battleground[i] = new char[this->col];
    }
    map();
}

Battlefield::~Battlefield() {
    for (int i = 0; i < row; i++) {
        delete[] battleground[i];
    }
    delete[] battleground;
}

void Battlefield::map() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 || i == (row - 1)) {
                battleground[i][j] = '-';
            } else if (j == 0 || j == (col - 1)) {
                battleground[i][j] = '|';
            } else {
                battleground[i][j] = ' ';
            }
        }
    }
}

void Battlefield::display() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << battleground[i][j] << " ";
        }
        cout << endl;
    }
}

void Battlefield::placeOfRobot(int x, int y, char emoji) {
    if (correctPostion(x, y)) {
        battleground[x][y] = emoji;
    }
}

void Battlefield::removeTheRobot(int x, int y) {
    if (correctPostion(x, y)) {
        battleground[x][y] = ' ';
    }
}

bool Battlefield::correctPostion(int x, int y) {
    return (x > 0 && x < (row - 1) && y > 0 && y < (col - 1));
}

void Battlefield::fixPosition(int &x, int &y) {
    do {
        x = rand() % (row - 2) + 1;
        y = rand() % (col - 2) + 1;
    } while (isPositionOccupied(x, y));
}

char& Battlefield::operator()(int x, int y) {
    return battleground[x][y];
}

bool Battlefield::isPositionOccupied(int x, int y) {
    return battleground[x][y] != ' ';
}

int Battlefield::getRows() {
    return row;
}

int Battlefield::getCol() {
    return col;
}
