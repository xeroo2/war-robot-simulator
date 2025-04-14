#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Battlefield.h"
#include "RoboCop.h"
#include "Terminator.h"
#include "TerminatorRoboCop.h"
#include "BlueThunder.h"
#include "Madbot.h"
#include "RoboTank.h"
#include "UltimateRobot.h"
#include "RobotLinkedList.h"
#include "RobotQueue.h"

using namespace std;

void initializeFromFile(const string& filename, Battlefield*& battlefield, RobotLinkedList& robots, int& steps, RobotQueue& robotQueue) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    int rows, cols;
    string line;

    // Read battlefield dimensions
    getline(file, line);
    istringstream iss(line);
    iss >> rows >> cols;
    battlefield = new Battlefield(rows, cols);

    // Read steps line
    getline(file, line);
    steps = stoi(line);

    // Read number of robots
    getline(file, line);
    int numRobots = stoi(line);

    for (int i = 0; i < numRobots; ++i) {
        string type, name, X, Y;
        file >> type >> name >> X >> Y;

        int x, y;
        if (X == "random" && Y == "random") {
            battlefield->fixPosition(x, y);
        } else {
            x = stoi(X);
            y = stoi(Y);
            if (!battlefield->correctPostion(x, y)) {
                battlefield->fixPosition(x, y);
            }
        }

        Robot* robot = nullptr;

        if (type == "RoboCop") {
            robot = new RoboCop(battlefield, 'R', x, y);
        } else if (type == "Terminator") {
            robot = new Terminator(battlefield, 't', x, y);
        } else if (type == "TerminatorRoboCop") {
            robot = new TerminatorRoboCop(battlefield, 'T', x, y);
        } else if (type == "BlueThunder") {
            robot = new BlueThunder(battlefield, 'B', x, y);
        } else if (type == "Madbot") {
            robot = new Madbot(battlefield, 'M', x, y);
        } else if (type == "RoboTank") {
            robot = new RoboTank(battlefield, 'K', x, y);
        } else if (type == "UltimateRobot") {
            robot = new UltimateRobot(battlefield, 'U', x, y);
        }

        if (robot) {
            robot->setPosition(x, y);
            robots.addRobot(robot);
            robotQueue.enqueue(robot);
        }
    }

    file.close();
}


void logState(ofstream& logfile, Battlefield* battlefield) {
    for (int i = 0; i < battlefield->getRows(); ++i) {
        for (int j = 0; j < battlefield->getCol(); ++j) {
            logfile << (*battlefield)(i, j) << " ";
        }
        logfile << endl;
    }
    logfile << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    Battlefield* battlefield = nullptr;
    RobotLinkedList robots;
    RobotQueue robotQueue;
    int steps = 0;

    // Initialize from file
    initializeFromFile("initial_conditions.txt", battlefield, robots, steps, robotQueue);

    if (battlefield == nullptr) {
        cerr << "Failed to initialize battlefield. Exiting." << endl;
        return 1;
    }

    // Display initial battlefield
    cout << "Initial battlefield state:" << endl;
    battlefield->display();

    // Open logfile
    ofstream logfile("logfile.txt");

    // Simulate turns
    for (int step = 0; step < steps; ++step) {
        cout << "Turn " << step + 1 << ":" << endl;

        // Perform actions for each robot and print actions to the terminal
        const int MAX_ACTIONS = 100;
        string actionSummary[MAX_ACTIONS];
        int summaryCount = 0;
        robots.performActions(logfile, battlefield, actionSummary, summaryCount);

        // Display the battlefield after all robot actions
        battlefield->display();

        // Print action summary
        for (int i = 0; i < summaryCount; ++i) {
            cout << actionSummary[i] << endl;
        }

        // Re-enter destroyed robots
        if (!robotQueue.isEmpty()) {
            Robot* reenteringRobot = robotQueue.dequeue();
            if (reenteringRobot) {
                int x, y;
                battlefield->fixPosition(x, y);

                reenteringRobot->setPosition(x, y);
                robots.addRobot(reenteringRobot);
                cout << "Robot re-entered at position (" << x << ", " << y << ")" << endl;
            }
        }

        // Display the battlefield after re-entry (if any)
        cout << "---------------------------------" << endl;
    }

    // Close logfile
    logfile.close();

    // Clean up
    delete battlefield;

    return 0;
}
