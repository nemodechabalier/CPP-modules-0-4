#include "Cure.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/


Cure::Cure() : AMateria("cure") {
	//std::cout << "Cure: default constructor called" << std::endl;
}

Cure::~Cure() {
	//std::cout << "Cure: default destructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	_type = other._type;
	//std::cout << "Cure: copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &other) {
	if (this != &other) {
		_type = other._type;
	}
	//std::cout << "Cure: copy assignment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

Cure *Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "• Cure : * heals " << target.getName() << "’s wounds *" << std::endl;
}