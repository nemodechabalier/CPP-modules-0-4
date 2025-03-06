#pragma once


#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};