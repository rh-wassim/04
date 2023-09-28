
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    delete j;  // should not create a leak
    delete i;
    return 0;
}

//AAnimal *animal = new AAnimal();  //<= error, we can't initiate an abstract class