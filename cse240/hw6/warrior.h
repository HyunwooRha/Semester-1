#ifndef _WARRIOR_H
#define _WARRIOR_H

#include "player.h"

class Warrior : public Player {
public:
    // Constructor
    Warrior(string name, int level, playerType type)
        : Player(name, level, type) {}

    // Method to display player information
    void displayPlayer() {
        cout << "Name: " << getName() << endl;
        cout << "Level: " << getLevel() << endl;
        cout << "Type: Warrior" << endl;
        cout << "Attack: " << getAttack() << endl;
        cout << "Defense: " << getDefense() << endl;
        cout << "HP: " << getHP() << endl;
    }
};

#endif // _WARRIOR_H