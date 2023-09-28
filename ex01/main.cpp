#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <sstream> 

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;

    const int animalCount = 4;
    Animal* animals[animalCount];
    for (int i = 0; i < animalCount / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = animalCount / 2; i < animalCount; ++i)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < animalCount; ++i)
    {
        animals[i]->makeSound();

        // Test deep copy and ideas
        if (Dog* dog = dynamic_cast<Dog*>(animals[i])) {
            Dog* dogCopy = new Dog(*dog);  // Deep copy of the Dog object
            Brain* dogBrain = dogCopy->getBrain();
            
            for (int j = 0; j < 5; ++j) // Declare 'j' here
            {
                // Use stringstream to convert int to string
                std::stringstream ss;
                ss << "Idea #" << (j + 1);
                std::string ideaStr = ss.str();
                dogBrain->setIdea(j, ideaStr);
            }
            std::cout << "Dog's ideas: ";
            for (int j = 0; j < 5; ++j)
            {
                std::cout << dogBrain->getIdea(j) << " ";
            }
            std::cout << std::endl;
            delete dogCopy;
        }
        else if (Cat* cat = dynamic_cast<Cat*>(animals[i])) {
            Cat* catCopy = new Cat(*cat);  // Deep copy of the Cat object
            Brain* catBrain = catCopy->getBrain();

            for (int j = 0; j < 5; ++j) // Declare 'j' here
            {
                // Use stringstream to convert int to string
                std::stringstream ss;
                ss << "Idea #" << (j + 1);
                std::string ideaStr = ss.str();
                catBrain->setIdea(j, ideaStr);
            }
            std::cout << "Cat's ideas: ";
            for (int j = 0; j < 5; ++j)
            {
                std::cout << catBrain->getIdea(j) << " ";
            }
            std::cout << std::endl;
            delete catCopy;
        }
    }

    for (int i = 0; i < animalCount; ++i)
    {
        delete animals[i];
    }

    return 0;
}
