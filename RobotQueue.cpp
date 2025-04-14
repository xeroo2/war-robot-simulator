#include "RobotQueue.h"

RobotQueue::RobotQueue() : front(nullptr), rear(nullptr), length(0) {}

void RobotQueue::enqueue(Robot* r) {
    Node* newNode = new Node(r);
    if (isEmpty()) {
        front = rear = newNode;
        front->next = nullptr;
        length++;
    } else {
        newNode->next = nullptr;
        rear->next = newNode;
        rear = newNode;
        length++;
    }
}

Robot* RobotQueue::dequeue() {
    if (isEmpty()) return nullptr;
    Node* temp = front;
    Robot* robot = front->robot;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }
    delete temp;
    length--;
    return robot;
}

bool RobotQueue::isEmpty() {
    return front == nullptr;
}

int RobotQueue::getLength() {
    return length;
}

Robot* RobotQueue::getFront() {
    if (!isEmpty()) {
        return front->robot;
    }
    return nullptr;
}
