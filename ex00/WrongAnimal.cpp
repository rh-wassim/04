#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    type = other.type;
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "WrongAnimal copy assignment operator" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
