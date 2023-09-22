//
// Created by Darien on 9/21/2023.
//

#include "../include/Character.h"

Character::Character(const std::string& name, int hp, int energy) : name(name), hp(hp), energy(energy) {}


int Character::getHP() const { return hp; }
void Character::setHP(int newHP) { hp = newHP; }
int Character::getEnergy() const { return energy; }
void Character::setEnergy(int newEnergy) { energy = newEnergy; }