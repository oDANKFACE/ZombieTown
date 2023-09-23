//
// Created by Darien on 9/21/2023.
//

#include "../include/Character.h"
#include <iostream>

Character::Character(const std::string& name, int hp, int energy) : name(name), hp(hp), energy(energy) {}


std::string Character::getName() const {
    return name;
}
void Character::setName(std::string newName) {
    name = newName;
}
int Character::getHP() const { return hp; }
void Character::setHP(int newHP) { hp = newHP; }
void Character::changeHP(int changeVal) { hp += changeVal; }
int Character::getEnergy() const { return energy; }
void Character::setEnergy(int newEnergy) { energy = newEnergy; }
void Character::changeEnergy(int changeVal) { energy += changeVal; }