// Q6b: Define displayPlayer() for Wizard class (2.5 points)
// Define the function displayPlayer() that you declared within the Wizard class in the header file
// See expected output in question file.

// (displayList() function in homework6template.cpp should call this function.)
// Include necessary header files
// Gradescope will expect output in this format: "Attribute: " << attribute << endl;
// This is a read check. If you read this, you should be fine.  You should follow the order in player.h
// capitalize each word in your output. 

#include "wizard.h"

// Define the function displayPlayer() that you declared within the Wizard class in the header file
void Wizard::displayPlayer() {
    cout << "Name: " << getName() << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Type: Wizard" << endl;
    cout << "Attack: " << getAttack() << endl;
    cout << "Defense: " << getDefense() << endl;
    cout << "HP: " << getHP() << endl;
}