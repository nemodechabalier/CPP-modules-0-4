#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Character : public ICharacter
{
private:

	std::string _name;
	AMateria* _inventory[4];
	AMateria** _used;
	int _useCount;

public:
	Character();
	Character(const Character& other);
	Character(const std::string& name);
	Character& operator=(const Character& other);
	~Character();


	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void Add_used(AMateria *AMateria);
};