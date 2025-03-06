#include "Ice.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/


Ice::Ice() : AMateria("Ice") {
	std::cout << "Ice: default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice: default destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	_type = other._type;
	std::cout << "Ice: copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Ice: copy assignment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

Ice *Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "• Ice : * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}