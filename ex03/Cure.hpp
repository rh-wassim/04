#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const & other);
    virtual ~Cure();
    Cure& operator=(Cure const & other);
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
