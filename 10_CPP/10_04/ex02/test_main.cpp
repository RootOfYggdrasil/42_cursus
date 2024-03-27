#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Brain.h"

void testAnimal() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Calling makeSound for Dog: ";
    dog->makeSound();

    std::cout << "Calling makeSound for Cat: ";
    cat->makeSound();

    delete dog;
    delete cat;
}

void testBrain() {
    Dog* myDog = new Dog();
    myDog->setIdea(0, "gimmy");
    myDog->setIdea(1, "wow");
    std::cout << "Idea 0 for Dog: " << myDog->getIdea(0) << std::endl;

    Cat* myCat = new Cat();
    myCat->setIdea(0, "chase tail");
    myCat->setIdea(1, "eat fish");
    std::cout << "Idea 1 for Cat: " << myCat->getIdea(1) << std::endl;

    delete myDog;
    delete myCat;
}

int main() {
    testAnimal();
    testBrain();

    return 0;
}