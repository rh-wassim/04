#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp" 
#include <iostream>

class Cat : public AAnimal
{
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    void makeSound() const;
    Brain* getBrain() const;
};

#endif  // CAT_HPP
