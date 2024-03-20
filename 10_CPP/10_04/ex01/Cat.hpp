

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);
		~Cat();

		Brain* getBrain() const;
		void makeSound() const;

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif