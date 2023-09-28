#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for(int i = 0; i < 4; i++) inventory[i] = NULL;
}

Character::Character(Character const & other) : name(other.name) {
    for(int i = 0; i < 4; i++) 
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
}

Character& Character::operator=(Character const & other) {
    if (this != &other) {
        for(int i = 0; i < 4; i++) 
            delete inventory[i];
        name = other.name;
        for(int i = 0; i < 4; i++) 
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
    }
    return *this;
}

Character::~Character() {
    for(int i = 0; i < 4; i++) delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for(int i = 0; i < 4; i++) 
        if(!inventory[i]) {
            inventory[i] = m;
            break;
        }
}

void Character::unequip(int idx) {
    if(idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if(idx < 0 || idx >= 4 || !inventory[idx]) return;
    inventory[idx]->use(target);
}
