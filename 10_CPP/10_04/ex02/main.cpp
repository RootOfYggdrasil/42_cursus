

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
	const Animal* arrayAnimal[50];
	const Animal* dog2 = NULL;
	dog2 = new Dog();
	for (int i = 0; i < 50; i++) {
		if (i % 2 == 0)
			arrayAnimal[i] = new Dog();
		else
			arrayAnimal[i] = new Cat();
	}
	for (int i = 0; i < 50; i++) {
		delete arrayAnimal[i];
	}
	std::cout << "DOGGO TIPO " << dog2->getType() << std::endl;

    std::cout << "Calling makeSound for Dog: ";
    dog->makeSound();

    std::cout << "Calling makeSound for Cat: ";
    cat->makeSound();

    Dog* myDog = new Dog();
    myDog->setIdea(0, "gimmy");
    myDog->setIdea(1, "wow");
    std::cout << "Idea 0 for Dog: " << myDog->getIdea(0) << std::endl;

    Cat* myCat = new Cat();
    myCat->setIdea(0, "chase tail");
    myCat->setIdea(1, "eat fish");
    std::cout << "Idea 0 for Cat: " << myCat->getIdea(0) << std::endl;
    std::cout << "Idea 1 for Cat: " << myCat->getIdea(1) << std::endl;
    std::cout << "Idea 1000 for Cat: " << myCat->getIdea(1000) << std::endl;



    delete dog;
    delete cat;
    delete myDog;
    delete myCat;
	delete dog2;

    return 0;
}