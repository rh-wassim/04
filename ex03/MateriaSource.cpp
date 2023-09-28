#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for(int i = 0; i < 4; i++) sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    for(int i = 0; i < 4; i++) 
        sources[i] = other.sources[i] ? other.sources[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        for(int i = 0; i < 4; i++) 
            delete sources[i];
        for(int i = 0; i < 4; i++) 
            sources[i] = other.sources[i] ? other.sources[i]->clone() : NULL;
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for(int i = 0; i < 4; i++) delete sources[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for(int i = 0; i < 4; i++) 
        if(!sources[i]) {
            sources[i] = m->clone();
            break;
        }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for(int i = 0; i < 4; i++) 
        if(sources[i] && sources[i]->getType() == type) 
            return sources[i]->clone();
    return NULL;
}
