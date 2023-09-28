#include "AMateria.hpp"

AMateria::AMateria() : type("default") {}
AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::AMateria(AMateria const & other) : type(other.type) {}
AMateria& AMateria::operator=(AMateria const & other) { 
    if (this != &other) 
        type = other.type; 
    return *this; 
}
AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return type; }
void AMateria::use(ICharacter& target) {
    std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
