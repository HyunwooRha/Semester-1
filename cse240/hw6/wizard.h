#ifndef _WIZARD_H_
#define _WIZARD_H_

#include "player.h"

class Wizard : public Player {
public:
    // Constructor
    Wizard(string name, int level, playerType type)
        : Player(name, level, type) {}

    // Method to display player information
    void displayPlayer() {
        cout << "Name: " << getName() << endl;
        cout << "Level: " << getLevel() << endl;
        cout << "Type: Wizard" << endl;
        cout << "Attack: " << getAttack() << endl;
        cout << "Defense: " << getDefense() << endl;
        cout << "HP: " << getHP() << endl;
    }
};

#endif // _WIZARD_H_