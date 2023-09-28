#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    
    // Learning Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Attempt to create Materia that hasn't been learned yet
    AMateria* tmp = src->createMateria("fire");
    if (tmp == NULL) {
        std::cout << "Cannot create Materia: Fire as it hasn't been learned yet" << std::endl;
    }

    // Character creation
    ICharacter* me = new Character("wassim");
    ICharacter* bob = new Character("bob");
    
    // Equipping and Using Materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob); // Should use Ice Materia
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(1, *bob); // Should use Cure Materia
    
    // Unequip and Use
    me->unequip(0);
    me->use(0, *bob); // Shouldn't do anything as Materia at index 0 is unequipped

    // Equipping more Materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *bob); // Should use Ice Materia

    // Trying to equip NULL shouldn't do anything
    me->equip(NULL);

    // Trying to equip to full inventory shouldn't do anything
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Using the equipped Materias
    me->use(2, *bob); // Should use Ice Materia
    me->use(3, *bob); // Should use Cure Materia

    // Clean Up
    delete bob;
    delete me;
    delete src;
    
    return 0;

}
