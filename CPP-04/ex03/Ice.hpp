#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Ice : public AMateria {

public:
	Ice();
	~Ice();
	Ice(const Ice& type);
	Ice& operator=(const Ice& other);

	Ice* clone() const;
	void use(ICharacter& target);
};