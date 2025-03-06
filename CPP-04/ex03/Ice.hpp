#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	~Ice();
	Ice(const Ice& type);
	Ice& operator=(const Ice& other);

	Ice* clone() const;
	void use(ICharacter& target);
};