#ifndef ROBOTQUEUE_H
#define ROBOTQUEUE_H

#include "Robot.h"

class RobotQueue {
    struct Node {
        Robot* robot;
        Node* next;
        Node(Robot* r) : robot(r), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int length;

public:
    RobotQueue();
    void enqueue(Robot* r);
    Robot* dequeue();
    bool isEmpty();
    int getLength();
    Robot* getFront();
};

#endif // ROBOTQUEUE_H
