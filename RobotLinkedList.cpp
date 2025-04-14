#include "RobotLinkedList.h"

RobotLinkedList::RobotLinkedList() : head(nullptr), length(0), last(nullptr) {}

void RobotLinkedList::addRobot(Robot* r) {
    Node* newNode = new Node(r);
    if (length == 0) {
        head = last = newNode;
        newNode->next = nullptr;
    } else {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

void RobotLinkedList::performActions(ofstream& logfile, Battlefield* battlefield, string actionSummary[], int& summaryCount) {
    Node* temp = head;
    while (temp) {
        ostringstream oss;
        oss << "Robot " << temp->robot->getEmoji() << " at (" << temp->robot->getX() << ", " << temp->robot->getY() << ")";
        temp->robot->action();
        oss << " performed actions.";
        actionSummary[summaryCount++] = oss.str();
        logActions(logfile, oss.str());
        temp = temp->next;
    }
}

void RobotLinkedList::logActions(ofstream& logfile, const string& action) {
    logfile << action << endl;
}

void RobotLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->robot;
        delete temp;
    }
    length = 0;
}

RobotLinkedList::~RobotLinkedList() {
    clear();
}

RobotLinkedList::Node* RobotLinkedList::getHead() const {
    return head;
}
