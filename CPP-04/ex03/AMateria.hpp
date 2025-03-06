#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

class AMateria
{
protected:

	std::string _type;

public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& type);
	AMateria &operator=(const AMateria &other);
	AMateria(std::string const& type);

	std::string const& getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};