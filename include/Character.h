//
// Created by Darien on 9/21/2023.
//

#ifndef ZOMBIETOWN_CHARACTER_H
#define ZOMBIETOWN_CHARACTER_H

#include <string>

// ******************************************************************************|
// CLASS Character
// Represents the playable character.
//      Manages character info and status.
// ******************************************************************************|


class Character {
public:
    Character(const std::string& name, int hp, int energy);

// NAME *******************************************
    std::string getName() const;
    void setName(std::string newName);

// HP *********************************************
    int getHP() const;
    void setHP(int newHP);
    void changeHP(int changeVal);

// ENERGY *****************************************
    int getEnergy() const;
    void setEnergy(int newEnergy);
    void changeEnergy(int changeVal);

private:
    std::string name;
    int hp;
    int energy;

};

#endif //ZOMBIETOWN_CHARACTER_H
