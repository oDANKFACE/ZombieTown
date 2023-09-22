//
// Created by Darien on 9/21/2023.
//

#ifndef ZOMBIETOWN_CHARACTER_H
#define ZOMBIETOWN_CHARACTER_H

#include <string>

class Character {
public:
    Character(const std::string& name, int hp, int energy);
    int getHP() const;
    void setHP(int newHP);
    int getEnergy() const;
    void setEnergy(int newEnergy);
private:
    std::string name;
    int hp;
    int energy;

};

#endif //ZOMBIETOWN_CHARACTER_H
