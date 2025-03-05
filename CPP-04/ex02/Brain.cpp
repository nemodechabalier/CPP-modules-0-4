#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		_ideas[i] = "idea";
	std::cout << "Brain : Default Constructor Called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain : Default Destructor Called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain : copie Constructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain : copy assignment operator called" << std::endl;
	return *this;
}