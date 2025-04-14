![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Project](https://img.shields.io/badge/Project-War_Robot_Simulator-red)

🚀 War Robot Simulator

War Robot Simulator is a turn-based robot warfare simulation built in C++.
Robots battle each other on a 2D battlefield by moving, looking around, and firing based on their abilities and strategies.

The simulation continues until either a maximum number of turns is reached or only one robot remains standing.

📋 Overview
Battlefield: 2D grid battlefield where robots move and engage in combat.

Turn-Based: Robots take turns in sequence to look, move, and fire.

Private Positions: Each robot's position is hidden from others unless revealed by "look" actions.

Robot Evolution: Robots can upgrade to stronger forms based on their combat performance.

Custom Data Structures: Linked lists and queues are implemented manually without standard libraries.

⚙️ Features
Battlefield Display: Real-time rendering of the battlefield after each turn.

Multiple Robot Types:

RoboCop: Looks, moves, and fires at random nearby targets.

Terminator: Moves and kills by stepping on robots.

BlueThunder: Fires in a fixed clockwise pattern.

MadBot: Randomly fires at neighboring cells.

RoboTank: Randomly fires anywhere on the battlefield.

TerminatorRoboCop: Combination of movement and firing capabilities.

UltimateRobot: The most powerful robot, moving and firing multiple shots each turn.

Robot Upgrades: Robots upgrade after achieving a set number of kills.

Three Lives: Destroyed robots can re-enter the battlefield up to three times.

Action Logging: All actions and battlefield states are logged to a file.

Error Handling: Safe input handling and game flow control.

No STL Containers: Custom linked lists and queues are used for managing turns and respawns.


🎮 Robot Types
Robot	Abilities
RoboCop	Looks, moves, fires randomly (up to 10 cells distance).
Terminator	Moves toward and steps on nearby enemy robots.
BlueThunder	Fires in a fixed clockwise neighboring pattern.
MadBot	Fires randomly at neighboring cells.
RoboTank	Fires randomly at any battlefield cell.
TerminatorRoboCop	Combines Terminator's stepping and RoboCop's firing abilities.
UltimateRobot	Moves and fires randomly at 3 locations per turn.

