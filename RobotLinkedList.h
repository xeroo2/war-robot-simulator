#ifndef ROBOTLINKEDLIST_H
#define ROBOTLINKEDLIST_H

#include "Robot.h"
#include <fstream>
#include <sstream>

using namespace std;

class RobotLinkedList {
    struct Node {
        Robot* robot;
        Node* next;
        Node(Robot* r) : robot(r), next(nullptr) {}
    };

    Node* head;
    Node* last;
    int length;

public:
    RobotLinkedList();
    void addRobot(Robot* r);
    void performActions(ofstream& logfile, Battlefield* battlefield, string actionSummary[], int& summaryCount);
    void logActions(ofstream& logfile, const string& action);
    void clear();
    ~RobotLinkedList();
    Node* getHead() const;
};

#endif // ROBOTLINKEDLIST_H
