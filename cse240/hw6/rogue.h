#ifndef _ROGUE_H
#define _ROGUE_H

#include "player.h"

class Rogue : public Player {
public:
    // Constructor
    Rogue(string name, int level, playerType type)
        : Player(name, level, type) {}

    // Method to display player information
    void displayPlayer() {
        cout << "Name: " << getName() << endl;
        cout << "Level: " << getLevel() << endl;
        cout << "Type: Rogue" << endl;
        cout << "Attack: " << getAttack() << endl;
        cout << "Defense: " << getDefense() << endl;
        cout << "HP: " << getHP() << endl;
    }
};

#endif // _ROGUE_H