
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		~Dog();

		Brain* getBrain() const;
		void makeSound() const;

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif