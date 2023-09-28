#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "Animal copy assignment operator" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
